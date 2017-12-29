# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for libopencm3 package

include ../../../include/mb.inc

PACKAGE_NAME := libopencm3

# Download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/libopencm3/libopencm3.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

define $(PACKAGE_NAME)_POSTACTION
	$(MAKE) --no-print-directory -C $(PACKAGE_NAME)_source
endef

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
