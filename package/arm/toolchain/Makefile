# \copyright 2017-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ARM toolchain package

include ../../../include/mb.inc

PACKAGE_NAME := toolchain
$(PACKAGE_NAME)_SOURCE_METHOD := wget
TOOLCHAIN_YEAR := 2017
TOOLCHAIN_QUARTER := q4
TOOLCHAIN_RELEASE := major

TOOLCHAIN_SUFFIX := $(strip \
	$(if $(findstring Linux_64,$(HOST_ARCH)),linux.tar.bz2, \
		$(if $(findstring Linux_32,$(HOST_ARCH)),linux.tar.bz2, \
			$(if $(findstring WIN,$(HOST_ARCH)),win32.zip, \
				unknown))))
$(PACKAGE_NAME)_FILENAME := "gcc-arm-none-eabi-$(TOOLCHAIN_VERSION)-$(TOOLCHAIN_YEAR)-$(TOOLCHAIN_QUARTER)-$(TOOLCHAIN_RELEASE)-$(TOOLCHAIN_SUFFIX)"
$(PACKAGE_NAME)_SOURCE := "https://developer.arm.com/-/media/Files/downloads/gnu-rm/$(TOOLCHAIN_VERSION)-$(TOOLCHAIN_YEAR)$(TOOLCHAIN_QUARTER)/$($(PACKAGE_NAME)_FILENAME)"

define $(PACKAGE_NAME)_LINUX_POSTACTION
	@$(CD) $1; \
	$(MV) gcc-arm-none-eabi-$(TOOLCHAIN_VERSION)-$(TOOLCHAIN_YEAR)-$(TOOLCHAIN_QUARTER)-$(TOOLCHAIN_RELEASE) toolchain
endef

define $(PACKAGE_NAME)_WIN_POSTACTION
	@$(CD) $1; \
	$(MKDIR) toolchain; \
	$(MV) arm-non-eabi bin lib share toolchain
endef

define $(PACKAGE_NAME)_POSTACTION
	echo "Postaction"
	$(if $(findstring Linux,$(HOST_ARCH)),$(call $(PACKAGE_NAME)_LINUX_POSTACTION,$1))
	$(if $(findstring WIN,$(HOST_ARCH)),$(call $(PACKAGE_NAME)_WIN_POSTACTION,$1))
endef

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
