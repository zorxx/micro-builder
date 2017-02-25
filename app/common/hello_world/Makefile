# \copyright 2016 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino Blink example application

include ../../../include/mb.inc

APP_NAME = hello_world
$(APP_NAME)_obj := $(foreach file, \
	           $(wildcard *.c) \
	           $(wildcard *.cpp) \
	           $(wildcard *.S), \
	           $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))
$(APP_NAME)_libs =

CPPFLAGS +=

APP_TARGETS := $(APP_NAME)

include $(INCLUDE_DIR)/app.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
