# \copyright 2015-2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino OneWire library package build environment

ONEWIRE_LIB_DIR := $(LIBRARIES_DIR)/arduino/OneWire/OneWire_source
CDEFS += ONEWIRE_SEARCH=1
INCDIR += $(ONEWIRE_LIB_DIR)

# vim: syntax=make tabstop=4 noexpandtab
