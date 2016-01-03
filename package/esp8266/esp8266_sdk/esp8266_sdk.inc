# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment for ESP8266 SDK package

ESP8266_SDK_VERSION := 1.5.0
ESP8266_SDK_DIR := $(PACKAGE_DIR)/esp8266/esp8266_sdk/source/esp_iot_sdk_v$(ESP8266_SDK_VERSION)

INCDIR += $(ESP8266_SDK_DIR)/include $(ESP8266_SDK_DIR)/include/json \
 $(PACKAGE_DIR)/esp8266/esp8266_sdk 
LIBDIRS += $(ESP8266_SDK_DIR)/lib
CDEFS +=

# vim: syntax=make tabstop=4 noexpandtab
