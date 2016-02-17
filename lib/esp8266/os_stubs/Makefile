# \copyright 2016 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Library to implement stubs for OS-reentrancy for ESP8266

include ../../../include/mb.inc

LIB_NAME := libos_stubs
$(LIB_NAME)_obj := $(foreach file, \
		$(wildcard *.c), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))
LIBRARY_TARGETS += $(LIB_NAME)

include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
