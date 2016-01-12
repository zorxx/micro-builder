# \copyright 2015-2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment for ESP8266 esptool package

ESPTOOL_DIR := $(PACKAGE_DIR)/esp8266/esptool/source
ESPTOOL := python $(ESPTOOL_DIR)/esptool.py

# vim: syntax=make tabstop=4 noexpandtab
