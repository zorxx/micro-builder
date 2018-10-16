/*! \copyright 2018 Zorxx Software. All rights reserved.
 *  \file microhttpd.cpp
 *  \brief zboot control panel, microhttpd web server implementation 
 */
#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include "microhttpd.h"
#include "zboot_cpanel.h"
#include "platform.h"

#define MAX_ARGS 20
#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))
static tMicroHttpdContext mhttpd_ctx = NULL;

/* ------------------------------------------------------------------------------------------------------------------
 * microhttpd callbacks
 */

void handle_post(tMicroHttpdClient client, const char *uri, const char *param_list[],
   const uint32_t param_count, const char *source_address, void *cookie, bool start, bool finish,
   const char *data, const uint32_t data_length, const uint32_t total_length)
{
   if(start)
   {  
      DebugMessage("%s: Begin upload %s", __func__, uri);
      HandleImageUploadStart(uri);
   }
   
   if(data_length > 0)
      HandleImageUploadWrite(uri, (const uint8_t *) data, data_length);
   
   if(finish)
   {  
      DebugMessage("%s: finish upload %s", __func__, uri);
      HandleImageUploadEnd(uri);
      microhttpd_send_response(client, 303, "none", 0, "Location: /\r\n", NULL);
   }
}

static void handle_cgi(tMicroHttpdClient client, const char *uri,
   const char *param_list[], const uint32_t param_count, const char *source_address, void *cookie)
{
   char *name_list[MAX_ARGS];
   char *value_list[MAX_ARGS];
   uint32_t idx;

   DebugMessage("CGI: uri %s, %u parameters", uri, param_count);

   for(idx = 0; idx < param_count && idx < MAX_ARGS; ++idx)
   {
      name_list[idx] = strdup(param_list[idx]);
      value_list[idx] = strchr(name_list[idx], '=');
      if(value_list[idx] != NULL)
      {
         *(value_list[idx]) = '\0';
         ++(value_list[idx]);
      }
      DebugMessage("CGI: param %s (%s, %s)", param_list[idx], name_list[idx], value_list[idx]);
   }

   HandleCGI(uri, idx, (const char **) name_list, (const char **) value_list, client);

   for(idx = 0; idx < param_count && idx < MAX_ARGS; ++idx)
      free((void *) name_list[idx]);
}

static void handle_not_found(tMicroHttpdClient client, const char *uri,
   const char *param_list[], const uint32_t param_count, const char *source_address, void *cookie)
{
   HandleLinkedFile(uri, client);
}

static tMicroHttpdGetHandlerEntry get_handler_list[] =
{
   { "/op.html", handle_cgi, NULL }
};

/* ----------------------------------------------------------------------------------------
 * Exported Functions
 */ 

void platform_http_send(uint16_t code, const char *content_type, const char *content, void *cookie)
{
   microhttpd_send_response((tMicroHttpdClient *) cookie, code, content_type,
      strlen(content), NULL, content);
}

void zboot_cpanel_init(void)
{
   tMicroHttpdParams params = {0};

   params.server_port = ZBOOT_CPANEL_TCP_PORT;
   params.process_timeout = 0;
   params.rx_buffer_size = 2048;
   params.get_handler_list = get_handler_list;
   params.get_handler_count = ARRAY_SIZE(get_handler_list);
   params.default_get_handler = handle_not_found;
   params.post_handler = handle_post;

   mhttpd_ctx = microhttpd_start(&params);
}

void zboot_cpanel_loop(void)
{
   microhttpd_process(mhttpd_ctx);
}

/* ----------------------------------------------------------------------------------------
 * ESP Functons 
 */ 

#include "esp_log.h"

#if defined(DEBUG)
void DebugMessage(const char *format, ...)
{
   char message[150];
   va_list arglist;
   va_start(arglist, format);
   vsnprintf(message, sizeof(message), format, arglist);
   va_end(arglist);
   ESP_LOGI("zboot_cpanel", message);
}
#endif

void platform_system_restart(void)
{
}
