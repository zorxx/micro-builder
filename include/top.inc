# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief file to be included at the top of each GNU makefile
# This file contains a wide variety of definitions (directories, tools, compiler/linker
#  definitions, etc.). Any of the definitions in this file can be overridden (or appended-to)
#  by the calling makefile.

# Directories
TOPDIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/..
EXAMPLES_DIR := $(TOPDIR)/examples
INCLUDE_DIR := $(TOPDIR)/include
LIBRARIES_DIR := $(TOPDIR)/lib
PACKAGE_DIR := $(TOPDIR)/package

# Host tools
WGET	:= wget
MKDIR	:= mkdir
RM		:= rm
CD		:= cd
UNZIP	:= unzip
TAR		:= tar
GIT		:= git
PYTHON	:= python
ECHO	:= echo
TOUCH	:= touch
DATE	:= date
PATCH	:= patch

# Top-level configuration, needed first in order to determine TARGET_ARCH
include $(TOPDIR)/config.inc

# Include any archiecture-specific configuration
ARCH_INCLUDE_DIR := $(INCLUDE_DIR)/$(TARGET_ARCH)
-include $(TOPDIR)/include/$(TARGET_ARCH)/$(TARGET_ARCH)_top.inc

# Host tools
CC		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)gcc
AR		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)ar
LD		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)gcc
OBJCOPY	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)objcopy
OBJDUMP	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)objdump
                                                                
# -----------------------------------------------------------------------
# Compilation

BUILD_TEMP_DIR := ./build
COMMON_CFLAGS := -Os -g -O2 -Wpointer-arith -Wundef -Werror -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -mno-serialize-volatile
CFLAGS += $(COMMON_CFLAGS)
CPPFLAGS += $(COMMON_CFLAGS)
CDEFS += 
INCDIR += . include $(TOPDIR)/lib $(TOPDIR)/include $(ARCH_INCLUDE_DIR)

# ----------------------------------------------------------------------------------------
# Library

LIB_BIN_DIR := $(LIBRARIES_DIR)/bin

# ----------------------------------------------------------------------------------------
# Application

LDFLAGS += -nostdlib -Wl,--no-check-sections -u call_user_start -Wl,-static
LIBDIRS += $(LIB_BIN_DIR)

# vim: syntax=make tabstop=4 noexpandtab
