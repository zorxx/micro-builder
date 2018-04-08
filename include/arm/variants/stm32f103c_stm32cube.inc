# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Generic STM32F103C board variant for STM32cube 

PREREQS := package/arm/linaro_toolchain package/stm32/stm32cube package/stm32/stlink

STM32_FAMILY := F1
STM32_CPU := STM32F103xB
STM32_BOARD := STM3210C_EVAL
STM32CUBE_BSP := STM3210C_EVAL

TARGET_CPU := cortex-m3
TARGET_CPU_SPEED := 72000000

VARIANT_FLAGS := -D${STM32_CPU} -D__STM32${STM32_FAMILY}__

INCDIR += $(INCLUDE_DIR)/arm/stm32/stm32f103c/stm32cube
INCDIR += ./package/stm32/stm32cube/stm32cube_source/Drivers/BSP 

CFLAGS += $(VARIANT_FLAGS)
CPPFLAGS += $(VARIANT_FLAGS) 
ASMFLAGS += $(VARIANT_FLAGS) 

# This must be last
include $(INCLUDE_DIR)/arm/stm32/stm32f1/stm32f1.inc 
include $(INCLUDE_DIR)/arm/stm32/stm32.inc 

# vim: syntax=make tabstop=4 noexpandtab
