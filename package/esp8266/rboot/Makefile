# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for rboot, ESP8266 bootloader 

required_prereqs = package/esp8266/esp8266_sdk
dependencies = package/esp8266/esptool2

include ../../../include/mb.inc

PACKAGE_NAME := rboot

# External package download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/raburton/rboot.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

EXTERNAL_TARGETS += $(PACKAGE_NAME)

# ----------------------------------------------------------

GENERIC_TARGETS := rboot_build

define GENERIC_rboot_build
	@echo "Making rboot..."
        RBOOT_EXTRA_INCDIR="$(INCDIR)" \
        ESPTOOL2="$(ESPTOOL2)" \
		$(MAKE) -C rboot_source all
endef

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/generic.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
