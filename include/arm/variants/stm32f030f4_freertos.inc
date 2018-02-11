# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief STM32F030 FreeRTOS variant 

PREREQS ?= package/arm/toolchain package/arm/libopencm3 package/stm32/stlink package/common/freertos

# libopencm3
DEVICE := stm32f030f4
TARGET_CPU_SPEED := 72000000

# freertos
FREERTOS_COMPILER = GCC
FREERTOS_ARCH = ARM_CM0
FREERTOS_HEAP_TYPE = 2
INCDIR += $(INCLUDE_DIR)/arm/stm32/stm32f0

# This must be last
include $(INCLUDE_DIR)/arm/libopencm3.inc 

# vim: syntax=make tabstop=4 noexpandtab
