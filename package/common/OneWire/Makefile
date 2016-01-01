# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for OneWire bus library package

include ../../../include/top.inc

PACKAGE_NAME := OneWire
LIB_NAME := lib$(PACKAGE_NAME)

# Download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/PaulStoffregen/OneWire.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git
$(PACKAGE_NAME)_VERSION := v2.3.1

$(LIB_NAME)_obj := source/OneWire.o

all: .$(PACKAGE_NAME).download $(LIB_BIN_DIR)/$(LIB_NAME).a
clean:
	$(call package_clean,$(PACKAGE_NAME))
	$(call library_clean,$(LIB_NAME))
	$(call build_clean)

include ../../../include/bottom.inc

# vim: syntax=make tabstop=4 noexpandtab
