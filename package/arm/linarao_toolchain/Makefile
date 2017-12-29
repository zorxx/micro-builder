# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for Linaro ARM toolchain package

include ../../../include/mb.inc

PACKAGE_NAME := toolchain
$(PACKAGE_NAME)_SOURCE_METHOD := wget
GCC_VERSION := 5.5-2017.10
TOOLCHAIN_VERSION := 5.5.0-2017.10

TOOLCHAIN_ARCH := $(strip \
	$(if $(findstring Linux_64,$(HOST_ARCH)),x86_64, \
		$(if $(findstring Linux_32,$(HOST_ARCH)),i686, \
			$(if $(findstring WIN,$(HOST_ARCH)),i686-mingw32, \
				unknown))))
$(PACKAGE_NAME)_FILENAME := "gcc-linaro-$(TOOLCHAIN_VERSION)-$(TOOLCHAIN_ARCH)_arm-eabi.tar.xz"
$(PACKAGE_NAME)_SOURCE := https://releases.linaro.org/components/toolchain/binaries/$(GCC_VERSION)/arm-eabi/$($(PACKAGE_NAME)_FILENAME)

# Rename directory to remove version 
define $(PACKAGE_NAME)_POSTACTION
	cd $1; \
	mv gcc-linaro-$(TOOLCHAIN_VERSION)-$(TOOLCHAIN_ARCH)_arm-eabi toolchain
endef

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
