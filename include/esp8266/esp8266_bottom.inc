# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Bottom make include file for ESP8266 architecture

# ----------------------------------------------------------------------------------------
# Architecture-specific build steps

# esp8266_app_info(app_file,app_dir)
define esp8266_app_info
	@$(OBJDUMP) -h -j .data -j .rodata -j .bss -j .text -j .irom0.text -j .iram.text $2/$1
endef

# esp8266_app_flash(app_file,app_dir)
define esp8266_app_flash
	@$(ECHO) "Flashing at: $(foreach file,$(wildcard $2/0x*.bin),$(notdir $(basename $(file))))"
	@$(ESPTOOL) -p $(TARGET_PORT) -b $(TARGET_BAUD) write_flash $(foreach file,$(wildcard $2/0x*.bin),$(notdir $(basename $(file))) $(file))
endef

# esp8266_checkboard(app_file,app_dir)
define esp8266_checkboard(app_file,app_dir)
	ifeq ($(BOARD_LD_SCRIPT_$(TARGET_BOARD)),)
	$(error "Invalid board type specification ($(TARGET_BOARD))")
	endif
endef

# vim: syntax=make tabstop=4 noexpandtab
