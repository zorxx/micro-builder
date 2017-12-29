# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for STM32 Arduino package

include ../../../include/mb.inc

PACKAGE_NAME := arduino

$(PACKAGE_NAME)_FILENAME := master.zip
$(PACKAGE_NAME)_SOURCE := "https://github.com/rogerclarkmelbourne/Arduino_STM32/archive/$($(PACKAGE_NAME)_FILENAME)" 
$(PACKAGE_NAME)_SOURCE_METHOD := wget

# ----------------------------------------------------------------------------------------

STM_SRCDIR := $(PACKAGE_NAME)_source/Arduino_STM32-master/$(STM32_CPU)/cores/maple
VARIANT_SRCDIR := $(PACKAGE_NAME)_source/Arduino_STM32-master/$(STM32_CPU)/variants/$(STM32_VARIANT)

# Core Library
LIB_NAME_CORE := lib$(PACKAGE_NAME)_core
$(LIB_NAME_CORE)_obj := $(foreach file, \
                $(wildcard $(STM_SRCDIR)/*.c) \
                $(wildcard $(STM_SRCDIR)/*.cpp) \
                $(wildcard $(STM_SRCDIR)/*.S) \
                $(wildcard $(STM_SRCDIR)/avr/*.c) \
                $(wildcard $(STM_SRCDIR)/libmaple/*.c) \
                $(wildcard $(STM_SRCDIR)/libmaple/*.cpp) \
                $(wildcard $(STM_SRCDIR)/libmaple/*.S) \
                $(wildcard $(VARIANT_SRCDIR)/*.c) \
                $(wildcard $(VARIANT_SRCDIR)/*.cpp) \
                $(wildcard $(VARIANT_SRCDIR)/*.S) \
                $(wildcard $(VARIANT_SRCDIR)/wirish/*.c) \
                $(wildcard $(VARIANT_SRCDIR)/wirish/*.S), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# ----------------------------------------------------------------------------------------

STM32F1_LIBDIR := $(PACKAGE_NAME)_source/Arduino_STM32-master/STM32F1/libraries

# Wire Library
LIB_NAME_WIRE := lib$(PACKAGE_NAME)_arduino_uip
$(LIB_NAME_WIRE)_obj := $(foreach file, \
                $(wildcard $(STM32F1_LIBDIR)/Wire/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

STM32F4_LIBDIR := $(PACKAGE_NAME)_source/Arduino_STM32-master/STM32F4/libraries

# arduino_uip Library
LIB_NAME_UIP := lib$(PACKAGE_NAME)_arduino_uip
$(LIB_NAME_UIP)_obj := $(foreach file, \
                $(wildcard $(STM32F4_LIBDIR)/arduino_uip/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# RTClock Library
LIB_NAME_RTC := lib$(PACKAGE_NAME)_RTClock
$(LIB_NAME_RTC)_obj := $(foreach file, \
                $(wildcard $(STM32F4_LIBDIR)/RTClock/src/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# SDIO Library
LIB_NAME_SDIO := lib$(PACKAGE_NAME)_SDIO
$(LIB_NAME_SDIO)_obj := $(foreach file, \
                $(wildcard $(STM32F4_LIBDIR)/SDIO/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# SPI Library
LIB_NAME_SPI := lib$(PACKAGE_NAME)_SPI
$(LIB_NAME_SPI)_obj := $(foreach file, \
                $(wildcard $(STM32F4_LIBDIR)/SPI/src/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

EXTERNAL_TARGETS += $(PACKAGE_NAME)

LIBRARY_TARGETS += $(LIB_NAME_CORE) $(LIB_NAME_UIP) $(LIB_NAME_RTC)
LIBRARY_TARGETS += $(LIB_NAME_SPI) $(LIB_NAME_WIRE)
LIBRARY_SUBMAKE := true

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
