# \copyright 2015-2016 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Hello World application for ESP8266

required_prereqs = package/esp8266/esp8266_sdk

include ../../../include/mb.inc

APP_NAME = hello_world
$(APP_NAME)_obj := $(foreach file, \
	           $(wildcard *.c), \
	           $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

APP_TARGETS := $(APP_NAME)
INCDIR += .

include $(INCLUDE_DIR)/dir.inc
include $(INCLUDE_DIR)/app.inc

# vim: syntax=make tabstop=4 noexpandtab
