# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 Arduino SDK package

include ../../../include/top.inc

PACKAGE_NAME := esp8266_arduino

# Download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/esp8266/Arduino.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

all: .$(PACKAGE_NAME).download
clean:
	$(call package_clean,$(PACKAGE_NAME))

include ../../../include/bottom.inc

# vim: syntax=make tabstop=4 noexpandtab
