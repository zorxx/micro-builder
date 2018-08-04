# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment configuration for ESP8266 toolchain

ESP8266_TOOLCHAIN_DIR := $(PACKAGE_DIR)/esp8266/toolchain
TOOLCHAIN_DIR := $(ESP8266_TOOLCHAIN_DIR)/toolchain_source/xtensa-lx106-elf
TOOLCHAIN_BIN_DIR := $(TOOLCHAIN_DIR)/bin
TOOLCHAIN_PREFIX := xtensa-lx106-elf-

# Don't use any of these settings while building the toolchain itself
ifneq ($(CURDIR),$(ESP8266_TOOLCHAIN_DIR))
$(info Including target build definitions)
CC	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)gcc
CXX	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)g++
AR	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)ar
LD	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)g++
OBJCOPY	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)objcopy
OBJDUMP	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)objdump
READELF	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)readelf
STRIP	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)strip
export PATH := $(PATH):$(TOOLCHAIN_BIN_DIR)
endif

# vim: syntax=make tabstop=4 noexpandtab
