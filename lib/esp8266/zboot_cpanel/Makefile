# \copyright 2018 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief zboot web control panel library

include ../../../include/mb.inc

ifeq ($(ESP8266_ARDUINO_DIR),)

$(info zboot_cpanel: mongoose web server implementation)
CPANEL_PLATFORM := mongoose
include $(LIBRARIES_DIR)/common/mongoose/package.inc

else

$(info zboot_cpanel: Arduino web server implementation)
CPANEL_PLATFORM := arduino

endif

LIB_NAME = libzboot_cpanel

CPANEL_SRC_mongoose = mongoose.ecpp
CPANEL_SRC_arduino = arduino.cpp
CPANEL_SRC := main.cpp $(CPANEL_SRC_$(CPANEL_PLATFORM))

$(LIB_NAME)_obj := $(foreach file, \
	           $(CPANEL_SRC), \
	           $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))
$(LIB_NAME)_obj += $(foreach file, \
	           $(wildcard *.html) \
	           $(wildcard *.js), \
	           $(addsuffix .bin.o, $(basename $(BUILD_TEMP_DIR)/$(file))))

#CDEFS += DEBUG=1
LIBRARY_TARGETS += $(LIB_NAME)

include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab