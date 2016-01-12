# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 Arduino SDK package

include ../../../include/mb.inc

PACKAGE_NAME := esp8266_arduino

# Download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/esp8266/Arduino.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

# Core Library
LIB_NAME_CORE := lib$(PACKAGE_NAME)_core
$(LIB_NAME_CORE)_obj := $(foreach file, \
		$(wildcard source/cores/esp8266/*.c) \
		$(wildcard source/cores/esp8266/*.cpp) \
		$(wildcard source/cores/esp8266/*.S), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# EEPROM Library
LIB_NAME_EEPROM := lib$(PACKAGE_NAME)_eeprom
$(LIB_NAME_EEPROM)_obj := $(foreach file, \
		$(wildcard source/libraries/EEPROM/esp8266/*.c) \
		$(wildcard source/libraries/EEPROM/*.cpp) \
		$(wildcard source/libraries/EEPROM/*.S), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# WiFi Library
LIB_NAME_WIFI := lib$(PACKAGE_NAME)_wifi
$(LIB_NAME_WIFI)_obj := $(foreach file, \
		$(wildcard source/libraries/ESP8266WiFi/src/*.c) \
		$(wildcard source/libraries/ESP8266WiFi/src/*.cpp) \
		$(wildcard source/libraries/ESP8266WiFi/src/*.S), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# mDNS Library
LIB_NAME_MDNS := lib$(PACKAGE_NAME)_mDNS
$(LIB_NAME_MDNS)_obj := $(foreach file, \
		$(wildcard source/libraries/ESP8266mDNS/*.c) \
		$(wildcard source/libraries/ESP8266mDNS/*.cpp) \
		$(wildcard source/libraries/ESP8266mDNS/*.S), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# The library doesn't build cleanly
CFLAGS += -Wno-error -Wno-error=implicit-function-declaration
CPPFLAGS +=

# Note: the library must be built after the package has been downloaded, and the build_library
#  operation must recursively call "make" in order to get the list of all source files to
#  be built/included in the library
all: .$(PACKAGE_NAME).download
	@$(call build_library,$(LIB_NAME_CORE))
	@$(call build_library,$(LIB_NAME_EEPROM))
	@$(call build_library,$(LIB_NAME_WIFI))
	@$(call build_library,$(LIB_NAME_MDNS))
clean: lib_clean
	@$(call package_clean,$(PACKAGE_NAME))
lib_clean:
	@$(call library_clean,$(LIB_NAME_CORE))
	@$(call library_clean,$(LIB_NAME_EEPROM))
	@$(call library_clean,$(LIB_NAME_WIFI))
	@$(call library_clean,$(LIB_NAME_MDNS))
	@$(call build_clean)

# vim: syntax=make tabstop=4 noexpandtab
