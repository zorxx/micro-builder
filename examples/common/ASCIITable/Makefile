# \copyright 2015 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino Blink example application for ESP8266

include ../../../include/top.inc

APP_NAME = ASCIITable
$(APP_NAME)_obj = $(addsuffix .o, $(basename $(wildcard *.c) $(wildcard *.cpp)))
$(APP_NAME)_libs = m gcc phy pp net80211 lwip wpa main crypto esp8266_arduino

CPPFLAGS += -include Arduino.h

all: $(BUILD_TEMP_DIR)/$(APP_NAME).out
clean: app_clean

include ../../../include/bottom.inc
