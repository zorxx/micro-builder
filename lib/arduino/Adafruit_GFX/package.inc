# \copyright 2016-2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino Adafruit_GFX library package build environment

ADAFRUIT_GFX_LIB_DIR := $(LIBRARIES_DIR)/arduino/Adafruit_GFX/Adafruit_GFX_source
INCDIR += $(ADAFRUIT_GFX_LIB_DIR) $(ADAFRUIT_GFX_LIB_DIR)/Fonts
LIBS += Adafruit_GFX

# vim: syntax=make tabstop=4 noexpandtab
