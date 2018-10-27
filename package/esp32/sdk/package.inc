# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment for ESP32 SDK package

ESP32_SDK_DIR = $(PACKAGE_DIR)/esp32/sdk/esp32_sdk_source
ESP32_SDK_PROJDIR = examples/protocols/http_request

# ---------------------------------------------------------------------------
# Libraries

ESP32_SDK_LIBS = lwip bootloader_support aws_iot spiffs wpa_supplicant ssl mqtt util spi_flash log newlib smartconfig_ack tcpip_adapter cjson jsmn app_update freertos esp8266 nvs_flash espos heap
ESP32_CORE_LIBS = hal core net80211 gcc pp espnow phy wps ssc smartconfig wpa

LIBDIRS += $(foreach lib,$(ESP32_SDK_LIBS),$(ESP32_SDK_DIR)/$(ESP32_SDK_PROJDIR)/build/$(lib))
LIBDIRS += $(ESP32_SDK_DIR)/components/esp32/lib
LIBDIRS += $(ESP32_SDK_DIR)/components/newlib/newlib/lib
LIBDIRS += $(ESP32_SDK_DIR)/components/ssl/wolfssl/lib

LIBS += gcc stdc++ gcov
LIBS += m c c_nano wolfssl
LIBS += esp8266_sdk
LIBS += $(ESP32_SDK_LIBS) $(ESP32_CORE_LIBS) 

# ---------------------------------------------------------------------------
# Includes
 
ESP32_SDK_INCDIRS = \
  util/include bootloader_support/include cjson/include cjson/cJSON esp32/include \
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
INCDIR += $(foreach inc,$(ESP32_SDK_INCDIRS),$(ESP32_SDK_DIR)/components/$(inc))
INCDIR += $(ESP32_SDK_DIR)/..
INCDIR += $(ESP32_SDK_DIR)/$(ESP32_SDK_PROJDIR)/build/include

# ---------------------------------------------------------------------------
# Linker 
 
APP_LD_DIR = $(ESP32_SDK_DIR)/..
APP_LD_SCRIPT = esp32.rom.ld esp32.app.ld $(ESP32_SDK_DIR)/$(ESP32_SDK_PROJDIR)/build/esp32/esp32_common_out.ld esp32.extra.ld

CDEFS += MEMLEAK_DEBUG __ESP_FILE__=__FILE__
#LDFLAGS += -ecall_user_start_zboot

# vim: syntax=make tabstop=4 noexpandtab
