# \copyright 2015-2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level configuration, including target architecture, and selected packages

# Target architecture
# Valid options:
#   esp8266
TARGET_ARCH ?= esp8266

TARGET_BOARD ?= nodemcu

# Toolchain and SDK from ESP8266/Arduino Project
PREREQS ?= package/esp8266/arduino_toolchain package/esp8266/esptool package/esp8266/arduino

# Toolchain from ESP8266/Arduino project, Raw ESP8266 SDK
#PREREQS ?= package/esp8266/arduino_toolchain package/esp8266/esptool package/esp8266/esp8266_sdk

# vim: syntax=make tabstop=4 noexpandtab
