# \copyright 2018 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief zboot web control panel library

include ../../../include/mb.inc

CPANEL_SRC := main.cpp

ifeq ($(ESP8266_ARDUINO_DIR),)

$(info zboot_cpanel: microhttpd web server implementation)

$(call build_dependency,lib/common/microhttpd)
include $(LIBRARIES_DIR)/common/microhttpd/package.inc
CPANEL_SRC += microhttpd.cpp esp8266_sdk.cpp

else ifeq ($(ESP8266_ARDUINO_DIR),1)

$(info zboot_cpanel: mongoose web server implementation)
$(call build_dependency,lib/common/mongoose)
include $(LIBRARIES_DIR)/common/mongoose/package.inc
CPANEL_SRC += mmongoose.cpp esp8266_sdk.cpp

else

$(info zboot_cpanel: Arduino web server implementation)
CPANEL_SRC += arduino.cpp

endif

LIB_NAME = libzboot_cpanel

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

# vim: syntax=make tabstop=4 noexpandtab
