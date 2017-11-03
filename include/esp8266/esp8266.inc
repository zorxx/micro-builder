# \copyright 2015-2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top make include file for ESP8266 architecture

# -------------------------------------------------
#

include $(TOPDIR)/include/esp8266/variants.inc

APP_LD_SCRIPT ?= $(ARCH_INCLUDE_DIR)/ld/$(BOARD_LD_SCRIPT_$(TARGET_BOARD))
LDFLAGS += -T$(APP_LD_SCRIPT) -g -Os -nostdlib -Wl,--no-check-sections -Wl,--gc-sections -Wl,-static

LIBDIRS += $(ARCH_INCLUDE_DIR)/ld

CFLAGS += -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections
CPPFLAGS += -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections
ASMFLAGS += -c -g -x assembler-with-cpp -MMD -mlongcalls -mtext-section-literals
CDEFS += __esp8266__ __ets__ ICACHE_FLASH ESP8266 F_CPU=$(TARGET_CPU_SPEED)
OBJCOPYDEFS += -O elf32-xtensa-le -B xtensa --rename-section .data=.irom0.other

# ----------------------------------------------------------------------------------------
# Architecture-specific Library Steps

define esp8266_post_lib
endef

# ----------------------------------------------------------------------------------------
# Architecture-specific Application Steps

# esp8266_post_app(app_out_file)
# Note: this step assumes the linker definition file places all flash code (.irom0.text section) at flash address 0x10000
define esp8266_post_app
	$(ESPTOOL) -bz $(TARGET_FLASH_SIZE) -bf $(TARGET_FLASH_SPEED) -bm $(TARGET_FLASH_MODE) -eo $1 -bo $(dir $1)0x00000.bin -bs .text -bs .data -bs .rodata -bc -ec
	$(OBJCOPY) --only-section .irom0.text -O binary $1 $(dir $1)irom0.bin
	$(OBJCOPY) --only-section .irom0.other -O binary $1 $(dir $1)other.bin
	python $(ARCH_INCLUDE_DIR)/append.py $(dir $1)irom0.bin $(dir $1)other.bin $(dir $1)0x10000.bin
	python $(ARCH_INCLUDE_DIR)/pad.py $(dir $1)0x00000.bin $(dir $1)a.bin 65536
	python $(ARCH_INCLUDE_DIR)/append.py $(dir $1)a.bin $(dir $1)0x10000.bin $(dir $1)user1.bin
	rm -f $(dir $1)a.bin
endef

# esp8266_app_info(app_file,app_dir)
define esp8266_app_info
	$(OBJDUMP) -h -j .data -j .rodata -j .bss -j .text -j .irom0.text -j .iram.text $2/$1
endef

# esp8266_app_flash(app_file,app_dir)
define esp8266_app_flash
	$(ECHO) "Flashing on port $(TARGET_PORT) @ $(TARGET_BAUD)"
	$(ESPTOOL) -cp $(TARGET_PORT) -cd $(TARGET_BOARD) -cb $(TARGET_BAUD) $(foreach file,$(wildcard $2/0x*.bin),-ca $(notdir $(basename $(file))) -cf $(file))
endef

# ----------------------------------------------------------------------------------------
# Other

# esp8266_checkboard(app_file,app_dir)
define esp8266_checkboard(app_file,app_dir)
	ifeq ($(BOARD_LD_SCRIPT_$(TARGET_BOARD)),)
	$(error "Invalid board type specification ($(TARGET_BOARD))")
	endif
endef

# vim: syntax=make tabstop=4 noexpandtab
