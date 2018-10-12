# \copyright 2018 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief zboot control panel demo application for ESP8266

dependencies = package/esp8266/zboot lib/esp8266/zboot_cpanel

include ../../../include/mb.inc

APP_NAME = cpanel

ifneq ($(ESP8266_ARDUINO_DIR),)

$(info Using ESP8266 Arduino implementation)
$(APP_NAME)_obj := $(BUILD_TEMP_DIR)/arduino.o 

else

$(info Using ESP8266 SDK implementation)
include $(LIBRARIES_DIR)/common/mongoose/package.inc
$(APP_NAME)_obj := $(BUILD_TEMP_DIR)/esp8266_sdk.o 
LIBS += mongoose

endif

APP_TARGETS := $(APP_NAME)

include $(INCLUDE_DIR)/dir.inc
include $(INCLUDE_DIR)/app.inc

# vim: syntax=make tabstop=4 noexpandtab
