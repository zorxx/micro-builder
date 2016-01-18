# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top make include file for ESP8266 architecture

# Target board type
# Valid options:
#   adafruit
#   nodemcu
TARGET_BOARD ?= nodemcu

# Serial port and baud rate for programming (flashing)
TARGET_PORT ?= COM3
TARGET_BAUD ?= 230400

# qio|qout|dio|dout
TARGET_FLASH_MODE ?= qio
# 512K|256K|1M|2M|4M|8M|16M|32M
TARGET_FLASH_SIZE ?= 4M
# 40|26|20|80
TARGET_FLASH_SPEED ?= 40
# none|ck|wifio|nodemcu
TARGET_RESET_METHOD ?= nodemcu

# -------------------------------------------------
#

include $(TOPDIR)/include/esp8266/variants.inc

APP_LD_SCRIPT := $(ARCH_INCLUDE_DIR)/ld/$(BOARD_LD_SCRIPT_$(TARGET_BOARD))
LDFLAGS += -T$(APP_LD_SCRIPT) -g -Os -nostdlib -Wl,--no-check-sections -Wl,--gc-sections -Wl,-static -flto

LIBDIRS += $(ARCH_INCLUDE_DIR)/ld

CFLAGS += -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections 
CPPFLAGS += -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections
ASMFLAGS += -c -g -x assembler-with-cpp -MMD -mlongcalls -mtext-section-literals
CDEFS += __esp8266__ __ets__ ICACHE_FLASH

# ----------------------------------------------------------------------------------------
# Architecture-specific Library Steps

define esp8266_post_lib
endef

# ----------------------------------------------------------------------------------------
# Architecture-specific Application Steps

# esp8266_post_app(app_out_file)
# Note: this step assumes the linker definition file places all flash code (.irom0.text section) at flash address 0x10000
define esp8266_post_app
	$(ESPTOOL) -bz $(TARGET_FLASH_SIZE) -bf $(TARGET_FLASH_SPEED) -bm $(TARGET_FLASH_MODE) -eo $1 -bo $(dir $1)0x00000.bin -bs .text -bs .data -bs .rodata -bc -ec -eo $1 -es .irom0.text $(dir $1)0x10000.bin -ec
endef

# esp8266_app_info(app_file,app_dir)
define esp8266_app_info
	$(OBJDUMP) -h -j .data -j .rodata -j .bss -j .text -j .irom0.text -j .iram.text $2/$1
endef

# esp8266_app_flash(app_file,app_dir)
define esp8266_app_flash
	$(ECHO) "Flashing on port $(TARGET_PORT) @ $(TARGET_BAUD)"
	$(ESPTOOL) -cp $(TARGET_PORT) -cd $(TARGET_BOARD) -cb $(TARGET_BAUD) $(foreach file,$(wildcard $2/*.bin),-ca $(notdir $(basename $(file))) -cf $(file))
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
