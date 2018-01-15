# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Generic STM32F103C board variant 

PREREQS := package/arm/toolchain package/stm32/stm32f1_arduino package/stm32/stlink
#PREREQS := package/arm/linaro_toolchain package/stm32/stm32f1_arduino package/stm32/stlink

STM32_CPU := STM32F1
STM32_BOARD := genericSTM32F103C
STM32_VARIANT = $($(STM32_BOARD).build.variant)

TARGET_CPU := cortex-m3
TARGET_CPU_SPEED := 72000000

VARIANT_FLAGS := -DVECT_TAB_ADDR=0x8000000 -DMCU_STM32F103C8 -DBOARD_generic_stm32f103c -DGENERIC_BOOTLOADER -D__STM32F1__

CFLAGS += $(VARIANT_FLAGS)
CPPFLAGS += $(VARIANT_FLAGS) 
ASMFLAGS += $(VARIANT_FLAGS) 

APP_LD_SCRIPT = $(APP_LD_DIR)/jtag_c8.ld

# This must be last
include $(INCLUDE_DIR)/arm/stm32/stm32.inc 
include $(INCLUDE_DIR)/arm/stm32/stm32f1.inc 

# vim: syntax=make tabstop=4 noexpandtab
