# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ARM toolchain package

include ../../../include/mb.inc

PACKAGE_NAME := toolchain
$(PACKAGE_NAME)_SOURCE_METHOD := wget
TOOLCHAIN_VERSION := 7-2017-q4

TOOLCHAIN_SUFFIX := $(strip \
	$(if $(findstring Linux_64,$(HOST_ARCH)),linux.tar.bz2, \
		$(if $(findstring Linux_32,$(HOST_ARCH)),linux.tar.bz2, \
			$(if $(findstring WIN,$(HOST_ARCH)),win32.zip, \
				unknown))))
$(PACKAGE_NAME)_FILENAME := "gcc-arm-none-eabi-$(TOOLCHAIN_VERSION)-major-$(TOOLCHAIN_SUFFIX)"
$(PACKAGE_NAME)_SOURCE := https://developer.arm.com/-/media/Files/downloads/gnu-rm/7-2017q4/$($(PACKAGE_NAME)_FILENAME)

# Rename directory to remove version 
define $(PACKAGE_NAME)_POSTACTION
	cd $1; \
	mv gcc-arm-none-eabi-$(TOOLCHAIN_VERSION)-major toolchain
endef

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
