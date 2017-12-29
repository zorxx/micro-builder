# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for openocd package

include ../../../include/mb.inc

PACKAGE_NAME := openocd
$(PACKAGE_NAME)_SOURCE_METHOD := wget
$(PACKAGE_NAME)_VERSION := 0.10.0

$(PACKAGE_NAME)_FILENAME := $(PACKAGE_NAME)-$($(PACKAGE_NAME)_VERSION).tar.bz2
$(PACKAGE_NAME)_SOURCE := https://downloads.sourceforge.net/project/$(PACKAGE_NAME)/$(PACKAGE_NAME)/$($(PACKAGE_NAME)_VERSION)/$($(PACKAGE_NAME)_FILENAME)

define $(PACKAGE_NAME)_POSTACTION
	@cd $(PACKAGE_NAME)_source;$(MV) $(PACKAGE_NAME)-$($(PACKAGE_NAME)_VERSION) $(PACKAGE_NAME)
	@cd $(PACKAGE_NAME)_source/$(PACKAGE_NAME);./configure
	@$(MAKE) --no-print-directory -C $(OPENOCD_DIR)
endef

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
