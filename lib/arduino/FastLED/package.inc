# \copyright 2019 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino FastLED Library package build environment

FASTLED_LIB_DIR := $(LIBRARIES_DIR)/arduino/FastLED/FastLED_source
INCDIR += $(FASTLED_LIB_DIR)
LIBS += FastLED

# vim: syntax=make tabstop=4 noexpandtab
