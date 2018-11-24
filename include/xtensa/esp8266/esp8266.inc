# \copyright 2015-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top make include file for ESP8266 architecture

# -------------------------------------------------
#

APP_LD_DIR ?= $(ARCH_INCLUDE_DIR)

ESP8266_APP_FLASH_ADDRESS ?= 0x100000
ZBOOT_FLASH_ADDRESS = 0x0

LDFLAGS += $(foreach ld,$(APP_LD_DIR),-L$(ld)) $(foreach ld,$(APP_LD_SCRIPT),$(addprefix -T ,$(ld))) -g -Os -nostdlib -Wl,--no-check-sections -Wl,--gc-sections -Wl,-static -Wl,-EL

CFLAGS += -Os -g -Wpointer-arith -mlongcalls -fno-inline-functions -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections
CPPFLAGS += -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections
ASMFLAGS += -c -g -x assembler-with-cpp -MMD -mlongcalls -mtext-section-literals
CDEFS += __esp8266__ __ets__ ICACHE_FLASH ESP8266 F_CPU=$(TARGET_CPU_SPEED) ESP_PLATFORM
OBJCOPYDEFS += -O elf32-xtensa-le -B xtensa --rename-section .data=.irom0.other

# ----------------------------------------------------------------------------------------
# Architecture-specific Library Steps

define $(MB_TARGET)_post_lib
endef

# ----------------------------------------------------------------------------------------
# Architecture-specific Application Steps

ZTOOL_OPTIONS = -d0 -z
ifneq ($(APP_VERSION),)
ZTOOL_OPTIONS += -v $(APP_VERSION)
endif
ifneq ($(APP_DESCRIPTION),)
ZTOOL_OPTIONS += -n $(APP_DESCRIPTION)
endif

# esp8266_post_app(app_out_file)
define $(MB_TARGET)_post_app
	$(ZTOOL) $(ZTOOL_OPTIONS) -e $1 -o $(basename $1).bin -r".irom0.text .irom0.other" -s".text .data .rodata"
endef

# esp8266_app_info(app_file,app_dir)
define $(MB_TARGET)_app_info
	$(OBJDUMP) -h -j .data -j .rodata -j .bss -j .text -j .irom0.text -j .iram.text $2/$1
endef

# esp8266_app_flash(app_file,app_dir)
define $(MB_TARGET)_app_flash
	$(ECHO) "Flashing on port $(TARGET_PORT) @ $(TARGET_BAUD)"
	$(ESPTOOL) --chip esp8266 write_flash $(ESP8266_APP_FLASH_ADDRESS) $2/$(basename $1).bin
endef

# ----------------------------------------------------------------------------------------
# Other

# esp8266_checkboard(app_file,app_dir)
define $(MB_TARGET)_checkboard(app_file,app_dir)
	ifeq ($(BOARD_LD_SCRIPT_$(TARGET_BOARD)),)
	$(error "Invalid board type specification ($(TARGET_BOARD))")
	endif
endef

define xtensa_flash_erase
	$(ECHO) "Erasing flash..."
	$(ESPTOOL) --chip esp8266 erase_flash
endef

# vim: syntax=make tabstop=4 noexpandtab
