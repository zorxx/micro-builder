# \copyright 2015-2016 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino Blink example application for ESP8266

include ../../../include/mb.inc

APP_NAME = blink
$(APP_NAME)_obj := $(foreach file, \
	           $(wildcard *.c) \
	           $(wildcard *.cpp) \
	           $(wildcard *.S), \
	           $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))
$(APP_NAME)_libs = stdc++ gcc phy pp net80211 lwip wpa main crypto esp8266_arduino_core
$(APP_NAME)_package_deps = esp8266/arduino

CPPFLAGS += -include Arduino.h

include ../../../include/app.inc

# vim: syntax=make tabstop=4 noexpandtab
