# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief STM32F030 LibOpenCM3 variant 

PREREQS ?= package/arm/toolchain package/arm/libopencm3 package/stm32/stlink

DEVICE := stm32f030f4

# This must be last
include $(INCLUDE_DIR)/arm/libopencm3.inc 

# vim: syntax=make tabstop=4 noexpandtab