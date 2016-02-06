# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment configuration for AVR Arduino package

AVR_HARDWARE_DIR := $(PACKAGE_DIR)/avr/arduino/arduino_source/arduino-nightly/hardware
AVR_LIBRARIES_DIR := $(AVR_HARDWARE_DIR)/arduino/avr/libraries
TOOLCHAIN_DIR := $(AVR_HARDWARE_DIR)/tools/avr
TOOLCHAIN_BIN_DIR := $(TOOLCHAIN_DIR)/bin
TOOLCHAIN_PREFIX := avr-

CC		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)gcc
CXX		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)g++
AR		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)ar
LD		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)g++
OBJCOPY	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)objcopy
OBJDUMP	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)objdump
READELF	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)readelf
AVRDUDE	:= $(TOOLCHAIN_BIN_DIR)/avrdude 

export PATH := $(PATH):$(TOOLCHAIN_BIN_DIR)
INCDIR += $(TOOLCHAIN_DIR) $(AVR_HARDWARE_DIR)/arduino/avr/variants/standard \
 $(AVR_HARDWARE_DIR)/arduino/avr/cores/arduino
INCDIR += $(AVR_LIBRARIES_DIR)/SoftwareSerial
INCDIR += $(AVR_LIBRARIES_DIR)/SPI
INCDIR += $(AVR_LIBRARIES_DIR)/Wire $(AVR_LIBRARIES_DIR)/Wire/utility

CDEFS += ARDUINO_ARCH_AVR ARDUINO=10607

# vim: syntax=make tabstop=4 noexpandtab
