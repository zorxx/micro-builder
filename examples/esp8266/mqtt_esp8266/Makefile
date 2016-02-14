# \copyright 2016 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief MQTT example application for ESP8266

include ../../../include/mb.inc

required_prereqs = package/esp8266/arduino
dependencies = package/common/MQTT

APP_NAME = mqtt
$(APP_NAME)_PREACTION = \
	$(shell $(foreach src,$(wildcard $(MQTT_EXAMPLES_DIR)/mqtt_esp8266/*.ino),cp $(src) ./$(notdir $(basename $(src)).cpp;)))
$(APP_NAME)_obj := $(foreach file, \
	           $(wildcard *.cpp), \
	           $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

$(APP_NAME)_libs = m MQTT arduino_wifi arduino_Ethernet arduino_core

APP_TARGETS := $(APP_NAME)
INCDIR += .

include $(INCLUDE_DIR)/app.inc

# vim: syntax=make tabstop=4 noexpandtab
