# \copyright 2015-2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level configuration, including target architecture, and selected packages

# Target architecture
# Valid options:
#   esp8266
TARGET_ARCH ?= esp8266

TARGET_BOARD ?= nodemcu

# Toolchain and SDK from ESP8266/Arduino Project
PACKAGES ?= esp8266/arduino_toolchain esp8266/esptool esp8266/arduino common/OneWire common/TemperatureControl

# Toolchain from ESP8266/Arduino project, Raw ESP8266 SDK
#PACKAGES ?= esp8266/arduino_toolchain esp8266/esptool esp8266/esp8266_sdk

# vim: syntax=make tabstop=4 noexpandtab
