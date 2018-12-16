# \copyright 2018 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Hello World application for FreeRTOS targets 

include ../../../include/mb.inc

APP_NAME = freertos_hello_world
$(APP_NAME)_obj := $(foreach file, \
	           $(wildcard *.c), \
	           $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

APP_TARGETS := $(APP_NAME)

include $(INCLUDE_DIR)/app.inc

# vim: syntax=make tabstop=4 noexpandtab
