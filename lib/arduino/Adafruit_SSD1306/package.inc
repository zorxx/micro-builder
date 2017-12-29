# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Adafruit_SSD1306 0.96" OLED Display build environment

ADAFRUIT_SSD1306_LIB_DIR := $(LIBRARIES_DIR)/arduino/Adafruit_SSD1306/Adafruit_SSD1306_source
INCDIR += $(ADAFRUIT_SSD1306_LIB_DIR)
LIBS += Adafruit_SSD1306

# vim: syntax=make tabstop=4 noexpandtab
