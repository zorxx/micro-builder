# \copyright 2015-2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 Arduino toolchain package

include ../../../include/mb.inc

PACKAGE_NAME := arduino_toolchain
$(PACKAGE_NAME)_SOURCE_METHOD := wget

$(PACKAGE_NAME)_FILENAME := $(strip \
	$(if $(findstring Linux_64,$(HOST_ARCH)),linux64-xtensa-lx106-elf-gb404fb9.tar.gz, \
		$(if $(findstring Linux_32,$(HOST_ARCH)),linux32-xtensa-lx106-elf.tar.gz, \
			$(if $(findstring WIN,$(HOST_ARCH)),win32-xtensa-lx106-elf-gb404fb9-2.tar.gz, \
				$(if $(findstring OSX,$(HOST_ARCH)),osx-xtensa-lx106-elf-gb404fb9-2.tar.gz, \
					unknown)))))
$(PACKAGE_NAME)_SOURCE := http://arduino.esp8266.com/$($(PACKAGE_NAME)_FILENAME)

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
