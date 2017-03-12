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

# ----------------------------------------------------------------------------------------

AVR_SRCDIR := $(PACKAGE_NAME)_source/arduino-nightly/hardware/arduino/avr

# Core Library
LIB_NAME_CORE := lib$(PACKAGE_NAME)_core
$(LIB_NAME_CORE)_obj := $(foreach file, \
                $(wildcard $(AVR_SRCDIR)/cores/arduino/*.c) \
                $(wildcard $(AVR_SRCDIR)/cores/arduino/*.cpp) \
                $(wildcard $(AVR_SRCDIR)/cores/arduino/*.S), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# SoftwareSerial Library
LIB_NAME_SOFTWARE_SERIAL := lib$(PACKAGE_NAME)_SoftwareSerial
$(LIB_NAME_SOFTWARE_SERIAL)_obj := $(foreach file, \
                $(wildcard $(AVR_SRCDIR)/libraries/SoftwareSerial/src/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# SPI Library
LIB_NAME_SPI := lib$(PACKAGE_NAME)_SPI
$(LIB_NAME_SPI)_obj := $(foreach file, \
                $(wildcard $(AVR_SRCDIR)/libraries/SPI/src/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# Wire Library
LIB_NAME_WIRE := lib$(PACKAGE_NAME)_Wire
$(LIB_NAME_WIRE)_obj := $(foreach file, \
                $(wildcard $(AVR_SRCDIR)/libraries/Wire/src/*.cpp) \
                $(wildcard $(AVR_SRCDIR)/libraries/Wire/src/utility/*.c), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# HID Library
LIB_NAME_HID := lib$(PACKAGE_NAME)_HID
$(LIB_NAME_HID)_obj := $(foreach file, \
                $(wildcard $(AVR_SRCDIR)/libraries/HID/src/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# ----------------------------------------------------------------------------------------

COMMON_LIBDIR := $(PACKAGE_NAME)_source/arduino-nightly/libraries

# Bridge Library
LIB_NAME_BRIDGE := lib$(PACKAGE_NAME)_Bridge
$(LIB_NAME_BRIDGE)_obj := $(foreach file, \
                $(wildcard $(COMMON_LIBDIR)/Bridge/src/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# Ethernet Library
LIB_NAME_ETHERNET := lib$(PACKAGE_NAME)_Ethernet
$(LIB_NAME_ETHERNET)_obj := $(foreach file, \
                $(wildcard $(COMMON_LIBDIR)/Ethernet/src/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# Keyboard Library
LIB_NAME_KEYBOARD := lib$(PACKAGE_NAME)_Keyboard
$(LIB_NAME_KEYBOARD)_obj := $(foreach file, \
                $(wildcard $(COMMON_LIBDIR)/Keyboard/src/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# LiquidCrystal Library
LIB_NAME_LIQUIDCRYSTAL := lib$(PACKAGE_NAME)_LiquidCrystal
$(LIB_NAME_LIQUIDCRYSTAL)_obj := $(foreach file, \
                $(wildcard $(COMMON_LIBDIR)/LiquidCrystal/src/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# Mouse Library
LIB_NAME_MOUSE := lib$(PACKAGE_NAME)_Mouse
$(LIB_NAME_MOUSE)_obj := $(foreach file, \
                $(wildcard $(COMMON_LIBDIR)/Mouse/src/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# SD Library
LIB_NAME_SD := lib$(PACKAGE_NAME)_SD
$(LIB_NAME_SD)_obj := $(foreach file, \
                $(wildcard $(COMMON_LIBDIR)/SD/src/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# Servo Library
LIB_NAME_SERVO := lib$(PACKAGE_NAME)_Servo
$(LIB_NAME_SERVO)_obj := $(foreach file, \
                $(wildcard $(COMMON_LIBDIR)/Servo/src/avr/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# Stepper Library
LIB_NAME_STEPPER := lib$(PACKAGE_NAME)_Stepper
$(LIB_NAME_STEPPER)_obj := $(foreach file, \
                $(wildcard $(COMMON_LIBDIR)/Stepper/src/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# WiFi Library
LIB_NAME_WIFI := lib$(PACKAGE_NAME)_WiFi
$(LIB_NAME_WIFI)_obj := $(foreach file, \
                $(wildcard $(COMMON_LIBDIR)/WiFi/src/*.cpp), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

EXTERNAL_TARGETS += $(PACKAGE_NAME)

LIBRARY_TARGETS += $(LIB_NAME_CORE) $(LIB_NAME_SOFTWARE_SERIAL) $(LIB_NAME_SPI) $(LIB_NAME_WIRE)
LIBRARY_TARGETS += $(LIB_NAME_HID) $(LIB_NAME_BRIDGE) $(LIB_NAME_ETHERNET) $(LIB_NAME_KEYBOARD)
LIBRARY_TARGETS += $(LIB_NAME_LIQUIDCRYSTAL) $(LIB_NAME_MOUSE) $(LIB_NAME_SD)
LIBRARY_TARGETS += $(LIB_NAME_WIFI) $(LIB_NAME_SERVO) $(LIB_NAME_STEPPER)
LIBRARY_SUBMAKE := true

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
