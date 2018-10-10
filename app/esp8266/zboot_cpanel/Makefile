# \copyright 2018 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief zboot control panel demo application for ESP8266

required_prereqs = package/esp8266/arduino
dependencies = package/esp8266/zboot lib/esp8266/zboot_cpanel

include ../../../include/mb.inc

APP_NAME = cpanel
$(APP_NAME)_obj := $(foreach file, \
	           $(wildcard *.cpp), \
	           $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

APP_TARGETS := $(APP_NAME)

include $(INCLUDE_DIR)/dir.inc
include $(INCLUDE_DIR)/app.inc

# vim: syntax=make tabstop=4 noexpandtab
