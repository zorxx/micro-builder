# \copyright 2017 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Second-stage bootloader application for ESP8266

APP_NAME = eboot
APP_LD_SCRIPT := $(APP_NAME).ld 

include ../../../include/mb.inc

$(APP_NAME)_obj := $(foreach file, \
	           $(wildcard *.c), \
	           $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

CFLAGS += -Iinclude -u call_user_start

APP_TARGETS := $(APP_NAME)
LIBS :=

define esp8266_post_app
endef

include $(INCLUDE_DIR)/app.inc

# vim: syntax=make tabstop=4 noexpandtab
