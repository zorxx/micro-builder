/*! \copyright 2018 Zorxx Software. All rights reserved.
 *  \file platform.h 
 *  \brief zboot control panel, platform-specific interface
 */
#ifndef ZBOOT_CPANEL_PLATFORM_H
#define ZBOOT_CPANEL_PLATFORM_H

#include <stdint.h>

#define ZBOOT_CPANEL_TCP_PORT 84

void HandleLinkedFile(const char *uri, void *cookie);
void HandleZbootImage(const char *uri, void *cookie);
void HandleCGI(const char *uri, const uint32_t arg_count, const char *arg_names[],
   const char *arg_values[], void *cookie);

void HandleImageUploadStart(const char *filename);
void HandleImageUploadWrite(const char *filename, const uint8_t *buffer, uint32_t length);
void HandleImageUploadEnd(const char *filename);

void platform_system_restart(void);
void platform_http_send(uint16_t code, const char *content_type, const char *content, void *cookie);

#if defined(DEBUG)
void DebugMessage(const char *format, ...);
#else
#define DebugMessage(...)
#endif

#endif /* ZBOOT_CPANEL_PLATFORM_H */
