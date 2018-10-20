/*! \copyright 2018 Zorxx Software. All rights reserved.
 *  \file main.cpp
 *  \brief zboot control panel 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "zboot-api.h"
#include "zboot_cpanel.h"
#include "platform.h"

static bool g_autoLocation = true;

typedef enum {
    SPI_FLASH_RESULT_OK,
    SPI_FLASH_RESULT_ERR,
    SPI_FLASH_RESULT_TIMEOUT
} SpiFlashOpResult;

extern "C" SpiFlashOpResult spi_flash_read(uint32_t src_addr, uint32_t *des_addr, uint32_t size);

static const char HTTP_NOT_FOUND_CONTENT[] = "NOT_FOUND";
static const char HTTP_OK_CONTENT[] = "OK";

// ------------------------------------------------------------------------------------------------
// Linked Files

#define DECLARE_LINKED_FILE(fn) \
	extern const char _binary_##fn##_start; \
	extern const char _binary_##fn##_end;   \
	extern const unsigned long _binary_##fn##_size;
DECLARE_LINKED_FILE(zboot_cpanel_index_html);
DECLARE_LINKED_FILE(zboot_cpanel_helpers_js);

typedef struct linked_file_uri_s
{
    const char *start;
    const char *end;
    const char *uri;
    const char *content_type;
} linked_file_uri_t;
#define DECLARE_LINKED_FILE_URI(fn, uri, content_type) \
    { &_binary_##fn##_start, &_binary_##fn##_end, uri, content_type }

static linked_file_uri_t linked_file_uri_list[] = 
{
    DECLARE_LINKED_FILE_URI(zboot_cpanel_index_html, "/", "text/html"),
    DECLARE_LINKED_FILE_URI(zboot_cpanel_helpers_js, "/helpers.js", "text/javascript"),
};
#define LINKED_FILE_URI_LIST_COUNT (sizeof(linked_file_uri_list)/sizeof(linked_file_uri_list[0]))

static void SendLinkedFile(const char *start, const unsigned long length, const char *content_type,
   void *cookie)
{
    unsigned long idx;
    uint8_t boot_index;
    uint32_t boot_address;
    uint32_t copy_length;
    char *copy;

    copy_length = (length + 3) >> 2 << 2;

    copy = (char *) malloc(length+sizeof(uint32_t));
    DebugMessage("Linked file @ %p, length %u", start, copy_length);

    if(zboot_get_current_boot_index(&boot_index)
    && zboot_get_image_address(boot_index, &boot_address))
    {
       unsigned long offset = (unsigned long) start - 0x40200000 + boot_address;
       DebugMessage("Flash location: %08x\n", offset);
       if(spi_flash_read(offset, (uint32_t *) copy, copy_length) != SPI_FLASH_RESULT_OK)
       {
          DebugMessage("Failed to read file from flash");
       }
    }
    else
    {
       DebugMessage("Failed to determine boot application location in flash");

       /* Reads from flash must be 32-bit aligned, so copy (read from flash) into
        *  a RAM buffer, suitable for use by the webserver library */
       for(idx = 0; idx < length; idx += sizeof(unsigned long))
       {
           unsigned long temp = *((unsigned long *) (start + idx));
           *((unsigned long *) (copy + idx)) = temp; 
       }
    }
    copy[length-1] = '\0';

    DebugMessage(&copy[length - 120]);

    platform_http_send(200, content_type, copy, cookie);
    free(copy);
}

linked_file_uri_t *FindLinkedFileURI(const char *uri)
{
    for(uint32_t idx = 0; idx < LINKED_FILE_URI_LIST_COUNT; ++idx)
    {
        linked_file_uri_t *entry = &linked_file_uri_list[idx];
        if(strcmp(uri, entry->uri) == 0)
           return entry;
    }
    return NULL;
}

void HandleLinkedFile(const char *uri, void *cookie)
{
   linked_file_uri_t *entry = FindLinkedFileURI(uri); 

   if(NULL != entry)
   {
      uint32_t length = entry->end - entry->start;
      DebugMessage("Sending file: %s, length %u\r\n", entry->uri, length); 
      SendLinkedFile(entry->start, length, entry->content_type, cookie);
      return;
   }

   platform_http_send(404, "text/plain", HTTP_NOT_FOUND_CONTENT, cookie);
}

// ------------------------------------------------------------------------------------------------
// CGI

typedef void (*pfnOperationHandler)(void *param, const uint32_t arg_count, const char *arg_names[], const char *arg_values[], void *cookie);

typedef struct
{
   const char *name;
   pfnOperationHandler handler;
   void *parameter;
} operation_handler_t;

static void ImageInfoOperationHandler(void *param, const uint32_t arg_count, const char *arg_names[], const char *arg_values[], void *cookie)
{
   uint32_t version, date, address;
   char description[100];
   uint8_t index;

   index = (uint8_t)strtoul(arg_values[0], NULL, 10);
   if(zboot_get_image_info(index, &version, &date, &address,
      description, sizeof(description)))
   {
      char message[200];
      snprintf(message, sizeof(message), "index=%u;address=%u;version=%u;date=%u;description=%s",
         index, address, version, date, description);
      platform_http_send(200, "text/html", message, cookie);
   }
   else
   {
      platform_http_send(404, "text/plain", HTTP_NOT_FOUND_CONTENT, cookie);
   }
}

typedef enum
{
   GET_VALUE_IMAGE_COUNT,
   GET_VALUE_CURRENT_BOOT_MODE,
   GET_VALUE_BOOT_MODE,
   GET_VALUE_COLDBOOT_INDEX,
   GET_VALUE_CURRENT_BOOT_INDEX,
   GET_VALUE_FAILSAFE_BOOT_INDEX,
   GET_VALUE_TEMP_BOOT_INDEX,
   GET_VALUE_OPTION,
   SET_VALUE_OPTION_ENABLE,
   SET_VALUE_OPTION_DISABLE,
   SET_VALUE_MODE,
   SET_VALUE_COLDBOOT_INDEX,
   SET_VALUE_TEMP_BOOT_INDEX,
   SET_VALUE_FAILSAFE_BOOT_INDEX,
   SET_VALUE_INVALIDATE_BOOT_INDEX,
   SET_VALUE_AUTO_SELECT_IMAGE_LOCATION
} eValueHandlerType;

static void GetValueHandler(void *param, const uint32_t arg_count, const char *arg_names[], const char *arg_values[], void *cookie)
{
   eValueHandlerType type = (eValueHandlerType)(int)param;
   bool result = false;
   uint8_t value;

   switch(type)
   {
      case GET_VALUE_IMAGE_COUNT:
         result = zboot_get_image_count(&value);
         break;
      case GET_VALUE_COLDBOOT_INDEX:
         result = zboot_get_coldboot_index(&value);
         break;
      case GET_VALUE_CURRENT_BOOT_INDEX:
         result = zboot_get_current_boot_index(&value);
         break;
      case GET_VALUE_FAILSAFE_BOOT_INDEX:
         result = zboot_get_failsafe_index(&value);
         break;
      case GET_VALUE_TEMP_BOOT_INDEX:
         result = zboot_get_temp_index(&value);
         break;
      case GET_VALUE_CURRENT_BOOT_MODE:
         result = zboot_get_current_boot_mode(&value);
         break;
      case GET_VALUE_BOOT_MODE:
         result = zboot_get_boot_mode(&value);
         break;
      case GET_VALUE_OPTION:
         result = zboot_get_options(&value);
         break;
      default:
         break;
   }

   if(result)
   {
      char message[20];
      snprintf(message, sizeof(message), "%u", value);
      platform_http_send(200, "text/html", message, cookie);
   }
   else
      platform_http_send(404, "text/plain", HTTP_NOT_FOUND_CONTENT, cookie);
}

static void SetValueHandler(void *param, const uint32_t arg_count, const char *arg_names[],
   const char *arg_values[], void *cookie)
{
   eValueHandlerType type = (eValueHandlerType)(int)param;
   bool result = false;
   uint8_t value;

   if(arg_count <= 0)
     return;

   value = (uint8_t)strtoul(arg_values[0], NULL, 10);
   switch(type)
   {
      case SET_VALUE_OPTION_ENABLE:
         result = zboot_set_option(value, true);
         break;
      case SET_VALUE_OPTION_DISABLE:
         result = zboot_set_option(value, false);
         break;
      case SET_VALUE_MODE:
         result = zboot_set_boot_mode(value);
         break;
      case SET_VALUE_COLDBOOT_INDEX:
         result = zboot_set_coldboot_index(value);
         break;
      case SET_VALUE_TEMP_BOOT_INDEX:
         result = zboot_set_temp_index(value);
         break;
      case SET_VALUE_FAILSAFE_BOOT_INDEX:
         result = zboot_set_failsafe_index(value);
         break;
      case SET_VALUE_INVALIDATE_BOOT_INDEX:
         result = zboot_invalidate_index(value);
         break;
      case SET_VALUE_AUTO_SELECT_IMAGE_LOCATION:
         g_autoLocation = (value) ? "enabled" : "disabled";
         result = true;
         break;
      default:
         break;
   }

   if(result)
      platform_http_send(200, "text/plain", HTTP_OK_CONTENT, cookie);
   else
      platform_http_send(404, "text/plain", HTTP_NOT_FOUND_CONTENT, cookie);
}

static void RebootOperationHandler(void *param, const uint32_t arg_count, const char *arg_names[],
   const char *arg_values[], void *cookie)
{
   platform_http_send(200, "text/plain", HTTP_OK_CONTENT, cookie);  // Send this first
   platform_system_restart();
}

static operation_handler_t operation_handler_list[] =
{
    { "image_info", ImageInfoOperationHandler, NULL },
    { "image_count", GetValueHandler, (void*)GET_VALUE_IMAGE_COUNT },
    { "cold_boot_index", GetValueHandler, (void*)GET_VALUE_COLDBOOT_INDEX },
    { "current_boot_index", GetValueHandler, (void*)GET_VALUE_CURRENT_BOOT_INDEX },
    { "get_failsafe_index", GetValueHandler, (void*)GET_VALUE_FAILSAFE_BOOT_INDEX },
    { "get_temp_boot_index", GetValueHandler, (void*)GET_VALUE_TEMP_BOOT_INDEX },
    { "current_boot_mode", GetValueHandler, (void*)GET_VALUE_CURRENT_BOOT_MODE },
    { "get_mode", GetValueHandler, (void*)GET_VALUE_BOOT_MODE },
    { "get_option", GetValueHandler, (void*)GET_VALUE_OPTION },
    { "set_temp_boot_index", SetValueHandler, (void*)SET_VALUE_TEMP_BOOT_INDEX },
    { "select_boot_index", SetValueHandler, (void*)SET_VALUE_COLDBOOT_INDEX },
    { "set_failsafe_index", SetValueHandler, (void*)SET_VALUE_FAILSAFE_BOOT_INDEX },
    { "set_mode", SetValueHandler, (void*)SET_VALUE_MODE },
    { "enable_option", SetValueHandler, (void *)SET_VALUE_OPTION_ENABLE },
    { "disable_option", SetValueHandler, (void *)SET_VALUE_OPTION_DISABLE},
    { "auto_location", SetValueHandler, (void*)SET_VALUE_AUTO_SELECT_IMAGE_LOCATION },
    { "invalidate_boot_index", SetValueHandler, (void*)SET_VALUE_INVALIDATE_BOOT_INDEX },
    { "reboot", RebootOperationHandler, NULL },
};
#define OPERATION_HANDLER_LIST_COUNT (sizeof(operation_handler_list)/sizeof(operation_handler_list[0]))

void HandleCGI(const char *uri, const uint32_t arg_count, const char *arg_names[],
   const char *arg_values[], void *cookie)
{
   if(arg_count > 0)
   {
      uint32_t idx;
      for(idx = 0; idx < OPERATION_HANDLER_LIST_COUNT; ++idx)
      {
         operation_handler_t *op = &operation_handler_list[idx];
         if(strcmp(arg_names[0], op->name) == 0)
         {
            DebugMessage("Found CGI operation: %s\r\n", arg_names[0]);
            op->handler(op->parameter, arg_count, arg_names, arg_values, cookie);
            return; 
         }
      }
      DebugMessage("Unknown CGI operation: %s\r\n", arg_names[0]);
   }

   platform_http_send(404, "text/plain", HTTP_NOT_FOUND_CONTENT, cookie);
}

// ------------------------------------------------------------------------------------------------
// Write zboot Image

static void *zboot_write_context = NULL;

void HandleZbootImage(const char *uri, void *cookie)
{
    platform_http_send(200, "text/html", "<META http-equiv=\"refresh\" content=\"0;/\">", cookie);
}

void HandleImageUploadStart(const char *filename)
{
   uint8_t index;
   uint32_t address;

   if(!zboot_find_best_write_index(&index, true))
   {
      DebugMessage("Failed to find valid write index\r\n");
   }
   else if(!zboot_get_image_address(index, &address))
   {
      DebugMessage("Failed to find address for image index %u\r\n", index);
   }
   else
   {
      DebugMessage("Starting upload of new zboot image (%s), index %u, %08x\r\n",
         (filename) ? filename : "<unknown">, index, address);
      zboot_write_context = zboot_write_init(address);
   }
}

void HandleImageUploadWrite(const char *filename, const uint8_t *buffer, uint32_t length)
{
   if(NULL == zboot_write_context)
   {
      DebugMessage("No zboot write currently in progress\r\n");
      return;
   }

   if(!zboot_write_flash(zboot_write_context, buffer, length))
   {
      DebugMessage("Failed to write %u bytes\r\n", length);
   }
   else
   {
      DebugMessage("Successfully wrote %u bytes\r\n", length);
   }
}
     
void HandleImageUploadEnd(const char *filename)
{
   DebugMessage("Upload of new zboot image finished\r\n");
   if(NULL != zboot_write_context)
   {
      zboot_write_end(zboot_write_context);
      zboot_write_context = NULL;
   }
}

