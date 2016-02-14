# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino MQTT library package build environment

MQTT_LIB_DIR := $(PACKAGE_DIR)/common/MQTT/MQTT_source
MQTT_EXAMPLES_DIR := $(MQTT_LIB_DIR)/examples
INCDIR += $(MQTT_LIB_DIR)/src

# vim: syntax=make tabstop=4 noexpandtab
