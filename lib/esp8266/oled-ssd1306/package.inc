# \copyright 2017-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief ESP8266 SSD1306 0.96" OLED Display build environment

ESP8266_OLED_SSD1306_LIB_DIR := $(LIBRARIES_DIR)/esp8266/oled-ssd1306/esp8266_oled_ssd1306_source/src
INCDIR += $(ESP8266_OLED_SSD1306_LIB_DIR)
LIBS += esp8266_oled_ssd1306 

# vim: syntax=make tabstop=4 noexpandtab
