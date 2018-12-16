# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Arduino SimpleTimer library package build environment

SIMPLETIMER_LIB_DIR := $(LIBRARIES_DIR)/arduino/SimpleTimer/SimpleTimer_source
INCDIR += $(SIMPLETIMER_LIB_DIR)
LIBS += SimpleTimer

# vim: syntax=make tabstop=4 noexpandtab
