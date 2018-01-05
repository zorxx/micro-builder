# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino DHT Sensor Library package build environment

DHT_SENSOR_LIB_DIR := $(LIBRARIES_DIR)/arduino/DHT-sensor/DHT-sensor_source
INCDIR += $(DHT_SENSOR_LIB_DIR)
LIBS += DHT-sensor

# vim: syntax=make tabstop=4 noexpandtab
