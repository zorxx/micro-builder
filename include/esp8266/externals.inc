# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief file to be included at the top of each GNU makefile

# ----------------------------------------------------------------------------------------
# Espressif SDKs

# ESP8266 NORTOS SDK
ESP8266_SDK_VERSION := 1.5.0
ESP8266_SDK_SOURCE := "http://bbs.espressif.com/download/file.php?id=989"
ESP8266_SDK_INSTALL_DIR := $(EXTERNALS_DIR)/esp8266_sdk
ESP8266_SDK_DIR := $(ESP8266_SDK_INSTALL_DIR)/esp_iot_sdk_v$(ESP8266_SDK_VERSION)
ESP8266_LD_DIR := $(ESP8266_SDK_DIR)/ld

# ESP8266 RTOS SDK
# TODO

# ----------------------------------------------------------------------------------------
# Espressif Tools

ESPTOOL_SOURCE := "https://github.com/themadinventor/esptool.git"
ESPTOOL_DIR := $(EXTERNALS_DIR)/esptool
ESPTOOL := python $(ESPTOOL_DIR)/esptool.py

# -----------------------------------------------------------------------
# ESP8266/Arduino Libraries

ESP8266_ARDUINO_SOURCE := "https://github.com/esp8266/Arduino.git"
ESP8266_ARDUINO_DIR := $(EXTERNALS_DIR)/arduino
ESP8266_ARDUINO_SDK_DIR := $(ESP8266_ARDUINO_DIR)/tools/sdk
                          
