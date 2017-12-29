# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief STM32F4 variant 

PREREQS ?= package/arm/toolchain package/stm32/arduino

STM32_CPU := STM32F4
STM32_VARIANT := generic_f407v

TARGET_CPU := corex_m0
TARGET_CPU_SPEED := 16000000

# This must be last
include $(INCLUDE_DIR)/arm/stm32/stm32.inc 

# vim: syntax=make tabstop=4 noexpandtab
