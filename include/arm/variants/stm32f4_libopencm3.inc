# \copyright 2017-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief STM32F4 variant 

PREREQS ?= package/arm/toolchain package/arm/libopencm3 package/stm32/stlink

DEVICE := stm32f401xe

CFLAGS += -mfloat-abi=hard
CPPFLAGS += -mfloat-abi=hard

# This must be last
include $(INCLUDE_DIR)/arm/stm32/stm32.inc 
include $(PACKAGE_DIR)/arm/libopencm3/libopencm3.inc 

# vim: syntax=make tabstop=4 noexpandtab
