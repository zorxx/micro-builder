# \copyright 2015 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Lean and mean UART library for ESP8266

include ../../../include/top.inc

LIB_NAME := libuart_lite
$(LIB_NAME)_obj := $(foreach file, \
		$(wildcard *.c) \
		$(wildcard *.cpp) \
		$(wildcard *.S), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

all: $(LIB_BIN_DIR)/$(LIB_NAME).a
clean:
	@$(call library_clean,$(LIB_NAME))
	@$(call build_clean)

include ../../../include/bottom.inc

# vim: syntax=make tabstop=4 noexpandtab
