# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level configuration, including target architecture, and selected packages

# Target architecture
# Valid options:
#   esp8266
TARGET_ARCH ?= esp8266

TARGET_BOARD ?= nodemcu

# Note: case-sensitive, downloaded and built in-order
PACKAGES ?= esp8266_sysgcc_toolchain esp8266_sdk esp8266_esptool esp8266_arduino OneWire

# vim: syntax=make tabstop=4 noexpandtab