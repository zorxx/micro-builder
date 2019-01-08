# \copyright 2019 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for STM32 versaloon application 

dependencies =

include ../../../include/mb.inc

# ----------------------------------------------------------
# External Package 

PACKAGE_NAME := versaloon

# External package download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/zoobab/versaloon.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

EXTERNAL_TARGETS += $(PACKAGE_NAME)

# ----------------------------------------------------------
# Application 

GENERIC_TARGETS := versaloon_build

define GENERIC_versaloon_build
	@echo "Making zboot..."
	@$(MAKE) --no-print-directory -C $(PACKAGE_NAME)_source all
endef

versaloon:
	$(call GENERIC_versaloon_build)

versaloon_clean:
	@$(MAKE) --no-print-directory -C $(PACKAGE_NAME)_source clean
	@$(foreach file,$(wildcard .zboot_build.generic),$(RM) $(file);)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/generic.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
