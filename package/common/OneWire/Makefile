# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for OneWire bus library package

include ../../../include/top.inc

PACKAGE_NAME := OneWire

# Download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/PaulStoffregen/OneWire.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git
$(PACKAGE_NAME)_VERSION := v2.3.1

# Library
LIB_NAME := lib$(PACKAGE_NAME)
$(LIB_NAME)_obj := $(foreach file, \
		$(wildcard source/*.c) \
		$(wildcard source/*.cpp) \
		$(wildcard source/*.S), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

all: .$(PACKAGE_NAME).download
	@$(call build_library,$(LIB_NAME))
clean: lib_clean
	@$(call package_clean,$(PACKAGE_NAME))
lib_clean:
	@$(call library_clean,$(LIB_NAME))
	@$(call build_clean)

include ../../../include/bottom.inc

# vim: syntax=make tabstop=4 noexpandtab
