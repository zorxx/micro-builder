# \copyright 2015-2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 SDK package

include ../../../include/mb.inc

PACKAGE_NAME := esp8266_sdk

# Download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/espressif/ESP8266_RTOS_SDK.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

# Common Library
LIB_NAME_COMMON := lib$(PACKAGE_NAME)_common
$(LIB_NAME_COMMON)_obj := $(foreach file, \
                          $(wildcard *.c), \
                          $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

LIBRARY_TARGETS += $(LIB_NAME_COMMON)
LIBRARY_SUBMAKE := true

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
