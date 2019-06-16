# \copyright 2015-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment for ESP8266 SDK package

ESP8266_SDK_DIR = $(PACKAGE_DIR)/esp8266/sdk/sdk_source
ESP8266_SDK_PROJDIR = examples/protocols/http_request

# ---------------------------------------------------------------------------
# Libraries

ESP8266_SDK_LIBS = lwip bootloader_support aws_iot spiffs wpa_supplicant ssl mqtt util spi_flash log newlib smartconfig_ack tcpip_adapter cjson jsmn app_update freertos esp8266 nvs_flash heap
ESP8266_CORE_LIBS = hal core net80211 gcc pp espnow phy wps ssc smartconfig wpa

LIBDIRS += $(foreach lib,$(ESP8266_SDK_LIBS),$(ESP8266_SDK_DIR)/$(ESP8266_SDK_PROJDIR)/build/$(lib))
LIBDIRS += $(ESP8266_SDK_DIR)/components/esp8266/lib
LIBDIRS += $(ESP8266_SDK_DIR)/components/newlib/newlib/lib
LIBDIRS += $(ESP8266_SDK_DIR)/components/ssl/wolfssl/lib

LIBS += gcc stdc++ gcov
LIBS += m c c_nano wolfssl
LIBS += esp8266_sdk
LIBS += $(ESP8266_SDK_LIBS) $(ESP8266_CORE_LIBS) 

# ---------------------------------------------------------------------------
# Includes
 
#ESP8266_SDK_INCDIRS = freertos/include freertos/port/esp8266/include/freertos
#ESP8266_SDK_INCDIRS += freertos/include/freertos/private esp8266/include
#ESP8266_SDK_INCDIRS += lwip/lwip/src/include lwip/port/esp8266/include tcpip_adapter/include
#ESP8266_SDK_INCDIRS += lwip/include/lwip/apps log/include nvs_flash/include

ESP8266_SDK_INCDIRS = \
  util/include bootloader_support/include cjson/include cjson/cJSON esp8266/include \
  esp8266/include espos/include freertos/include freertos/include/freertos \
  freertos/include/freertos/private freertos/port/esp8266/include \
  freertos/port/esp8266/include/freertos log/include lwip/include lwip/include/lwip/apps \
  lwip/lwip/src/include lwip/port/esp8266/include lwip/include/lwip/apps/multi-threads \
  mqtt/include mqtt/paho/MQTTClient-C/src mqtt/paho/MQTTClient-C/src/FreeRTOS \
  mqtt/paho/MQTTPacket/src newlib/include newlib/newlib/include newlib/newlib/port/include \
  nvs_flash/include spi_flash/include spiffs/include spiffs/include/spiffs ssl/include \
  ssl/mbedtls/mbedtls/include ssl/mbedtls/port/esp8266/include heap/include \
  ssl/mbedtls/port/openssl/include tcpip_adapter/include tcpip_adapter/include \
  heap/port/esp8266/include lwip/lwip/src/include/posix
INCDIR += $(foreach inc,$(ESP8266_SDK_INCDIRS),$(ESP8266_SDK_DIR)/components/$(inc))
INCDIR += $(ESP8266_SDK_DIR)/..
INCDIR += $(ESP8266_SDK_DIR)/$(ESP8266_SDK_PROJDIR)/build/include

# ---------------------------------------------------------------------------
# Linker 
 
APP_LD_DIR = $(ESP8266_SDK_DIR)/.. $(ESP8266_SDK_DIR)/$(ESP8266_SDK_PROJDIR)/build/esp8266 \
             $(ESP8266_SDK_DIR)/components/esp8266/ld
APP_LD_SCRIPT = esp8266.rom.ld esp8266.app.ld esp8266.peripherals.ld esp8266_common_out.ld esp8266.extra.ld

CDEFS += MEMLEAK_DEBUG __ESP_FILE__=__FILE__
LDFLAGS += -ecall_user_start_zboot

# vim: syntax=make tabstop=4 noexpandtab
