# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino BMP180 Barometric Pressure/Temperature Sensor Library package

include ../../../include/mb.inc

PACKAGE_NAME := BMP180

# Download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/sparkfun/BMP180_Breakout.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

# Library
LIB_NAME := lib$(PACKAGE_NAME)
$(LIB_NAME)_obj := $(foreach file, \
		$(wildcard $(PACKAGE_NAME)_source/Libraries/Arduino/src/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

EXTERNAL_TARGETS += $(PACKAGE_NAME)
LIBRARY_TARGETS += $(LIB_NAME)
LIBRARY_SUBMAKE := true # Call "make" recursively when building the library to get the source files

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/lib.inc

# vim: syntax=make tabstop=4 noexpandtab
