# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for AVR Arduino package

include ../../../include/mb.inc

PACKAGE_NAME := arduino

ARCH_FILENAME := $(strip \
        $(if $(findstring Linux_64,$(HOST_ARCH)),linux64.tar.xz, \
                $(if $(findstring Linux_32,$(HOST_ARCH)),linux32.tar.xz, \
                        $(if $(findstring WIN,$(HOST_ARCH)),windows.zip, \
                                $(if $(findstring OSX,$(HOST_ARCH)),macosx.zip, \
                                        unknown)))))
$(PACKAGE_NAME)_FILENAME := arduino-nightly-$(ARCH_FILENAME)
$(PACKAGE_NAME)_SOURCE := "https://www.arduino.cc/download.php?f=/$($(PACKAGE_NAME)_FILENAME)"
$(PACKAGE_NAME)_SOURCE_METHOD := wget

SRCDIR := $(PACKAGE_NAME)_source/arduino-nightly/hardware/arduino/avr

# Core Library
LIB_NAME_CORE := lib$(PACKAGE_NAME)_core
$(LIB_NAME_CORE)_obj := $(foreach file, \
                $(wildcard $(SRCDIR)/cores/arduino/*.c) \
                $(wildcard $(SRCDIR)/cores/arduino/*.cpp) \
                $(wildcard $(SRCDIR)/cores/arduino/*.S), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# SoftwareSerial Library
LIB_NAME_SOFTWARE_SERIAL := lib$(PACKAGE_NAME)_SoftwareSerial
$(LIB_NAME_SOFTWARE_SERIAL)_obj := $(foreach file, \
                $(wildcard $(SRCDIR)/libraries/SoftwareSerial/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# SPI Library
LIB_NAME_SPI := lib$(PACKAGE_NAME)_SPI
$(LIB_NAME_SPI)_obj := $(foreach file, \
                $(wildcard $(SRCDIR)/libraries/SPI/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# Wire Library
LIB_NAME_WIRE := lib$(PACKAGE_NAME)_Wire
$(LIB_NAME_WIRE)_obj := $(foreach file, \
                $(wildcard $(SRCDIR)/libraries/Wire/*.cpp) \
                $(wildcard $(SRCDIR)/libraries/Wire/utility/*.c), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

EXTERNAL_TARGETS += $(PACKAGE_NAME)

LIBRARY_TARGETS += $(LIB_NAME_CORE) $(LIB_NAME_SOFTWARE_SERIAL) $(LIB_NAME_SPI) $(LIB_NAME_WIRE)
LIBRARY_SUBMAKE := true

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
