# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top make include file for STM32 architecture

# -------------------------------------------------
#

LDFLAGS += -L$(APP_LD_DIR) -T$(APP_LD_SCRIPT) -mthumb -mcpu=$(TARGET_CPU) -flto -specs=nosys.specs -Wl,--check-sections -Wl,--cref -Wl,--gc-sections -Wl,--unresolved-symbols=report-all

LIBDIRS += $(ARCH_INCLUDE_DIR)/ld

COMMON_CFLAGS = -Os -g -mthumb -mcpu=$(TARGET_CPU) -nostdlib -Wpointer-arith -Wundef -Wno-write-strings -Wl,-EL --param max-inline-insns-single=500 -MMD -ffunction-sections -fdata-sections
CFLAGS += $(COMMON_CFLAGS) -Wstrict-prototypes -std=gnu11
CPPFLAGS += $(COMMON_CFLAGS) -std=gnu++11 -fno-rtti -fno-exceptions 

ASMFLAGS += -mcpu=$(TARGET_CPU) -mthumb -c -g -x assembler-with-cpp -MMD
CDEFS += F_CPU=$(TARGET_CPU_SPEED)L
OBJCOPYDEFS += -O elf32-le -B arm

# ----------------------------------------------------------------------------------------
# Architecture-specific Library Steps

define $(MB_TARGET)_post_lib
endef

# ----------------------------------------------------------------------------------------
# Architecture-specific Application Steps

# stm32_post_app(app_out_file)
define $(MB_TARGET)_post_app
	$(OBJCOPY) -O binary $1 $(basename $1).bin
endef

# stm32_app_info(app_file,app_dir)
define $(MB_TARGET)_app_info
	$(OBJDUMP) -h -j .data -j .rodata -j .bss -j .text -j .irom0.text -j .iram.text $2/$1
endef

# stm32_app_flash(app_file,app_dir)
define $(MB_TARGET)_app_flash
	$(ECHO) "Flashing $(basename $1).bin"
	cd $2;$(STFLASH) write $(basename $1).bin 0x8000000
endef

# ----------------------------------------------------------------------------------------
# Other

# stm32_checkboard(app_file,app_dir)
define $(MB_TARGET)_checkboard(app_file,app_dir)
	ifeq ($(BOARD_LD_SCRIPT_$(TARGET_BOARD)),)
	$(error "Invalid board type specification ($(TARGET_BOARD))")
	endif
endef

# vim: syntax=make tabstop=4 noexpandtab
