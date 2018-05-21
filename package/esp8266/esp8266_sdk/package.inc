# \copyright 2015-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment for ESP8266 SDK package

ESP8266_SDK_DIR := $(PACKAGE_DIR)/esp8266/esp8266_sdk/esp8266_sdk_source

ESP8266_SDK_SRCDIRS := \
	cjson/library \
	esp8266/driver \
	esp8266/source \
	lwip/lwip/src/api lwip/lwip/src/apps/sntp lwip/lwip/src/netif \
	lwip/lwip/src/core lwip/lwip/src/core/ipv4 lwip/lwip/src/core/ipv6 \
        lwip/port/freertos lwip/port/netif lwip/apps/dhcpserver lwip/apps/sntp lwip/apps/multi-threads \
	freertos/library \
	tcpip_adapter \
	espconn/library \
	mqtt/source/library mqtt/source/platformi \
	nopoll/library \
	ssl/mbedtls/mbedtls/library ssl/mbedtls/port \
	ssl/openssl/source/library ssl/openssl/source/platform \
	spiffs\library

ESP8266_SDK_INCDIRS := \
	cjson/include \
	esp8266/include esp8266/include/driver \
	lwip/include lwip/include/lwip/ipv4 lwip/include/lwip/ipv6 lwip/include/lwip/posix \
        lwip/include/lwip/apps lwip/port/esp8266/include \
	lwip/include/lwip lwip/lwip/src/include/lwip lwip/include/lwip/port lwip/lwip/src/include \
	lwip/lwip/src/include/posix \
	freertos/include freertos/include/port freertos/include/port/freertos \
        freertos/port/esp8266/include/freertos freertos/port/esp8266/include \
        freertos/include/freertos/private \
	tcpip_adapter/include \
	espconn/include \
	mqtt/include/mqtt \
	nopoll/include nopoll/include/nopoll \
	ssl/openssl/include ssl/openssl/include/internal ssl/openssl/include/openssl \
	ssl/openssl/include/platform ssl/mbedtls/mbedtls/include ssl/mbedtls/port/include \
	ssl/mbedtls/port/esp8266/include/mbedtls \
	spiffs/include/spiffs

INCDIR += $(foreach inc,$(ESP8266_SDK_INCDIRS),$(ESP8266_SDK_DIR)/components/$(inc))
INCDIR += $(ESP8266_SDK_DIR)/..

APP_LD_DIR := $(ESP8266_SDK_DIR)/components/esp8266/ld

LIBDIRS += $(ESP8266_SDK_DIR)/components/esp8266/lib
LIBS += gcc stdc++ gcov
LIBS += airkiss cirom crypto espnow hal core minic mirom net80211 \
        phy pp pwm smartconfig ssc wpa wps

LIBS += esp8266_sdk_common

CDEFS += MEMLEAK_DEBUG

# vim: syntax=make tabstop=4 noexpandtab
