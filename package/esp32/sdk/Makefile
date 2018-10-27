# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP32 SDK package

include ../../../include/mb.inc

PACKAGE_NAME := esp32_sdk

# Download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/zorxx/esp-idf.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

# Remove the Cache_Read_Enable_New function from libmain.a. We need to
#  use the function defined in rboot in order to make use of flash
#  larger than 1 MiB
define $(PACKAGE_NAME)_POSTACTION
#$(OBJCOPY) -W Cache_Read_Enable_New $(ESP8266_SDK_DIR)/components/esp8266/lib/libcore.a
endef

EXTERNAL_TARGETS += $(PACKAGE_NAME)

# ----------------------------------------------------------

GENERIC_TARGETS := esp32_sdk_build

#ESP8266_SDK_EXTRA_LDFLAGS := "-L$(LIB_BIN_DIR) -lzboot -Tesp8266.rom_cache.ld -L$(ESP8266_SDK_DIR)/.."

define GENERIC_esp32_sdk_build
	@echo "Making esp32_sdk..."
	$(CP) sdkconfig $(ESP32_SDK_DIR)/$(ESP32_SDK_PROJDIR)
	EXTRA_LDFLAGS=$(ESP32_SDK_EXTRA_LDFLAGS) \
                IDF_PATH=$(ESP32_SDK_DIR) \
		PATH=$(PATH):$(TOOLCHAIN_BIN_DIR) \
		BATCH_BUILD=1 \
		$(MAKE) -C $(ESP32_SDK_DIR)/$(ESP32_SDK_PROJDIR) all
endef

sdk_clean:
	IDF_PATH=$(ESP32_SDK_DIR) \
		$(MAKE) --no-print-directory -C $(ESP32_SDK_DIR)/$(ESP32_SDK_PROJDIR) clean
	@$(foreach file,$(wildcard .esp32_sdk_build.generic),$(RM) $(file);)

# ----------------------------------------------------------

LIB_NAME_ESP32_SDK := libesp32_sdk
$(LIB_NAME_ESP32_SDK)_obj := $(foreach file, \
                startup.c, \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

LIBRARY_TARGETS := $(LIB_NAME_ESP32_SDK)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/generic.inc
#include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
