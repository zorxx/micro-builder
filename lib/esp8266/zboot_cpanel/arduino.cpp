/*! \copyright 2018 Zorxx Software. All rights reserved.
 *  \file arduino.cpp
 *  \brief zboot control panel, Arduino ESP8266 implementation 
 */
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "user_interface.h" // system_restart
#include "zboot_cpanel.h"
#include "platform.h"

#if defined(DEBUG)
void DebugMessage(const char *format, ...)
{
   char message[150];
   va_list arglist;
   va_start(arglist, format);
   vsnprintf(message, sizeof(message), format, arglist);
   va_end(arglist);
   Serial.print(message);
}
#endif

// ------------------------------------------------------------------------------------------------
// Private Helper Functions 

static ESP8266WebServer server(ZBOOT_CPANEL_TCP_PORT);

static void arduino_HandleURI()
{
   HandleLinkedFile(server.uri().c_str(), NULL);
}

#define ARDUINO_MAX_ARGS 20

static void arduino_HandleCGI()
{
   const char *arg_names[ARDUINO_MAX_ARGS];
   const char *arg_values[ARDUINO_MAX_ARGS];
   uint32_t arg_count = server.args();
   uint32_t i;

   for(i = 0; i < arg_count && i < ARDUINO_MAX_ARGS; ++i)
   {
      arg_names[i] = strdup(server.argName(i).c_str());
      arg_values[i] = strdup(server.arg(i).c_str());
   }
   HandleCGI(server.uri().c_str(), arg_count, arg_names, arg_values, NULL);
   for(i = 0; i < arg_count && i < ARDUINO_MAX_ARGS; ++i)
   {
      free((void*)arg_names[i]);
      free((void*)arg_values[i]);
   }
}

static void arudino_HandleZbootImage()
{
   HandleZbootImage(server.uri().c_str(), NULL);
}

static void arduino_HandleUploadZbootImage()
{
   HTTPUpload& upload = server.upload();
   switch(upload.status)
   {
      case UPLOAD_FILE_START:
         HandleImageUploadStart(upload.filename.c_str());
         break;

      case UPLOAD_FILE_WRITE:
         HandleImageUploadWrite(upload.filename.c_str(), upload.buf, upload.currentSize);
         break;

      case UPLOAD_FILE_END:
         HandleImageUploadEnd(upload.filename.c_str());
         break;

      default:
         DebugMessage("Unknown upload event (%d)\r\n", upload.status);
         break;
   }
}

// ------------------------------------------------------------------------------------------------
// Exported Functions 

void zboot_cpanel_init(void)
{
    server.on("/ajax", arduino_HandleCGI);
    server.on("/new_zboot_image", HTTP_POST, arudino_HandleZbootImage, arduino_HandleUploadZbootImage);
    server.onNotFound(arduino_HandleURI); // All linked files are handled via the NotFound handler
    server.begin();
}

void zboot_cpanel_loop(void)
{
    server.handleClient();
}

void platform_http_send(uint16_t code, const char *content_type, const char *content, void *cookie)
{
   server.send(200, content_type, content);
}

void platform_system_restart(void)
{
   system_restart();
}

