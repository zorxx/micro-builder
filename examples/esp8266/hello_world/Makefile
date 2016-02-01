# \copyright 2015-2016 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Hello World application for ESP8266

include ../../../include/mb.inc

dependencies = package/esp8266/esp8266_sdk lib/esp8266/uart_lite

APP_NAME = hello_world
$(APP_NAME)_obj := $(foreach file, \
	           $(wildcard *.c) \
	           $(wildcard *.cpp) \
	           $(wildcard *.S), \
	           $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

$(APP_NAME)_libs = gcc phy pp net80211 lwip wpa main crypto uart_lite

APP_TARGETS := $(APP_NAME)
INCDIR += .

include $(INCLUDE_DIR)/app.inc

# vim: syntax=make tabstop=4 noexpandtab
