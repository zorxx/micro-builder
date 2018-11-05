# \copyright 2017-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 SSD1306 0.96" OLED Display build environment

dependencies = package/esp8266/arduino 

include ../../../include/mb.inc

PACKAGE_NAME := esp8266_oled_ssd1306

# Download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/squix78/esp8266-oled-ssd1306.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

# Library
LIB_NAME := lib$(PACKAGE_NAME)
$(LIB_NAME)_obj := $(foreach file, \
		$(wildcard $(ESP8266_OLED_SSD1306_LIB_DIR)/*.cpp), \
		$(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

EXTERNAL_TARGETS += $(PACKAGE_NAME)
LIBRARY_TARGETS += $(LIB_NAME)
LIBRARY_SUBMAKE := true # Call "make" recursively when building the library to get the source files

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/lib.inc

# vim: syntax=make tabstop=4 noexpandtab
