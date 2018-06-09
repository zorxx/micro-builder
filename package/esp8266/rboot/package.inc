# \copyright 2017-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief rboot API source 

RBOOT_DIR := $(PACKAGE_DIR)/esp8266/rboot/rboot_source

INCDIR += \
 $(RBOOT_DIR) \
 $(RBOOT_DIR)/appcode
LIBS += rboot

# vim: syntax=make tabstop=4 noexpandtab
