#\copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment configuration for STM32F1 Arduino package

ARDUINO_DIR := $(PACKAGE_DIR)/stm32/stm32f4_arduino/arduino_source
ARDUINO_TARGET_CPU_DIR := $(ARDUINO_DIR)/STM32F4
ARDUINO_COMMON_DIR := $(ARDUINO_DIR)/STM32F1
ARDUINO_LIB_DIR := $(ARDUINO_TARGET_CPU_DIR)/libraries
ARDUINO_COMMON_LIB_DIR := $(ARDUINO_COMMON_DIR)/libraries

-include $(ARDUINO_TARGET_CPU_DIR)/boards.txt

APP_LD_DIR := $(ARDUINO_TARGET_CPU_DIR)/variants/$(STM32_VARIANT)/ld

STM32_CFLAGS += $($(STM32_BOARD).build.cpu_flags)
STM32_CFLAGS += $($(STM32_BOARD).build.extra_flags)
STM32_CFLAGS += -DVARIANT_$(STM32_BOARD) 
ifneq ($($(STM32_VARIANT).build.vect_flags),)
STM32_CFLAGS += "$($(STM32_VARIANT).build.vect_flags)"
endif

CFLAGS += $(STM32_CFLAGS)
CPPFLAGS += $(STM32_CFLAGS)

INCDIR += $(ARDUINO_TARGET_CPU_DIR)/cores/maple
INCDIR += $(ARDUINO_TARGET_CPU_DIR)/cores/maple/avr
INCDIR += $(ARDUINO_TARGET_CPU_DIR)/cores/maple/libmaple
INCDIR += $(ARDUINO_TARGET_CPU_DIR)/cores/maple/libmaple/usbF4
INCDIR += $(ARDUINO_TARGET_CPU_DIR)/system/libmaple
INCDIR += $(ARDUINO_TARGET_CPU_DIR)/variants/$(STM32_VARIANT)
INCDIR += $(ARDUINO_LIB_DIR)/arduino_uip $(ARDUINO_LIB_DIR)/arduino_uip/utility
INCDIR += $(ARDUINO_LIB_DIR)/RTClock/src
INCDIR += $(ARDUINO_LIB_DIR)/SPI/src
INCDIR += $(ARDUINO_COMMON_LIB_DIR)/EEPROM/src
INCDIR += $(ARDUINO_COMMON_LIB_DIR)/Wire/src
INCDIR += $(ARDUINO_COMMON_LIB_DIR)/Wire/utility/src

LIBS += arduino_core arduino_uip arduino_SPI arduino_RTClock

# vim: syntax=make tabstop=4 noexpandtab
