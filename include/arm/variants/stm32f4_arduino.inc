# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief STM32F4 variant 

PREREQS ?= package/arm/toolchain package/stm32/stm32f4_arduino package/stm32/stlink

STM32_CPU := STM32F4
STM32_BOARD := generic_f407v
STM32_VARIANT = $($(STM32_BOARD).build.variant)

TARGET_CPU := cortex-m4
TARGET_CPU_SPEED := 16000000

APP_LD_SCRIPT = $(APP_LD_DIR)/jtag.ld

# This must be last
include $(INCLUDE_DIR)/arm/stm32/stm32.inc 

# vim: syntax=make tabstop=4 noexpandtab
