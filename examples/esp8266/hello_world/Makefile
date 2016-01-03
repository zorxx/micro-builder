# \copyright 2015 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Hello World application for ESP8266

include ../../../include/top.inc

APP_NAME = hello_world
$(APP_NAME)_obj := $(foreach file, \
	           $(wildcard *.c) \
	           $(wildcard *.cpp) \
	           $(wildcard *.S), \
	           $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

$(APP_NAME)_libs = gcc phy pp net80211 lwip wpa main crypto uart_lite

all: $(BUILD_TEMP_DIR)/$(APP_NAME).out
clean: app_clean

include ../../../include/bottom.inc
