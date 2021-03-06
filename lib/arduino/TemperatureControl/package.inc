# \copyright 2015-2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino-Temperature-Control-Library package build environment

TEMPERATURE_CONTROL_LIB_DIR := $(LIBRARIES_DIR)/arduino/TemperatureControl/TemperatureControl_source
INCDIR += $(TEMPERATURE_CONTROL_LIB_DIR)
LIBS += TemperatureControl

# vim: syntax=make tabstop=4 noexpandtab
