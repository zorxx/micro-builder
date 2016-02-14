# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for Adafruit_ILI9340 2.2" SPI LCD display library package

dependencies = package/common/Adafruit_GFX

include ../../../include/mb.inc

PACKAGE_NAME := Adafruit_ILI9340

# Download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/zorxx/Adafruit_ILI9340.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

# Library
LIB_NAME := lib$(PACKAGE_NAME)
$(LIB_NAME)_obj := $(foreach file, \
		$(wildcard Adafruit_ILI9340_source/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

EXTERNAL_TARGETS += $(PACKAGE_NAME)
LIBRARY_TARGETS += $(LIB_NAME)
LIBRARY_SUBMAKE := true # Call "make" recursively when building the library to get the source files

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
