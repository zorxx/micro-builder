# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for rboot, ESP8266 bootloader 

#required_prereqs = package/esp8266/esp8266_sdk
required_prereqs = package/esp8266/arduino
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
	RBOOT_BAUDRATE=115200 \
        ESPTOOL2="$(ESPTOOL2)" \
		$(MAKE) -C rboot_source all
endef

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/generic.inc
include $(INCLUDE_DIR)/dir.inc

flash: all
	@$(ECHO) "Flashing on port $(TARGET_PORT) @ $(TARGET_BAUD)"
	@$(ESPTOOL) -cp $(TARGET_PORT) -cd $(TARGET_BOARD) -cb $(TARGET_BAUD) -cf rboot_source/firmware/rboot.bin

# vim: syntax=make tabstop=4 noexpandtab
