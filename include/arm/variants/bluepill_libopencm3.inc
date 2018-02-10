# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief STM32F1 "blue pill" LibOpenCM3 variant 

PREREQS ?= package/arm/toolchain package/arm/libopencm3

TARGET_CPU_SPEED := 72000000
DEVICE := stm32f103c6

LIBS += opencm3_stm32f1
LIB_DIR += $(LIBOPENCM3_DIR)/lib

CFLAGS += $(VARIANT_FLAGS)
CPPFLAGS += $(VARIANT_FLAGS) 
ASMFLAGS += $(VARIANT_FLAGS) 

define arm_bluepill_libopencm3_APP_PREACTION
	$(call libopencm3_app_preaction)
endef

# This must be last
include $(INCLUDE_DIR)/arm/libopencm3.inc 
include $(INCLUDE_DIR)/arm/stm32/stm32.inc 

# vim: syntax=make tabstop=4 noexpandtab
