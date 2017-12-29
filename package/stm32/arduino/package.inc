# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment configuration for STM32 Arduino package

ARDUINO_DIR := $(PACKAGE_DIR)/stm32/arduino/arduino_source/Arduino_STM32-master/$(STM32_CPU)
STM32F1_LIB_DIR := $(PACKAGE_DIR)/stm32/arduino/arduino_source/Arduino_STM32-master/STM32F1/libraries

include $(ARDUINO_DIR)/boards.txt

ARDUINO_COMMON_LIBRARIES_DIR := $(ARDUINO_DIR)/libraries

APP_LD_DIR := $(ARDUINO_DIR)/variants/$(STM32_VARIANT)/ld
APP_LD_SCRIPT := $(APP_LD_DIR)/flash.ld
CFLAGS += -D__$(STM32_CPU)__ $($(STM32_VARIANT).build.extra_flags) "$($(STM32_VARIANT).build.vect_flags)"
CPPFLAGS += -D__$(STM32_CPU)__ $($(STM32_VARIANT).build.extra_flags) "$($(STM32_VARIANT).build.vect_flags)"

INCDIR += $(ARDUINO_DIR)/cores/maple $(ARDUINO_DIR)/cores/maple/avr
INCDIR += $(ARDUINO_DIR)/cores/maple/libmaple $(ARDUINO_DIR)/system/libmaple
INCDIR += $(ARDUINO_DIR)/cores/maple/libmaple/usbF4
INCDIR += $(ARDUINO_DIR)/variants/$(STM32_VARIANT)
INCDIR += $(AVR_LIBRARIES_DIR)/SoftwareSerial/src
INCDIR += $(AVR_LIBRARIES_DIR)/SPI/src
INCDIR += $(AVR_LIBRARIES_DIR)/Wire/src $(AVR_LIBRARIES_DIR)/Wire/utility
INCDIR += $(AVR_LIBRARIES_DIR)/HID/src
INCDIR += $(AVR_LIBRARIES_DIR)/EEPROM/src
INCDIR += $(ARDUINO_COMMON_LIBRARIES_DIR)/arduino_uip
INCDIR += $(ARDUINO_COMMON_LIBRARIES_DIR)/RTClock/src
INCDIR += $(ARDUINO_COMMON_LIBRARIES_DIR)/SDIO
INCDIR += $(ARDUINO_COMMON_LIBRARIES_DIR)/SPI/src
INCDIR += $(STM32F1_LIB_DIR)/Wire

# vim: syntax=make tabstop=4 noexpandtab
