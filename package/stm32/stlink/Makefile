# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for stlink application 

dependencies = package/arm/toolchain

include ../../../include/mb.inc

PACKAGE_NAME := stlink

$(PACKAGE_NAME)_SOURCE := "https://github.com/texane/stlink.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

define $(PACKAGE_NAME)_POSTACTION
	@CC=gcc CXX=g++ $(MAKE) --no-print-directory -C $(STLINK_DIR) release 
endef

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
