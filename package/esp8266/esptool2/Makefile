# \copyright 2017-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 esptool2 package

include ../../../include/mb.inc

PACKAGE_NAME := esptool2
$(PACKAGE_NAME)_SOURCE := "https://github.com/zorxx/esptool2.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/dir.inc

# ----------------------------------------------------------

GENERIC_TARGETS := esptool2_build

define GENERIC_esptool2_build
	@echo "Making esptool2..."
	@$(MAKE) --no-print-directory -C esptool2_source all
endef

esptool2:
	$(call GENERIC_esptool2_build)
esptool2_clean:
	$(MAKE) -C esptool2_source clean
.PHONY: esptool2 esptool2_clean

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/generic.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
