# \copyright 2015-2019 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief ESP8266 Arduino package build environment

ESP8266_ARDUINO_DIR := $(PACKAGE_DIR)/esp8266/arduino/arduino_source

# Core includes
INCDIR += $(ESP8266_ARDUINO_DIR)/cores/esp8266 \
          $(ESP8266_ARDUINO_DIR)/variants/$(TARGET_BOARD) \
          $(ESP8266_ARDUINO_DIR)/tools/sdk/lwip2/include \
          $(ESP8266_ARDUINO_DIR)/tools/sdk/include
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/ArduinoOTA
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/DNSServer/src
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/EEPROM
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/ESP8266AVRISP/src
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/ESP8266HTTPClient/src
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/ESP8266httpUpdate/src
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/ESP8266HTTPUpdateServer/src
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/ESP8266mDNS/src
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/ESP8266SdFat/src
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/ESP8266SSDP
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/ESP8266WebServer/src
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/ESP8266WiFi/src
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/ESP8266WiFiMesh/src
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/Ethernet/src
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/Ethernet/src/utility
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/GDBStub/src
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/Hash/src
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/OneWire
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/SD/src
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/SDFS/src
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/SPI
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/TFT_Touch_Shield_V2
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/Ticker
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/Wire

LIBDIRS += $(ESP8266_ARDUINO_DIR)/..
LIBDIRS += $(ESP8266_ARDUINO_DIR)/tools/sdk/lib $(ESP8266_ARDUINO_DIR)/tools/sdk/lib/NONOSDK221
CDEFS += ARDUINO_ARCH_ESP8266 ARDUINO=10809 ESP8266 __ets__ ICACHE_FLASH LWIP_OPEN_SRC TCP_MSS=536 \
         LWIP_FEATURES=1 LWIP_IPV6=0 LWIP_SOCKET=1 LWIP_TIMEVAL_PRIVATE=0
CFLAGS += -U__STRICT_ANSI__
CPPFLAGS += -U__STRICT_ANSI__ -fno-use-cxa-atexit
LDFLAGS += -u call_user_start -u _printf_float -u _scanf_float -Wl,-wrap,system_restart_local -Wl,-wrap,spi_flash_read

LIBS += m c gcc hal phy pp net80211 lwip2-536-feat wpa crypto main wps bearssl axtls espnow smartconfig airkiss wpa2 stdc++
LIBS += arduino_ArduinoOTA arduino_Ethernet arduino_HTTPUpdateServer arduino_SSDP arduino_Wire
LIBS += arduino_AVRISP arduino_GDBStub arduino_mDNS arduino_TFT arduino_core arduino_Hash arduino_OneWire
LIBS += arduino_Ticker arduino_DNSServer arduino_HTTPClient arduino_SD arduino_wifi arduino_eeprom
LIBS += arduino_HTTPUpdate arduino_SPI arduino_WiFiMesh arduino_WebServer

# vim: syntax=make tabstop=4 noexpandtab
