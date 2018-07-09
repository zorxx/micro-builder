# \copyright 2015-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 SDK package

include ../../../include/mb.inc

PACKAGE_NAME := esp8266_sdk

# Download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/espressif/ESP8266_RTOS_SDK.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

# Remove the Cache_Read_Enable_New function from libmain.a. We need to
#  use the function defined in rboot in order to make use of flash
#  larger than 1 MiB
define $(PACKAGE_NAME)_POSTACTION
$(OBJCOPY) -W Cache_Read_Enable_New $(ESP8266_SDK_DIR)/components/esp8266/lib/libcore.a
endef

EXTERNAL_TARGETS += $(PACKAGE_NAME)

# ----------------------------------------------------------

GENERIC_TARGETS := esp8266_sdk_build

define GENERIC_esp8266_sdk_build
	@echo "Making esp8266_sdk..."
	$(CP) sdkconfig $(ESP8266_SDK_DIR)/$(ESP8266_SDK_PROJDIR)
	IDF_PATH=$(ESP8266_SDK_DIR) PATH=$(PATH):$(TOOLCHAIN_BIN_DIR) \
		$(MAKE) -C $(ESP8266_SDK_DIR)/$(ESP8266_SDK_PROJDIR) all
endef

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/generic.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
