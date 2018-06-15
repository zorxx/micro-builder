# \copyright 2017-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief rboot API source 

RBOOT_DIR := $(PACKAGE_DIR)/esp8266/rboot
RBOOT_SRC_DIR := $(RBOOT_DIR)/rboot_source

INCDIR += \
 $(RBOOT_SRC_DIR) \
 $(RBOOT_SRC_DIR)/appcode
LIBS += rboot
LDFLAGS += -u Cache_Read_Enable_New

define xtensa_flash_boot
	$(MAKE) -C $(RBOOT_DIR) flash
endef

# vim: syntax=make tabstop=4 noexpandtab
