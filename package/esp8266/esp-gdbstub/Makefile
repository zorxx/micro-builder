# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 gdbstub package

include ../../../include/mb.inc

PACKAGE_NAME := esp-gdbstub
$(PACKAGE_NAME)_SOURCE := "https://github.com/espressif/esp-gdbstub.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

SRCDIR := $(PACKAGE_NAME)_source

LIB_NAME_GDBSTUB := lib$(PACKAGE_NAME)_gdbstub
$(LIB_NAME_GDBSTUB)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/*.c) \
		$(wildcard $(SRCDIR)/*.S), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

CFLAGS += -include stddef.h

EXTERNAL_TARGETS += $(PACKAGE_NAME)
LIBRARY_TARGETS += $(LIB_NAME_GDBSTUB)
LIBRARY_SUBMAKE := true

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
