# \copyright 2016-2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino Adafruit_ILI9340 library package build environment

ADAFRUIT_ILI9340_LIB_DIR := $(LIBRARIES_DIR)/arduino/Adafruit_ILI9340/Adafruit_ILI9340_source
INCDIR += $(ADAFRUIT_ILI9340_LIB_DIR)
LIBS += Adafruit_ILI9340

# vim: syntax=make tabstop=4 noexpandtab
