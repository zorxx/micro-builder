#\copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment configuration for STM32F1 Arduino package

ARDUINO_DIR := $(PACKAGE_DIR)/stm32/stm32f1_arduino/arduino_source
ARDUINO_TARGET_CPU_DIR := $(ARDUINO_DIR)/STM32F1
ARDUINO_LIB_DIR := $(ARDUINO_TARGET_CPU_DIR)/libraries

-include $(ARDUINO_TARGET_CPU_DIR)/boards.txt

APP_LD_DIR := $(ARDUINO_TARGET_CPU_DIR)/variants/$(STM32_VARIANT)/ld

STM32_CFLAGS += $($(STM32_BOARD).build.cpu_flags)
STM32_CFLAGS += $($(STM32_BOARD).build.extra_flags)
STM32_CFLAGS += -DRAMEND=0
ifneq ($($(STM32_VARIANT).build.vect_flags),)
STM32_CFLAGS += "$($(STM32_VARIANT).build.vect_flags)"
endif

CFLAGS += $(STM32_CFLAGS)
CPPFLAGS += $(STM32_CFLAGS)
LDFLAGS += -Wl,--undefined=end

INCDIR += $(ARDUINO_TARGET_CPU_DIR)/cores/maple
INCDIR += $(ARDUINO_TARGET_CPU_DIR)/system/libmaple
INCDIR += $(ARDUINO_TARGET_CPU_DIR)/system/libmaple/include
INCDIR += $(ARDUINO_TARGET_CPU_DIR)/system/libmaple/usb/stm32f1
INCDIR += $(ARDUINO_TARGET_CPU_DIR)/system/libmaple/usb/usb_lib
INCDIR += $(ARDUINO_TARGET_CPU_DIR)/cores/maple/avr
INCDIR += $(ARDUINO_TARGET_CPU_DIR)/variants/$(STM32_VARIANT)
INCDIR += $(ARDUINO_LIB_DIR)/EEPROM/src
INCDIR += $(ARDUINO_LIB_DIR)/RTClock/src
INCDIR += $(ARDUINO_LIB_DIR)/SPI/src
INCDIR += $(ARDUINO_LIB_DIR)/Wire
INCDIR += $(ARDUINO_LIB_DIR)/Wire/utility

LIBS += arduino_core arduino_Wire arduino_EEPROM arduino_SPI arduino_RTClock

# vim: syntax=make tabstop=4 noexpandtab
