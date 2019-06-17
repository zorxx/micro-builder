# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266/ESP32 ws2812_i2s Library

WS2812_I2S_LIB_DIR := $(LIBRARIES_DIR)/esp8266/ws2812_i2s/ws2812_i2s_source/include
INCDIR += $(WS2812_I2S_LIB_DIR)
LIBS += ws2812_i2s

# vim: syntax=make tabstop=4 noexpandtab
