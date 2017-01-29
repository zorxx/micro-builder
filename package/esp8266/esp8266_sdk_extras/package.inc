# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment for ESP8266 SDK Extras package

ESP8266_SDK_EXTRAS_DIR := $(PACKAGE_DIR)/esp8266/esp8266_sdk_extras/esp8266_sdk_extras_source

INCDIR +=

LIBDIRS += $(ESP8266_SDK_EXTRAS_DIR)/libs
LIBS += hal 

# vim: syntax=make tabstop=4 noexpandtab
