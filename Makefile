# \copyright 2015-2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level makefile for micro-builder 
# This will build all prerequisites for the selected variant (MB_VARIANT)

include include/mb.inc

default: all

ARCH_LIST := $(sort $(foreach arch,$(wildcard $(INCLUDE_DIR)/*/.),$(lastword $(subst /, ,$(basename $(arch))))))
define get_arch_variants
	$(sort $(basename $(notdir $(wildcard $(INCLUDE_DIR)/$1/variants/*.inc))))
endef

variants:
	@echo "Architectures: $(ARCH_LIST)"
	@echo $(foreach arch,$(ARCH_LIST),"Variants for $(arch):\n$(call get_arch_variants,$(arch))\n")
.PHONY: variants

clean:
	@$(foreach dir,$(DEPENDENCY_DIRS),make --no-print-directory -C $(dir) clean;)
	@$(RM) -rf $(TARGET_BIN_DIR)
.PHONY: clean

# vim: tabstop=4 noexpandtab
