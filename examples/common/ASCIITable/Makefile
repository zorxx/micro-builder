# \copyright 2015-2016 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino Blink example application for ESP8266

include ../../../include/mb.inc

dependencies = package/esp8266/arduino

APP_NAME = ASCIITable
$(APP_NAME)_obj := $(foreach file, \
	           $(wildcard *.c) \
	           $(wildcard *.cpp) \
	           $(wildcard *.S), \
	           $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))
$(APP_NAME)_libs = m arduino_core

CPPFLAGS += -include Arduino.h

APP_TARGETS := $(APP_NAME)

include $(INCLUDE_DIR)/app.inc

# vim: syntax=make tabstop=4 noexpandtab
