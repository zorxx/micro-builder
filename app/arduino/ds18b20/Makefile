# \copyright 2015-2016 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino Dallas DS18B20 example application

dependencies := lib/arduino/OneWire lib/arduino/TemperatureControl

include ../../../include/mb.inc

APP_NAME = ds18b20
$(APP_NAME)_obj := $(foreach file, \
	           $(wildcard *.c) \
	           $(wildcard *.cpp) \
	           $(wildcard *.S), \
	           $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))
$(APP_NAME)_libs := arduino_core OneWire TemperatureControl

APP_TARGETS := $(APP_NAME)

include $(INCLUDE_DIR)/app.inc

# vim: syntax=make tabstop=4 noexpandtab
