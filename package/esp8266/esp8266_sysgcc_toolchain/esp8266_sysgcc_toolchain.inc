# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment configuration for sysgcc ESP8266 toolchain

TOOLCHAIN_DIR := C:\SysGCC\esp8266
TOOLCHAIN_BIN_DIR := $(TOOLCHAIN_DIR)\bin
TOOLCHAIN_HAL_DIR := $(TOOLCHAIN_DIR)\HAL
TOOLCHAIN_PREFIX := xtensa-lx106-elf-

LIBDIRS += $(TOOLCHAIN_HAL_DIR)

CC		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)gcc
AR		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)ar
LD		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)gcc
OBJCOPY	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)objcopy
OBJDUMP	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)objdump

# vim: syntax=make tabstop=4 noexpandtab
