# \copyright 2015-2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment for ESP8266 SDK package

ESP8266_SDK_DIR := $(PACKAGE_DIR)/esp8266/esp8266_sdk/esp8266_sdk_source

INCDIR += \
 $(ESP8266_SDK_DIR)/include \
 $(ESP8266_SDK_DIR)/include/espressif \
 $(ESP8266_SDK_DIR)/include/freertos \
 $(ESP8266_SDK_DIR)/include/json \
 $(ESP8266_SDK_DIR)/include/lwip \
 $(ESP8266_SDK_DIR)/include/lwip/ipv4 \
 $(ESP8266_SDK_DIR)/include/lwip/ipv6 \
 $(ESP8266_SDK_DIR)/include/mbedtls \
 $(ESP8266_SDK_DIR)/include/nopoll \
 $(ESP8266_SDK_DIR)/include/openssl \
 $(ESP8266_SDK_DIR)/include/spiffs \
 $(ESP8266_SDK_DIR)/include/ssl \
 $(ESP8266_SDK_DIR)/extra_include \
 $(ESP8266_SDK_DIR)/driver_lib/include

LIBDIRS += $(ESP8266_SDK_DIR)/lib
LIBS += m gcc stdc++
LIBS += cirom crypto espconn espnow freertos json lwip main mesh \
        mirom net80211 nopoll phy pp pwm smartconfig spiffs ssl wpa wps
LIBS += esp8266_sdk_common

CDEFS += MEMLEAK_DEBUG

# vim: syntax=make tabstop=4 noexpandtab
