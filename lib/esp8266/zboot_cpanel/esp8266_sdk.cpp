/*! \copyright 2018 Zorxx Software. All rights reserved.
 *  \file esp8266_sdk.cpp
 *  \brief zboot control panel, esp8266_sdk platform  implementation 
 */
#include "esp_system.h"
#include "esp_log.h"
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
   ESP_LOGI("zboot_cpanel", message);
}
#endif

void platform_system_restart(void)
{
   esp_restart();
}
