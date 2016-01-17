# \copyright 2015-2016 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino Dallas DS18B20 example application

include ../../../include/mb.inc

APP_NAME = ds18b20
$(APP_NAME)_obj := $(foreach file, \
	           $(wildcard *.c) \
	           $(wildcard *.cpp) \
	           $(wildcard *.S), \
	           $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))
$(APP_NAME)_libs := m gcc phy pp net80211 lwip wpa main crypto esp8266_arduino_core OneWire TemperatureControl
dependencies := package/esp8266/arduino package/common/OneWire package/common/TemperatureControl

APP_TARGETS := $(APP_NAME)

include $(INCLUDE_DIR)/app.inc

# vim: syntax=make tabstop=4 noexpandtab
