# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for Xtensa ESP8266 toolchain package

include ../../../include/mb.inc

PACKAGE_NAME := esp_toolchain
$(PACKAGE_NAME)_SOURCE_METHOD := wget

$(PACKAGE_NAME)_ARCH := $(strip \
	$(if $(findstring Linux_64,$(HOST_ARCH)),linux64, \
		$(if $(findstring Linux_32,$(HOST_ARCH)),linux32, \
			$(if $(findstring WIN,$(HOST_ARCH)),win32, \
				$(if $(findstring OSX,$(HOST_ARCH)),osx, \
					unknown)))))

$(PACKAGE_NAME)_FILENAME := xtensa-lx106-elf-$($(PACKAGE_NAME)_ARCH)-1.22.0-92-g8facf4c-5.2.0.tar.gz

$(PACKAGE_NAME)_SOURCE := https://dl.espressif.com/dl/$($(PACKAGE_NAME)_FILENAME)

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
