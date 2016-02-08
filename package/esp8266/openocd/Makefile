# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 OpenOCD package

# See: http://www.esp8266.com/viewtopic.php?f=9&t=1871

# Note: the following are required: 
# - libtool
# - pkg-config >= 0.23 (or compatible)
# - autoconf >= 2.64
# - automake >= 1.9
# - texinfo

include ../../../include/mb.inc

PACKAGE_NAME := openocd
$(PACKAGE_NAME)_SOURCE := "https://github.com/projectgus/openocd.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

# Build openocd executable for host
define $(PACKAGE_NAME)_POSTACTION
	cd $1; \
	./bootstrap; \
	./configure; \
	make
endef

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
