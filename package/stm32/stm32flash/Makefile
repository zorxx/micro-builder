# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for stm32flash package

include ../../../include/mb.inc

PACKAGE_NAME := stm32flash
$(PACKAGE_NAME)_SOURCE_METHOD := wget
$(PACKAGE_NAME)_VERSION := 0.5

$(PACKAGE_NAME)_FILENAME := $(PACKAGE_NAME)-$($(PACKAGE_NAME)_VERSION).tar.gz
$(PACKAGE_NAME)_SOURCE := https://downloads.sourceforge.net/project/stm32flash/$($(PACKAGE_NAME)_FILENAME)

define $(PACKAGE_NAME)_POSTACTION
	@$(MAKE) --no-print-directory -C $(STM32FLASH_DIR)
endef

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
