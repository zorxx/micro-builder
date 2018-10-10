# \copyright 2015-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 Arduino SDK package

include ../../../include/mb.inc

PACKAGE_NAME := arduino

# External package download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/esp8266/Arduino.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git
$(PACKAGE_NAME)_VERSION := 2.4.1

SRCDIR := $(PACKAGE_NAME)_source

# Remove the Cache_Read_Enable_New function from libmain.a. We need to
#  use the function defined in rboot in order to make use of flash
#  larger than 1 MiB
define $(PACKAGE_NAME)_POSTACTION
$(OBJCOPY) -W Cache_Read_Enable_New $(SRCDIR)/tools/sdk/lib/libmain.a
endef

# Core Library
LIB_NAME_CORE := lib$(PACKAGE_NAME)_core
$(LIB_NAME_CORE)_obj := $(foreach file, \
		$(SRCDIR)/tests/host/common/noniso.c \
		$(wildcard $(SRCDIR)/cores/esp8266/*.c) \
		$(wildcard $(SRCDIR)/cores/esp8266/umm_malloc/*.c) \
		$(wildcard $(SRCDIR)/cores/esp8266/spiffs/*.c) \
		$(wildcard $(SRCDIR)/cores/esp8266/*.cpp) \
		$(wildcard $(SRCDIR)/cores/esp8266/*.S), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# ArduinoOTA Library
LIB_NAME_ARDUINO_OTA := lib$(PACKAGE_NAME)_ArduinoOTA
$(LIB_NAME_ARDUINO_OTA)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/ArduinoOTA/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# DNSServer Library
LIB_NAME_DNS_SERVER := lib$(PACKAGE_NAME)_DNSServer
$(LIB_NAME_DNS_SERVER)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/DNSServer/src/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# HTTPClient Library
LIB_NAME_HTTP_CLIENT := lib$(PACKAGE_NAME)_HTTPClient
$(LIB_NAME_HTTP_CLIENT)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/ESP8266HTTPClient/src/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# HTTPUpdate Library
LIB_NAME_HTTP_UPDATE := lib$(PACKAGE_NAME)_HTTPUpdate
$(LIB_NAME_HTTP_UPDATE)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/ESP8266httpUpdate/src/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# HTTPUpdateServer Library
LIB_NAME_HTTP_UPDATE_SERVER := lib$(PACKAGE_NAME)_HTTPUpdateServer
$(LIB_NAME_HTTP_UPDATE_SERVER)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/ESP8266HTTPUpdateServer/src/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# AVRISP Library
LIB_NAME_AVRISP := lib$(PACKAGE_NAME)_AVRISP
$(LIB_NAME_AVRISP)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/ESP8266AVRISP/src/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# EEPROM Library
LIB_NAME_EEPROM := lib$(PACKAGE_NAME)_eeprom
$(LIB_NAME_EEPROM)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/EEPROM/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# WebServer Library 
LIB_NAME_ESP8266_WEBSERVER := lib$(PACKAGE_NAME)_WebServer
$(LIB_NAME_ESP8266_WEBSERVER)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/ESP8266WebServer/src/*.cpp) \
		$(wildcard $(SRCDIR)/libraries/ESP8266WebServer/src/detail/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# Ethernet Library
LIB_NAME_ETHERNET := lib$(PACKAGE_NAME)_Ethernet
$(LIB_NAME_ETHERNET)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/Ethernet/src/*.cpp) \
		$(wildcard $(SRCDIR)/libraries/Ethernet/src/utility/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# GDBStub Library
LIB_NAME_GDBSTUB := lib$(PACKAGE_NAME)_GDBStub
$(LIB_NAME_GDBSTUB)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/GDBStub/src/internal/*.c) \
		$(wildcard $(SRCDIR)/libraries/GDBStub/src/internal/*.S), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# Hash Library
LIB_NAME_HASH := lib$(PACKAGE_NAME)_Hash
$(LIB_NAME_HASH)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/Hash/src/sha1/*.c) \
		$(wildcard $(SRCDIR)/libraries/Hash/src/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# OneWire Library
LIB_NAME_ONEWIRE := lib$(PACKAGE_NAME)_OneWire
$(LIB_NAME_ONEWIRE)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/OneWire/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# WiFi Library
LIB_NAME_WIFI := lib$(PACKAGE_NAME)_wifi
$(LIB_NAME_WIFI)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/ESP8266WiFi/src/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# WiFiMesh Library
LIB_NAME_WIFI_MESH := lib$(PACKAGE_NAME)_WiFiMesh
$(LIB_NAME_WIFI_MESH)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/ESP8266WiFiMesh/src/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# mDNS Library
LIB_NAME_MDNS := lib$(PACKAGE_NAME)_mDNS
$(LIB_NAME_MDNS)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/ESP8266mDNS/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# SD Library
LIB_NAME_SD := lib$(PACKAGE_NAME)_SD
$(LIB_NAME_SD)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/SD/src/*.cpp) \
		$(wildcard $(SRCDIR)/libraries/SD/src/utility/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# SPI Library
LIB_NAME_SPI := lib$(PACKAGE_NAME)_SPI
$(LIB_NAME_SPI)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/SPI/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

# SSDP Library
LIB_NAME_SSDP := lib$(PACKAGE_NAME)_SSDP
$(LIB_NAME_SSDP)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/ESP8266SSDP/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))    

# Ticker Library
LIB_NAME_TICKER := lib$(PACKAGE_NAME)_Ticker
$(LIB_NAME_TICKER)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/Ticker/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))  

# TFT Library
LIB_NAME_TFT := lib$(PACKAGE_NAME)_TFT
$(LIB_NAME_TFT)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/TFT_Touch_Shield_V2/*.c) \
		$(wildcard $(SRCDIR)/libraries/TFT_Touch_Shield_V2/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))  

# Wire Library
LIB_NAME_WIRE := lib$(PACKAGE_NAME)_Wire
$(LIB_NAME_WIRE)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/libraries/Wire/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

EXTERNAL_TARGETS += $(PACKAGE_NAME)

LIBRARY_TARGETS += $(LIB_NAME_CORE) $(LIB_NAME_AVRISP) \
  $(LIB_NAME_DNS_SERVER) $(LIB_NAME_EEPROM) $(LIB_NAME_ETHERNET) $(LIB_NAME_GDBSTUB) \
  $(LIB_NAME_HASH) $(LIB_NAME_HTTP_CLIENT) $(LIB_NAME_HTTP_UPDATE) $(LIB_NAME_HTTP_UPDATE_SERVER) \
  $(LIB_NAME_ONEWIRE) $(LIB_NAME_SD) $(LIB_NAME_SPI) \
  $(LIB_NAME_TICKER) $(LIB_NAME_TFT) $(LIB_NAME_WIFI) $(LIB_NAME_WIFI_MESH) $(LIB_NAME_WIRE) \
  $(LIB_NAME_ARDUINO_OTA) $(LIB_NAME_MDNS) $(LIB_NAME_SSDP) $(LIB_NAME_ESP8266_WEBSERVER)
LIBRARY_SUBMAKE := true

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
