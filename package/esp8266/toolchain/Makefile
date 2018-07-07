# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 toolchain package

include ../../../include/mb.inc

PACKAGE_NAME := toolchain
$(PACKAGE_NAME)_SOURCE := "https://github.com/pfalcon/esp-open-sdk.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

EXTERNAL_TARGETS += $(PACKAGE_NAME)

# ----------------------------------------------------------

define GENERIC_esp8266_toolchain_build
	@echo "Making ESP8266 toolchain..."
	@cd toolchain_source;$(MAKE) STANDALONE=n
endef

GENERIC_TARGETS := esp8266_toolchain_build

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/generic.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
