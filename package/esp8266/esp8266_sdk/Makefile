# \copyright 2015-2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 NORTOS SDK package

include ../../../include/mb.inc

PACKAGE_NAME := esp8266_sdk

# Download information
$(PACKAGE_NAME)_FILENAME := sdk.zip
$(PACKAGE_NAME)_SOURCE := "http://bbs.espressif.com/download/file.php?id=1469"
$(PACKAGE_NAME)_SOURCE_METHOD := wget

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
