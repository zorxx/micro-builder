# \copyright 2015-2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief ESP8266 Arduino package build environment

ESP8266_ARDUINO_DIR := $(PACKAGE_DIR)/esp8266/arduino/source

# Core includes
INCDIR += $(ESP8266_ARDUINO_DIR)/cores/esp8266 $(ESP8266_ARDUINO_DIR)/variants/$(TARGET_BOARD) \
 $(ESP8266_ARDUINO_DIR)/tools/sdk/include
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/EEPROM
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/ESP8266WiFi/src
INCDIR += $(ESP8266_ARDUINO_DIR)/libraries/ESP8266mDNS

LIBDIRS += $(ESP8266_ARDUINO_DIR)/tools/sdk/lib
CDEFS += ARDUINO_ARCH_ESP8266 ARDUINO=100
CFLAGS += -U__STRICT_ANSI__
CPPFLAGS += -U__STRICT_ANSI__ -fno-use-cxa-atexit
LDFLAGS += -u call_user_start -Wl,-wrap,system_restart_local -Wl,-wrap,register_chipv6_phy

# vim: syntax=make tabstop=4 noexpandtab