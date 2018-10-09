# \copyright 2017-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 ztool package

include ../../../include/mb.inc

PACKAGE_NAME := ztool
$(PACKAGE_NAME)_SOURCE := "https://github.com/zorxx/ztool.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/dir.inc

# ----------------------------------------------------------

GENERIC_TARGETS := ztool_build

define GENERIC_ztool_build
	@echo "Making ztool..."
	@unset CC;$(MAKE) --no-print-directory -C ztool_source all
endef

ztool:
	$(call GENERIC_ztool_build)
ztool_clean:
	@$(MAKE) -C ztool_source clean
	@-$(RM) .$(PACKAGE_NAME)_build.generic
.PHONY: ztool ztool_clean

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/generic.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
