# \copyright 2015-2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 Arduino toolchain package

include ../../../include/mb.inc

PACKAGE_NAME := arduino_toolchain
$(PACKAGE_NAME)_SOURCE_METHOD := wget

$(PACKAGE_NAME)_FILENAME := $(strip \
	$(if $(findstring Linux_64,$(HOST_ARCH)),x86_64-linux-gnu.xtensa-lx106-elf-20ed2b9c.tar.gz, \
	  	$(if $(findstring WIN,$(HOST_ARCH)),x86_64-w64-mingw32.xtensa-lx106-elf-20ed2b9c.zip, \
	   		$(if $(findstring OSX,$(HOST_ARCH)),x86_64-apple-darwin14.xtensa-lx106-elf-20ed2b9c.tar.gz, \
	   			unknown))))
$(PACKAGE_NAME)_SOURCE := "https://github.com/earlephilhower/esp-quick-toolchain/releases/download/2.5.0-3/$($(PACKAGE_NAME)_FILENAME)"

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
