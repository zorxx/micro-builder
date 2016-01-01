# \copyright 2015 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Hello World application for ESP8266

include ../../../include/top.inc

APP_NAME = hello_world
hello_world_obj = $(addsuffix .o, $(basename $(wildcard *.c) $(wildcard *.cpp)))
hello_world_libs = gcc phy pp net80211 lwip wpa main crypto uart_lite

all: $(BUILD_TEMP_DIR)/$(APP_NAME).out
clean: app_clean

include ../../../include/bottom.inc
