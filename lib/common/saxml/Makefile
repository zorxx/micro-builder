# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for saxml Library

include ../../../include/mb.inc

PACKAGE_NAME := saxml

# Download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/zorxx/saxml.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

# Library
LIB_NAME := lib$(PACKAGE_NAME)
$(LIB_NAME)_obj := $(foreach file, \
		$(wildcard $(PACKAGE_NAME)_source/*.c), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

ifeq ($(TARGET_ARCH),avr)
CDEFS += SAXML_NO_MALLOC SAXML_MAX_STRING_LENGTH=256
endif

EXTERNAL_TARGETS += $(PACKAGE_NAME)
LIBRARY_TARGETS += $(LIB_NAME)
LIBRARY_SUBMAKE := true # Call "make" recursively when building the library to get the source files

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
