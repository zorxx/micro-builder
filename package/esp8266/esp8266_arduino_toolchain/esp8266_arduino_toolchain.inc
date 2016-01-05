# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment configuration for ESP8266 Arduino toolchain

TOOLCHAIN_DIR := $(PACKAGE_DIR)/esp8266/esp8266_arduino_toolchain/source/xtensa-lx106-elf
TOOLCHAIN_BIN_DIR := $(TOOLCHAIN_DIR)/bin
TOOLCHAIN_PREFIX := xtensa-lx106-elf-

CC		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)gcc
CXX		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)g++
AR		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)ar
LD		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)g++
OBJCOPY	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)objcopy
OBJDUMP	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)objdump

export PATH := $(PATH):$(TOOLCHAIN_BIN_DIR)

# vim: syntax=make tabstop=4 noexpandtab
