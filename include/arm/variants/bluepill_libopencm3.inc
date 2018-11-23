# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief STM32F1 "blue pill" LibOpenCM3 variant 

PREREQS ?= package/arm/toolchain package/arm/libopencm3 package/stm32/stlink

DEVICE := stm32f103c6

# This must be last
include $(INCLUDE_DIR)/arm/stm32/stm32f1/stm32f1.inc
include $(PACKAGE_DIR)/arm/libopencm3/libopencm3.inc

# vim: syntax=make tabstop=4 noexpandtab
