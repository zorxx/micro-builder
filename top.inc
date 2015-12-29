# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief file to be included at the top of each GNU makefile
# This file contains a wide variety of definitions (directories, tools, compiler/linker
#  definitions, etc.). Any of the definitions in this file can be overridden (or appended-to)
#  by the calling makefile.

TOPDIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
include $(TOPDIR)/user.inc
include $(TOPDIR)/variant.inc

TOOLCHAIN_DIR := C:\SysGCC\esp8266
TOOLCHAIN_BIN_DIR := $(TOOLCHAIN_DIR)\bin
TOOLCHAIN_HAL_DIR := $(TOOLCHAIN_DIR)\HAL
TOOLCHAIN_PREFIX := xtensa-lx106-elf-

# Host tools
WGET := wget
MKDIR := mkdir
RM := rm
CD := cd
UNZIP := unzip
GIT := git
PYTHON := python
ECHO := echo

# Directories
SDK_DIR := $(TOPDIR)/sdk
TOOLS_DIR := $(TOPDIR)/tools
EXAMPLES_DIR := $(TOPDIR)/examples
LIBRARIES_DIR := $(TOPDIR)/lib

# ----------------------------------------------------------------------------------------
# Espressif SDKs

# ESP8266 NORTOS SDK
ESP8266_SDK_VERSION := 1.5.0
ESP8266_SDK_SOURCE := "http://bbs.espressif.com/download/file.php?id=989"
ESP8266_SDK_INSTALL_DIR := $(SDK_DIR)/esp8266
ESP8266_SDK_DIR := $(ESP8266_SDK_INSTALL_DIR)/esp_iot_sdk_v$(ESP8266_SDK_VERSION)
ESP8266_LD_DIR := $(ESP8266_SDK_DIR)/ld

# ESP8266 RTOS SDK
# TODO

# ----------------------------------------------------------------------------------------
# Espressif Tools

ESPTOOL_SOURCE := "https://github.com/themadinventor/esptool.git"
ESPTOOL_DIR := $(TOOLS_DIR)/esptool
ESPTOOL := python $(ESPTOOL_DIR)/esptool.py

CC	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)gcc
AR	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)ar
LD	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)gcc
OBJCOPY := $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)objcopy
OBJDUMP := $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)objdump

# -----------------------------------------------------------------------
# ESP8266/Arduino Libraries

ESP8266_ARDUINO_SOURCE := "https://github.com/esp8266/Arduino.git"
ESP8266_ARDUINO_DIR := $(TOPDIR)/arduino
ESP8266_ARDUINO_INSTALL_DIR := $(ESP8266_ARDUINO_DIR)/dist
ESP8266_ARDUINO_SDK_DIR := $(ESP8266_ARDUINO_INSTALL_DIR)/tools/sdk

# -----------------------------------------------------------------------
# Compilation

BUILD_TEMP_DIR := ./build
COMMON_CFLAGS := -Os -g -O2 -Wpointer-arith -Wundef -Werror -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -mno-serialize-volatile
CFLAGS := $(COMMON_CFLAGS)
CPPFLAGS := $(COMMON_CFLAGS)
CDEFS := __ets__ ICACHE_FLASH
INCDIR := . include $(ESP8266_SDK_DIR)/include $(ESP8266_SDK_DIR)/include/json $(TOPDIR)/lib $(TOPDIR)/include

# ----------------------------------------------------------------------------------------
# Library

LIB_BIN_DIR := $(LIBRARIES_DIR)/bin

# ----------------------------------------------------------------------------------------
# Application

LDFLAGS := -nostdlib -Wl,--no-check-sections -u call_user_start -Wl,-static
LIBDIRS := $(LIB_BIN_DIR) $(ESP8266_SDK_DIR)/lib $(ESP8266_ARDUINO_SDK_DIR)/ld $(TOOLCHAIN_HAL_DIR)
APP_LD_SCRIPT := $(ESP8266_ARDUINO_SDK_DIR)/ld/$(BOARD_LD_SCRIPT_$(TARGET_BOARD))

