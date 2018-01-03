# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino BMP180 Barometric Pressure/Temperature Sensor Library package build environment

BMP180_LIB_DIR := $(LIBRARIES_DIR)/arduino/BMP180/BMP180_source/Libraries/Arduino/src
INCDIR += $(BMP180_LIB_DIR)
LIBS += BMP180

# vim: syntax=make tabstop=4 noexpandtab
