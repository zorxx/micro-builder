# \copyright 2015-2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level configuration, including target architecture, and selected packages

# Target architecture
# Valid options:
#   esp8266
#   avr
#   ameba
TARGET_ARCH ?= esp8266

TARGET_ARCH := $(strip $(TARGET_ARCH))

# -----------------------------------------------------------------------------------------------
# Ameba Examples

ifeq ($(TARGET_ARCH),ameba)

TARGET_CPU ?= corex_m0
TARGET_CPU_SPEED ?= 16000000

TARGET_PORT ?= /dev/ttyUSB0
TARGET_BAUD ?= 57600

PREREQS ?= package/ameba/toolchain package/ameba/sdk

endif # ameba

# -----------------------------------------------------------------------------------------------
# ESP8266 Examples

ifeq ($(TARGET_ARCH),esp8266)

# Target board type
# Valid options:
#   adafruit
#   nodemcu
TARGET_BOARD ?= nodemcu

# Serial port and baud rate for programming (flashing)
TARGET_PORT ?= /dev/ttyUSB0
TARGET_BAUD ?= 230400

# qio|qout|dio|dout
TARGET_FLASH_MODE ?= qio
# 512K|256K|1M|2M|4M|8M|16M|32M
TARGET_FLASH_SIZE ?= 4M
# 40|26|20|80
TARGET_FLASH_SPEED ?= 40
# none|ck|wifio|nodemcu
TARGET_RESET_METHOD ?= none

TARGET_CPU_SPEED ?= 80000000

# Toolchain and SDK from ESP8266/Arduino Project
#PREREQS ?= package/esp8266/arduino_toolchain package/esp8266/esptool package/esp8266/arduino

# Toolchain from ESP8266/Arduino project, Raw ESP8266 SDK
PREREQS ?= package/esp8266/arduino_toolchain package/esp8266/esptool package/esp8266/esp8266_sdk \
           package/esp8266/esp8266_sdk_extras

endif # esp8266

# -----------------------------------------------------------------------------------------------
# AVR Examples

ifeq ($(TARGET_ARCH),avr)

TARGET_CPU ?= ATmega328
TARGET_MCU ?= atmega328p
TARGET_CPU_SPEED ?= 16000000

TARGET_PORT ?= /dev/ttyUSB0
TARGET_BAUD ?= 57600

# AVR/Arduino
PREREQS ?= package/avr/arduino

endif # avr

# vim: syntax=make tabstop=4 noexpandtab
