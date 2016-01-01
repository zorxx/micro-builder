# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief ESP8266 Arduino package build environment

ESP8266_ARDUINO_DIR := $(PACKAGE_DIR)/esp8266/esp8266_arduino/source

INCDIR += $(ESP8266_ARDUINO_DIR)/cores/esp8266 $(ESP8266_ARDUINO_DIR)/variants/$(TARGET_BOARD)

# vim: syntax=make tabstop=4 noexpandtab
