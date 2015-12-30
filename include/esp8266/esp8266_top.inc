# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Settings specific to hardware variants

# Target board type
# Valid options:
#   adafruit
#   nodemcu
TARGET_BOARD ?= nodemcu

# Serial port and baud rate for programming (flashing)
TARGET_PORT ?= COM14
TARGET_BAUD ?= 256000

# TODO: Implement SPI flash filesystem support, with configuration

# -------------------------------------------------
#

include $(TOPDIR)/include/esp8266/variants.inc
include $(TOPDIR)/include/esp8266/externals.inc

TOOLCHAIN_DIR := C:\SysGCC\esp8266
TOOLCHAIN_BIN_DIR := $(TOOLCHAIN_DIR)\bin
TOOLCHAIN_HAL_DIR := $(TOOLCHAIN_DIR)\HAL
TOOLCHAIN_PREFIX := xtensa-lx106-elf-

INCDIR := $(ESP8266_SDK_DIR)/include $(ESP8266_SDK_DIR)/include/json 
LIBDIRS := $(ESP8266_SDK_DIR)/lib $(ESP8266_ARDUINO_SDK_DIR)/ld $(TOOLCHAIN_HAL_DIR)

APP_LD_SCRIPT := $(ESP8266_ARDUINO_SDK_DIR)/ld/$(BOARD_LD_SCRIPT_$(TARGET_BOARD))
LDFLAGS := -T$(APP_LD_SCRIPT)      

CFLAGS := 
CPPFLAGS :=
CDEFS := __ets__ ICACHE_FLASH

