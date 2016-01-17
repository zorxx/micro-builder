# \copyright 2015-2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for Arduino-Temperature-Control-Library package

include ../../../include/mb.inc

dependencies = package/common/OneWire

PACKAGE_NAME := TemperatureControl

# Download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/milesburton/Arduino-Temperature-Control-Library.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git
$(PACKAGE_NAME)_VERSION := 3.7.5

# Library
LIB_NAME := lib$(PACKAGE_NAME)
$(LIB_NAME)_obj := $(foreach file, \
		$(wildcard TemperatureControl_source/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

EXTERNAL_TARGETS += $(PACKAGE_NAME)
LIBRARY_TARGETS += $(LIB_NAME)
LIBRARY_SUBMAKE := true # Call "make" recursively when building the library to get the source files

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
