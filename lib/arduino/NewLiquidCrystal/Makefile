# \copyright 2016-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for NewLiquidCrystal library package

include ../../../include/mb.inc

PACKAGE_NAME := NewLiquidCrystal

# Download information
$(PACKAGE_NAME)_SOURCE := "https://bitbucket.org/fmalpartida/new-liquidcrystal"
$(PACKAGE_NAME)_SOURCE_METHOD := hg 

# Library
LIB_NAME := lib$(PACKAGE_NAME)
$(LIB_NAME)_obj := $(foreach file, \
		$(filter-out $(PACKAGE_NAME)_source/SI2CIO.cpp,$(wildcard $(PACKAGE_NAME)_source/*.cpp)), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

EXTERNAL_TARGETS += $(PACKAGE_NAME)
LIBRARY_TARGETS += $(LIB_NAME)
LIBRARY_SUBMAKE := true # Call "make" recursively when building the library to get the source files

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/lib.inc

# vim: syntax=make tabstop=4 noexpandtab
