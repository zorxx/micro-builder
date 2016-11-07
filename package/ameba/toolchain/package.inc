# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment configuration for Ameba toolchain

TOOLCHAIN_DIR := $(PACKAGE_DIR)/ameba/toolchain/toolchain_source/gcc-linaro-5.3.1-2016.05-x86_64_arm-eabi
TOOLCHAIN_BIN_DIR := $(TOOLCHAIN_DIR)/bin
TOOLCHAIN_PREFIX := arm-eabi-

CC		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)gcc
CXX		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)g++
AR		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)ar
LD		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)g++
OBJCOPY	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)objcopy
OBJDUMP	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)objdump
READELF	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)readelf

export PATH := $(PATH):$(TOOLCHAIN_BIN_DIR)

# vim: syntax=make tabstop=4 noexpandtab
