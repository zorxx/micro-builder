# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment for ESP32 SDK package

ESP32_SDK_DIR = $(PACKAGE_DIR)/esp32/sdk/esp32_sdk_source
ESP32_SDK_PROJDIR = examples/protocols/http_request

# ---------------------------------------------------------------------------
# Libraries

ESP32_SDK_LIBS = soc esp32 lwip bootloader_support esp_http_server wear_levelling heap \
                 spiffs wpa_supplicant mqtt spi_flash log newlib smartconfig_ack tcpip_adapter \
                 json app_update freertos nvs_flash openssl fatfs mdns json coap vfs ethernet \
                 libsodium ulp pthread mbedtls coexist net80211 rtc mesh driver esp_ringbuf \
                 wpa2 aws_iot xtensa-debug-module
ESP32_CORE_LIBS = core net80211 gcc pp espnow phy wps smartconfig wpa hal

LIBDIRS += $(foreach lib,$(ESP32_SDK_LIBS),$(ESP32_SDK_DIR)/$(ESP32_SDK_PROJDIR)/build/$(lib))
LIBDIRS += $(ESP32_SDK_DIR)/components/esp32 $(ESP32_SDK_DIR)/components/esp32/lib
LIBDIRS += $(ESP32_SDK_DIR)/components/newlib/lib

LIBS += gcc stdc++ gcov m c g
LIBS += $(ESP32_SDK_LIBS) $(ESP32_CORE_LIBS) 

# ---------------------------------------------------------------------------
# Includes
 
ESP32_SDK_INCDIRS = \
  bootloader_support/include esp32/include freertos/include freertos/include/freertos \
  freertos/port log/include soc/include soc/esp32/include driver/include esp_event/include \
  lwip/port/esp32/include lwip/include/apps lwip/lwip/src/include lwip/lwip/src/include/posix \
  lwip/lwip/src/include/lwip lwip/lwip/src/include/netif mqtt/esp-mqtt/include \
  newlib/include newlib/platform_include nvs_flash/include spi_flash/include spiffs/include \
  heap/include tcpip_adapter/include vfs/include
INCDIR += $(foreach inc,$(ESP32_SDK_INCDIRS),$(ESP32_SDK_DIR)/components/$(inc))
INCDIR += $(ESP32_SDK_DIR)/..
INCDIR += $(ESP32_SDK_DIR)/$(ESP32_SDK_PROJDIR)/build/include

# ---------------------------------------------------------------------------
# Linker 
 
APP_LD_DIR = $(ESP32_SDK_DIR)/components/esp32/ld $(ESP32_SDK_DIR)/$(ESP32_SDK_PROJDIR)/build/esp32
APP_LD_DIR += $(ESP32_SDK_DIR)/..
APP_LD_SCRIPT = esp32_out.ld esp32.common.ld esp32.rom.ld esp32.peripherals.ld
APP_LD_SCRIPT += esp32.rom_extra.ld

CDEFS += MEMLEAK_DEBUG __ESP_FILE__=__FILE__

# vim: syntax=make tabstop=4 noexpandtab
