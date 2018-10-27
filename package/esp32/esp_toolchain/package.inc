# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment configuration for ESP32 Xtensa toolchain

TOOLCHAIN_DIR := $(PACKAGE_DIR)/esp32/esp_toolchain/esp_toolchain_source/xtensa-esp32-elf
TOOLCHAIN_BIN_DIR := $(TOOLCHAIN_DIR)/bin
TOOLCHAIN_PREFIX := xtensa-esp32-elf-

CC	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)gcc
CXX	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)g++
AR	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)ar
LD	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)g++
OBJCOPY	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)objcopy
OBJDUMP	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)objdump
READELF	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)readelf
STRIP	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)strip

export PATH := $(PATH):$(TOOLCHAIN_BIN_DIR)

# vim: syntax=make tabstop=4 noexpandtab
