# \copyright 2016-2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino MQTT library package build environment

MQTT_LIB_DIR := $(LIBRARIES_DIR)/arduino/MQTT/MQTT_source
MQTT_EXAMPLES_DIR := $(MQTT_LIB_DIR)/examples
INCDIR += $(MQTT_LIB_DIR)/src

# vim: syntax=make tabstop=4 noexpandtab
