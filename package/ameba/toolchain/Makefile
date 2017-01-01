# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for Ameba toolchain package

include ../../../include/mb.inc

PACKAGE_NAME := toolchain
$(PACKAGE_NAME)_SOURCE_METHOD := wget
TOOLCHAIN_VERSION := 5.3.1-2016.05

$(PACKAGE_NAME)_FILENAME := $(strip \
	$(if $(findstring Linux_64,$(HOST_ARCH)),gcc-linaro-$(TOOLCHAIN_VERSION)-x86_64_arm-eabi.tar.xz, \
		$(if $(findstring Linux_32,$(HOST_ARCH)),gcc-linaro-$(TOOLCHAIN_VERSION)-i686-arm-eabi.tar.xz, \
			$(if $(findstring WIN,$(HOST_ARCH)),gcc-linaro-$(TOOLCHAIN_VERSION)-i686-mingw32_arm-ebi.tar.xz, \
					unknown))))
$(PACKAGE_NAME)_SOURCE := https://releases.linaro.org/components/toolchain/binaries/latest-5/arm-eabi/$($(PACKAGE_NAME)_FILENAME)

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
