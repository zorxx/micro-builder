# \copyright 2017-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief rboot API source 

ZBOOT_DIR := $(PACKAGE_DIR)/esp8266/zboot
ZBOOT_SRC_DIR := $(ZBOOT_DIR)/zboot_source

INCDIR += \
 $(ZBOOT_SRC_DIR) \
 $(ZBOOT_SRC_DIR)/appcode
LIBS += zboot
LDFLAGS += -u Cache_Read_Enable_New

define xtensa_flash_boot
	$(MAKE) -C $(ZBOOT_DIR) flash
endef

# vim: syntax=make tabstop=4 noexpandtab
