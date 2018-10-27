# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP32 SDK package

include ../../../include/mb.inc

PACKAGE_NAME := esp32_sdk

# Download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/zorxx/esp-idf.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

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
		BATCH_BUILD=1 V=0 \
		$(MAKE) -C $(ESP32_SDK_DIR)/$(ESP32_SDK_PROJDIR) all
endef

sdk_clean:
	IDF_PATH=$(ESP32_SDK_DIR) \
		$(MAKE) --no-print-directory -C $(ESP32_SDK_DIR)/$(ESP32_SDK_PROJDIR) clean
	@$(foreach file,$(wildcard .esp32_sdk_build.generic),$(RM) $(file);)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/generic.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
