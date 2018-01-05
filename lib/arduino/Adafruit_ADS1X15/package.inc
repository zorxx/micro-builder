# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino ADS1X15 ADC Library package build environment

ADS1X15_LIB_DIR := $(LIBRARIES_DIR)/arduino/Adafruit_ADS1X15/Adafruit_ADS1X15_source
INCDIR += $(ADS1X15_LIB_DIR)
LIBS += Adafruit_ADS1X15

# vim: syntax=make tabstop=4 noexpandtab
