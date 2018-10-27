# \copyright 2017-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for zboot, Xtensa bootloader 

dependencies = package/xtensa/ztool

include ../../../include/mb.inc

# ----------------------------------------------------------
# External Package 

PACKAGE_NAME := zboot

# External package download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/zorxx/zboot.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

EXTERNAL_TARGETS += $(PACKAGE_NAME)

# ----------------------------------------------------------
# Bootloader Application 

GENERIC_TARGETS := zboot_build

ifeq ($(TARGET_FLASH_SIZE),4M)
ZBOOT_IMAGE_COUNT := 3
ZBOOT_ROM0 := 0x100000
ZBOOT_ROM1 := 0x200000
ZBOOT_ROM2 := 0x300000
ZBOOT_ROM3 := 0
else
ZBOOT_IMAGE_COUNT := 2
ZBOOT_ROM0 := 0x3000
ZBOOT_ROM1 := 0x80000
ZBOOT_ROM2 := 0
ZBOOT_ROM3 := 0
endif

define GENERIC_zboot_build
	@echo "Making zboot..."
        @ZBOOT_EXTRA_INCDIR="$(INCDIR)" \
	ZBOOT_BAUDRATE=115200 \
	ZBOOT_BIG_FLASH=1 \
	ZBOOT_GPIO_ENABLED=1 \
	SPI_SIZE=$(TARGET_FLASH_SIZE) \
	SPI_MODE=$(TARGET_FLASH_MODE) \
	SPI_SPEED=$(TARGET_FLASH_SPEED) \
	ZBOOT_DEFAULT_CONFIG_IMAGE_COUNT=$(ZBOOT_IMAGE_COUNT) \
	ZBOOT_DEFAULT_CONFIG_ROM0=$(ZBOOT_ROM0) \
	ZBOOT_DEFAULT_CONFIG_ROM1=$(ZBOOT_ROM1) \
	ZBOOT_DEFAULT_CONFIG_ROM2=$(ZBOOT_ROM2) \
	ZBOOT_DEFAULT_CONFIG_ROM3=$(ZBOOT_ROM3) \
        XTENSA_BINDIR="$(TOOLCHAIN_BIN_DIR)" \
        TOOLCHAIN_PREFIX=$(TOOLCHAIN_PREFIX) \
        ZTOOL="$(ZTOOL)" \
		$(MAKE) --no-print-directory -C zboot_source all
endef

zboot:
	$(call GENERIC_zboot_build)

zboot_clean:
	@$(MAKE) --no-print-directory -C zboot_source clean
	@$(foreach file,$(wildcard .zboot_build.generic),$(RM) $(file);)

flash: all
	@$(ECHO) "Flashing on port $(TARGET_PORT) @ $(TARGET_BAUD)"
	$(ESPTOOL) -bz $(TARGET_FLASH_SIZE) -bf $(TARGET_FLASH_SPEED) -bm $(TARGET_FLASH_MODE) -cp $(TARGET_PORT) -cd $(TARGET_BOARD) -cb $(TARGET_BAUD) -cf zboot_source/firmware/zboot.bin

# ----------------------------------------------------------
# Application API Library

LIB_NAME_API := lib$(PACKAGE_NAME)
$(LIB_NAME_API)_obj := $(foreach file, \
                          $(wildcard zboot_source/appcode/*.c), \
                          $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))
CDEFS += BOOT_BIG_FLASH=1 BOOT_RTC_ENABLED=1
#CDEFS += ZBOOT_API_DEBUG
LIBRARY_TARGETS += $(LIB_NAME_API)
LIBRARY_SUBMAKE := true

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/generic.inc
include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
