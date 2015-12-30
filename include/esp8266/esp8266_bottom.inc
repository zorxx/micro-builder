# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief 

esp8266_externals: esp8266_sdk esp8266_tools esp8266_arduino
esp8266_externals_clean: esp8266_sdk_clean esp8266_tools_clean esp8266_arduino_clean

# ----------------------------------------------------------------------------------------
# Architecture-specific build steps

esp8266_post_lib:

esp8266_post_app:
	@$(ESPTOOL) elf2image $(APP_OUT) -o$(BUILD_TEMP_DIR)/

esp8266_app_info: app
	@$(OBJDUMP) -h -j .data -j .rodata -j .bss -j .text -j .irom0.text $(APP_OUT)

esp8266_app_flash: app
	@$(ECHO) "Flashing at: $(foreach file,$(wildcard $(BUILD_TEMP_DIR)/0x*.bin),$(notdir $(basename $(file))))"
	@$(ESPTOOL) -p $(TARGET_PORT) -b $(TARGET_BAUD) write_flash $(foreach file,$(wildcard $(BUILD_TEMP_DIR)/0x*.bin),$(notdir $(basename $(file))) $(file))

# ----------------------------------------------------------------------------------------
# SDK Download/Installation

$(ESP8266_SDK_INSTALL_DIR):
	@$(ECHO) "Downloading and installing ESP8266 SDK..."
	@$(MKDIR) -p $@
	@$(WGET) -nc $(ESP8266_SDK_SOURCE) -O $@/sdk.zip
	@$(CD) $@;$(UNZIP) -q sdk.zip

esp8266_sdk: $(ESP8266_SDK_INSTALL_DIR)
esp8266_sdk_clean:
	@$(RM) -rf $(SDK_DIR)

# ----------------------------------------------------------------------------------------
# Espressif Tools Download/Installation

$(ESPTOOL_DIR):
	@$(MKDIR) -p $@
	@$(GIT) clone $(ESPTOOL_SOURCE) $@

esp8266_tools: $(ESPTOOL_DIR)
esp8266_tools_clean:
	@$(RM) -rf $(ESPTOOL_DIR)

# ----------------------------------------------------------------------------------------
# ESP8266/Arduino

$(ESP8266_ARDUINO_DIR):
	@$(MKDIR) -p $@
	@$(GIT) clone $(ESP8266_ARDUINO_SOURCE) $@
esp8266_arduino: $(ESP8266_ARDUINO_DIR)
esp8266_arduino_clean:
	@$(RM) -rf $(ESP8266_ARDUINO_DIR)      

# vim: tabstop=4 noexpandtab
