# \copyright 2018 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief zboot control panel demo application for ESP8266

dependencies = lib/esp8266/zboot_cpanel

include ../../../include/mb.inc

APP_NAME = cpanel

ifneq ($(ESP8266_ARDUINO_DIR),)

$(info Using ESP8266 Arduino implementation)
$(APP_NAME)_obj := $(BUILD_TEMP_DIR)/arduino.o 

else

$(info Using ESP8266 SDK implementation)
$(call build_dependency,lib/common/microhttpd)
include $(LIBRARIES_DIR)/common/microhttpd/package.inc 
$(APP_NAME)_obj := $(BUILD_TEMP_DIR)/esp8266_sdk.o 

endif

APP_TARGETS := $(APP_NAME)

ifneq ($(AP_SSID),)
CDEFS += AP_SSID=$(AP_SSID)
else
CDEFS += AP_SSID=ssid
endif
ifneq ($(AP_PASSWORD),)
CDEFS += AP_PASSWORD=$(AP_PASSWORD)
else
CDEFS += AP_PASSWORD=password
endif

include $(INCLUDE_DIR)/dir.inc
include $(INCLUDE_DIR)/app.inc

# vim: syntax=make tabstop=4 noexpandtab
