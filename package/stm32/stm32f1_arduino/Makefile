# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for STM32F1 Arduino package

include ../../../include/mb.inc

PACKAGE_NAME := arduino

$(PACKAGE_NAME)_SOURCE := "https://github.com/rogerclarkmelbourne/Arduino_STM32"
$(PACKAGE_NAME)_SOURCE_METHOD := git

# ----------------------------------------------------------------------------------------
# Common

STM_SRCDIR := $(ARDUINO_TARGET_CPU_DIR)/cores/maple
VARIANT_SRCDIR := $(ARDUINO_TARGET_CPU_DIR)/variants/$(STM32_VARIANT)

# Core Library
LIB_NAME_CORE := lib$(PACKAGE_NAME)_core
$(LIB_NAME_CORE)_obj := $(foreach file, \
                $(wildcard $(STM_SRCDIR)/*.c) \
                $(wildcard $(STM_SRCDIR)/*.cpp) \
                $(wildcard $(STM_SRCDIR)/avr/*.c) \
                $(wildcard $(STM_SRCDIR)/libmaple/*.c) \
                $(wildcard $(STM_SRCDIR)/libmaple/*.S) \
                $(wildcard $(STM_SRCDIR)/libmaple/stm32f1/performance/*.S) \
                $(wildcard $(STM_SRCDIR)/libmaple/usb/stm32f1/*.c) \
                $(wildcard $(STM_SRCDIR)/libmaple/usb/usb_lib/*.c) \
                $(wildcard $(STM_SRCDIR)/stm32f1/*.c) \
                $(wildcard $(STM_SRCDIR)/stm32f1/*.cpp) \
                $(wildcard $(VARIANT_SRCDIR)/*.c) \
                $(wildcard $(VARIANT_SRCDIR)/*.cpp) \
                $(wildcard $(VARIANT_SRCDIR)/*.S) \
                $(wildcard $(VARIANT_SRCDIR)/wirish/*.c) \
                $(wildcard $(VARIANT_SRCDIR)/wirish/*.cpp) \
                $(wildcard $(VARIANT_SRCDIR)/wirish/*.S) \
                $(ARDUINO_DIR)/../gccfix.cpp, \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

LIBRARY_TARGETS += $(LIB_NAME_CORE)

# ----------------------------------------------------------------------------------------
# STM32F1

# Wire Library
LIB_NAME_WIRE := lib$(PACKAGE_NAME)_Wire
$(LIB_NAME_WIRE)_obj := $(foreach file, \
                $(wildcard $(ARDUINO_LIB_DIR)/Wire/*.cpp) \
                $(wildcard $(ARDUINO_LIB_DIR)/Wire/utility/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# EEPROM Library
LIB_NAME_EEPROM := lib$(PACKAGE_NAME)_EEPROM
$(LIB_NAME_EEPROM)_obj := $(foreach file, \
                $(wildcard $(ARDUINO_LIB_DIR)/EEPROM/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# RTClock Library
LIB_NAME_RTCLOCK := lib$(PACKAGE_NAME)_RTClock
$(LIB_NAME_RTCLOCK)_obj := $(foreach file, \
                $(wildcard $(ARDUINO_LIB_DIR)/RTClock/src/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# SPI Library
LIB_NAME_SPI := lib$(PACKAGE_NAME)_SPI
$(LIB_NAME_SPI)_obj := $(foreach file, \
                $(wildcard $(ARDUINO_LIB_DIR)/SPI/src/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))


LIBRARY_TARGETS += $(LIB_NAME_WIRE) $(LIB_NAME_EEPROM) $(LIB_NAME_SPI) $(LIB_NAME_RTCLOCK)

# ----------------------------------------------------------------------------------------

EXTERNAL_TARGETS += $(PACKAGE_NAME)
LIBRARY_SUBMAKE := true

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
