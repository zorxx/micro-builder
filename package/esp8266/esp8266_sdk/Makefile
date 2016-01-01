# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 NORTOS SDK package

include ../../../include/top.inc

PACKAGE_NAME := esp8266_sdk

# Download information
$(PACKAGE_NAME)_FILENAME := sdk.zip
$(PACKAGE_NAME)_SOURCE := "http://bbs.espressif.com/download/file.php?id=989"
$(PACKAGE_NAME)_SOURCE_METHOD := wget

all: .$(PACKAGE_NAME).download
clean:
	$(call package_clean,$(PACKAGE_NAME))

include ../../../include/bottom.inc

# vim: syntax=make tabstop=4 noexpandtab
