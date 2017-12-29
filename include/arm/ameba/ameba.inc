# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top make include file for Ameba architecture

# -------------------------------------------------
#

LDFLAGS += -T$(APP_LD_SCRIPT) -g -Os -mcpu=cortex-m3 -mthumb -flto -Wl,--no-check-sections -Wl,--cref -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-commo

LIBDIRS += $(ARCH_INCLUDE_DIR)/ld

COMMON_CFLAGS = -Os -g -Wpointer-arith -Wundef -Wno-write-strings -Wl,-EL -fno-inline-functions -falign-functions=4 -MMD -ffunction-sections -fdata-sections -fno-common -fmessage-length=0 -fno-exceptions -fomit-frame-pointer
CFLAGS += $(COMMON_CFLAGS) -Wstrict-prototypes -std=gnu99
CPPFLAGS += $(COMMON_CFLAGS) 

ASMFLAGS += -mcpu=cortex-m3 -mthumb -c -g -x assembler-with-cpp -MMD
CDEFS += _LONG_CALL_ROM_= __IASMARM__=1 F_CPU=$(TARGET_CPU_SPEED)
CDEFS += CONFIG_CHIP_E_CUT=1
CDEFS += LWIP_TIMEVAL_PRIVATE=0
OBJCOPYDEFS += -O elf32-le -B arm

# ----------------------------------------------------------------------------------------
# Architecture-specific Library Steps

define ameba_post_lib
endef

# ----------------------------------------------------------------------------------------
# Architecture-specific Application Steps

# ameba_post_app(app_out_file)
define ameba_post_app
endef

# ameba_app_info(app_file,app_dir)
define ameba_app_info
	$(OBJDUMP) -h -j .data -j .rodata -j .bss -j .text -j .irom0.text -j .iram.text $2/$1
endef

# ameba_app_flash(app_file,app_dir)
define ameba_app_flash
	$(ECHO) "Flashing on port $(TARGET_PORT) @ $(TARGET_BAUD)"
endef

# ----------------------------------------------------------------------------------------
# Other

# ameba_checkboard(app_file,app_dir)
define ameba_checkboard(app_file,app_dir)
	ifeq ($(BOARD_LD_SCRIPT_$(TARGET_BOARD)),)
	$(error "Invalid board type specification ($(TARGET_BOARD))")
	endif
endef

# vim: syntax=make tabstop=4 noexpandtab
