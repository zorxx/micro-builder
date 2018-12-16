# \copyright 2016-2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino Debounced Input package build environment

DEBOUNCED_INPUT_LIB_DIR := $(LIBRARIES_DIR)/arduino/DebouncedInput/DebouncedInput_source/src
INCDIR += $(DEBOUNCED_INPUT_LIB_DIR)
LIBS += DebouncedInput

# vim: syntax=make tabstop=4 noexpandtab
