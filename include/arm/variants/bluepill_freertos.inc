# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief STM32F1 "blue pill" LibOpenCM3/FreeRTOS variant 

PREREQS ?= package/arm/toolchain package/arm/libopencm3 package/common/freertos \
           package/stm32/stlink

DEVICE := stm32f103c8

# freertos
FREERTOS_COMPILER = GCC
FREERTOS_ARCH = ARM_CM3
FREERTOS_HEAP_TYPE = 2
INCDIR += $(INCLUDE_DIR)/arm/stm32/stm32f1

# This must be last
include $(INCLUDE_DIR)/arm/stm32/stm32.inc
include $(PACKAGE_DIR)/arm/libopencm3/libopencm3.inc

# vim: syntax=make tabstop=4 noexpandtab
