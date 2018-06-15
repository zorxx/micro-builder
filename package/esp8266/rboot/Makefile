# \copyright 2017-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for rboot, ESP8266 bootloader 

dependencies = package/esp8266/esptool2

include ../../../include/mb.inc

# ----------------------------------------------------------
# External Package 

PACKAGE_NAME := rboot

# External package download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/zorxx/rboot.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

EXTERNAL_TARGETS += $(PACKAGE_NAME)

# ----------------------------------------------------------
# Bootloader Application 

GENERIC_TARGETS := rboot_build

define GENERIC_rboot_build
	@echo "Making rboot..."
        @RBOOT_EXTRA_INCDIR="$(INCDIR)" \
	RBOOT_BAUDRATE=115200 \
	RBOOT_RTC_ENABLED=1 \
	RBOOT_BIG_FLASH=1 \
	RBOOT_GPIO_ENABLED=1 \
	SPI_SIZE=$(TARGET_FLASH_SIZE) \
	SPI_MODE=$(TARGET_FLASH_MODE) \
	SPI_SPEED=$(TARGET_FLASH_SPEED) \
	RBOOT_DEFAULT_CONFIG_IMAGE_COUNT=3 \
	RBOOT_DEFAULT_CONFIG_ROM0=0x100000 \
	RBOOT_DEFAULT_CONFIG_ROM1=0x200000 \
	RBOOT_DEFAULT_CONFIG_ROM2=0x300000 \
        XTENSA_BINDIR="$(TOOLCHAIN_BIN_DIR)" \
        ZTOOL="$(ZTOOL)" \
		$(MAKE) --no-print-directory -C rboot_source all
endef

rboot:
	$(call GENERIC_rboot_build)

rboot_clean:
	@$(MAKE) --no-print-directory -C rboot_source clean

flash: all
	@$(ECHO) "Flashing on port $(TARGET_PORT) @ $(TARGET_BAUD)"
	@$(ESPTOOL) -bz $(TARGET_FLASH_SIZE) -bf $(TARGET_FLASH_SPEED) -bm $(TARGET_FLASH_MODE) -cp $(TARGET_PORT) -cd $(TARGET_BOARD) -cb $(TARGET_BAUD) -cf rboot_source/firmware/rboot.bin

# ----------------------------------------------------------
# Application API Library

LIB_NAME_API := lib$(PACKAGE_NAME)
$(LIB_NAME_API)_obj := $(foreach file, \
                          $(wildcard rboot_source/appcode/*.c), \
                          $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))
CDEFS += BOOT_BIG_FLASH=1 BOOT_RTC_ENABLED=1
LIBRARY_TARGETS += $(LIB_NAME_API)
LIBRARY_SUBMAKE := true

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/generic.inc
include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
