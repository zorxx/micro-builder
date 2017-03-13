# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for rboot, ESP8266 bootloader 

#required_prereqs = package/esp8266/esp8266_sdk
required_prereqs = package/esp8266/arduino
dependencies = package/esp8266/esptool2

include ../../../include/mb.inc

# ----------------------------------------------------------
# External Package 

PACKAGE_NAME := rboot

# External package download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/raburton/rboot.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

EXTERNAL_TARGETS += $(PACKAGE_NAME)

# ----------------------------------------------------------
# Bootloader Application 

GENERIC_TARGETS := rboot_build

define GENERIC_rboot_build
	@echo "Making rboot..."
        RBOOT_EXTRA_INCDIR="$(INCDIR)" \
	RBOOT_BAUDRATE=115200 \
        ESPTOOL2="$(ESPTOOL2)" \
		$(MAKE) -C rboot_source all
endef

flash: all
	@$(ECHO) "Flashing on port $(TARGET_PORT) @ $(TARGET_BAUD)"
	@$(ESPTOOL) -cp $(TARGET_PORT) -cd $(TARGET_BOARD) -cb $(TARGET_BAUD) -cf rboot_source/firmware/rboot.bin

# ----------------------------------------------------------
# Application API Library

LIB_NAME_API := lib$(PACKAGE_NAME)
$(LIB_NAME_API)_obj := $(foreach file, \
                          rboot_source/appcode/rboot-api.c, \
                          $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

LIBRARY_TARGETS += $(LIB_NAME_API)
LIBRARY_SUBMAKE := true

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/generic.inc
include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
