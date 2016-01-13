# \copyright 2015-2016 Zorxx Software, All Rights Reserved
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

# ArduinoOTA Library
LIB_NAME_ARDUINO_OTA := lib$(PACKAGE_NAME)_ArduinoOTA
$(LIB_NAME_ARDUINO_OTA)_obj := $(foreach file, \
		$(wildcard source/libraries/ArduinoOTA/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# DNSServer Library
LIB_NAME_DNS_SERVER := lib$(PACKAGE_NAME)_DNSServer
$(LIB_NAME_DNS_SERVER)_obj := $(foreach file, \
		$(wildcard source/libraries/DNSServer/src/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# HTTPClient Library
LIB_NAME_HTTP_CLIENT := lib$(PACKAGE_NAME)_HTTPClient
$(LIB_NAME_HTTP_CLIENT)_obj := $(foreach file, \
		$(wildcard source/libraries/ESP8266HTTPClient/src/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# HTTPUpdate Library
LIB_NAME_HTTP_UPDATE := lib$(PACKAGE_NAME)_HTTPUpdate
$(LIB_NAME_HTTP_UPDATE)_obj := $(foreach file, \
		$(wildcard source/libraries/ESP8266httpUpdate/src/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# HTTPUpdateServer Library
LIB_NAME_HTTP_UPDATE_SERVER := lib$(PACKAGE_NAME)_HTTPUpdateServer
$(LIB_NAME_HTTP_UPDATE_SERVER)_obj := $(foreach file, \
		$(wildcard source/libraries/ESP8266HTTPUpdateServer/src/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# AVRISP Library
LIB_NAME_AVRISP := lib$(PACKAGE_NAME)_AVRISP
$(LIB_NAME_AVRISP)_obj := $(foreach file, \
		$(wildcard source/libraries/ESP8266AVRISP/src/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# EEPROM Library
LIB_NAME_EEPROM := lib$(PACKAGE_NAME)_eeprom
$(LIB_NAME_EEPROM)_obj := $(foreach file, \
		$(wildcard source/libraries/EEPROM/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# Ethernet Library
LIB_NAME_ETHERNET := lib$(PACKAGE_NAME)_Ethernet
$(LIB_NAME_ETHERNET)_obj := $(foreach file, \
		$(wildcard source/libraries/Ethernet/src/*.cpp) \
		$(wildcard source/libraries/Ethernet/src/utility/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# GDBStub Library
LIB_NAME_GDBSTUB := lib$(PACKAGE_NAME)_GDBStub
$(LIB_NAME_GDBSTUB)_obj := $(foreach file, \
		$(wildcard source/libraries/GDBStub/src/internal/*.c) \
		$(wildcard source/libraries/GDBStub/src/internal/*.S), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# Hash Library
LIB_NAME_HASH := lib$(PACKAGE_NAME)_Hash
$(LIB_NAME_HASH)_obj := $(foreach file, \
		$(wildcard source/libraries/Hash/src/sha1/*.c) \
		$(wildcard source/libraries/Hash/src/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# OneWire Library
LIB_NAME_ONEWIRE := lib$(PACKAGE_NAME)_OneWire
$(LIB_NAME_ONEWIRE)_obj := $(foreach file, \
		$(wildcard source/libraries/OneWire/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# WiFi Library
LIB_NAME_WIFI := lib$(PACKAGE_NAME)_wifi
$(LIB_NAME_WIFI)_obj := $(foreach file, \
		$(wildcard source/libraries/ESP8266WiFi/src/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# WiFiMesh Library
LIB_NAME_WIFI_MESH := lib$(PACKAGE_NAME)_WiFiMesh
$(LIB_NAME_WIFI_MESH)_obj := $(foreach file, \
		$(wildcard source/libraries/ESP8266WiFiMesh/src/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# mDNS Library
LIB_NAME_MDNS := lib$(PACKAGE_NAME)_mDNS
$(LIB_NAME_MDNS)_obj := $(foreach file, \
		$(wildcard source/libraries/ESP8266mDNS/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# SD Library
LIB_NAME_SD := lib$(PACKAGE_NAME)_SD
$(LIB_NAME_SD)_obj := $(foreach file, \
		$(wildcard source/libraries/SD/src/*.cpp) \
		$(wildcard source/libraries/SD/src/utility/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# SPI Library
LIB_NAME_SPI := lib$(PACKAGE_NAME)_SPI
$(LIB_NAME_SPI)_obj := $(foreach file, \
		$(wildcard source/libraries/SPI/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# SSDP Library
LIB_NAME_SSDP := lib$(PACKAGE_NAME)_SSDP
$(LIB_NAME_SSDP)_obj := $(foreach file, \
		$(wildcard source/libraries/ESP8266SSDP/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))    

# Ticker Library
LIB_NAME_TICKER := lib$(PACKAGE_NAME)_Ticker
$(LIB_NAME_TICKER)_obj := $(foreach file, \
		$(wildcard source/libraries/Ticker/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))  

# TFT Library
LIB_NAME_TFT := lib$(PACKAGE_NAME)_TFT
$(LIB_NAME_TFT)_obj := $(foreach file, \
		$(wildcard source/libraries/TFT_Touch_Shield_V2/*.c) \
		$(wildcard source/libraries/TFT_Touch_Shield_V2/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))  

# Wire Library
LIB_NAME_WIRE := lib$(PACKAGE_NAME)_Wire
$(LIB_NAME_WIRE)_obj := $(foreach file, \
		$(wildcard source/libraries/Wire/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# Libraries don't build cleanly
CFLAGS += -Wno-error -Wno-error=implicit-function-declaration
CPPFLAGS +=

# Note: the library must be built after the package has been downloaded, and the build_library
#  operation must recursively call "make" in order to get the list of all source files to
#  be built/included in the library
all: .$(PACKAGE_NAME).download
	@$(call build_library,$(LIB_NAME_CORE))
	@$(call build_library,$(LIB_NAME_ARDUINO_OTA))
	@$(call build_library,$(LIB_NAME_AVRISP))
	@$(call build_library,$(LIB_NAME_DNS_SERVER))
	@$(call build_library,$(LIB_NAME_EEPROM))
	@$(call build_library,$(LIB_NAME_ETHERNET))
	@$(call build_library,$(LIB_NAME_GDBSTUB))
	@$(call build_library,$(LIB_NAME_HASH))
	@$(call build_library,$(LIB_NAME_HTTP_CLIENT))
	@$(call build_library,$(LIB_NAME_HTTP_UPDATE))
	@$(call build_library,$(LIB_NAME_HTTP_UPDATE_SERVER))
	@$(call build_library,$(LIB_NAME_MDNS))
	@$(call build_library,$(LIB_NAME_ONEWIRE))
	@$(call build_library,$(LIB_NAME_SD))
	@$(call build_library,$(LIB_NAME_SPI))
	@$(call build_library,$(LIB_NAME_SSDP))
	@$(call build_library,$(LIB_NAME_TICKER))
	@$(call build_library,$(LIB_NAME_TFT))
	@$(call build_library,$(LIB_NAME_WIFI))
	@$(call build_library,$(LIB_NAME_WIFI_MESH))
	@$(call build_library,$(LIB_NAME_WIRE))
clean: lib_clean
	@$(call package_clean,$(PACKAGE_NAME))
lib_clean:
	@$(call library_clean,$(LIB_NAME_CORE))
	@$(call library_clean,$(LIB_NAME_ARDUINO_OTA))
	@$(call library_clean,$(LIB_NAME_AVRISP))
	@$(call library_clean,$(LIB_NAME_DNS_SERVER))
	@$(call library_clean,$(LIB_NAME_EEPROM))
	@$(call library_clean,$(LIB_NAME_ETHERNET))
	@$(call library_clean,$(LIB_NAME_GDBSTUB))
	@$(call library_clean,$(LIB_NAME_HASH))
	@$(call library_clean,$(LIB_NAME_HTTP_CLIENT))
	@$(call library_clean,$(LIB_NAME_HTTP_UPDATE))
	@$(call library_clean,$(LIB_NAME_HTTP_UPDATE_SERVER))
	@$(call library_clean,$(LIB_NAME_MDNS))
	@$(call library_clean,$(LIB_NAME_ONEWIRE))
	@$(call library_clean,$(LIB_NAME_SD))
	@$(call library_clean,$(LIB_NAME_SPI))
	@$(call library_clean,$(LIB_NAME_SSDP))
	@$(call library_clean,$(LIB_NAME_TICKER))
	@$(call library_clean,$(LIB_NAME_TFT))
	@$(call library_clean,$(LIB_NAME_WIFI))
	@$(call library_clean,$(LIB_NAME_WIFI_MESH))
	@$(call library_clean,$(LIB_NAME_WIRE))
	@$(call build_clean)

# vim: syntax=make tabstop=4 noexpandtab
