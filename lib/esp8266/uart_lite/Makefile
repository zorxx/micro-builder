# \copyright 2015-2016 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Lean and mean UART library for ESP8266

include ../../../include/mb.inc

LIB_NAME := libuart_lite
$(LIB_NAME)_obj := $(foreach file, \
		$(wildcard *.c) \
		$(wildcard *.cpp) \
		$(wildcard *.S), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))
$(LIB_NAME)_package_deps = esp8266/esp8266_sdk
LIBRARY_TARGETS += $(LIB_NAME)

include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
