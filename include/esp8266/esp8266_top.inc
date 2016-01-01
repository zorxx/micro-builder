# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top make include file for ESP8266 architecture

# Target board type
# Valid options:
#   adafruit
#   nodemcu
TARGET_BOARD ?= nodemcu

# Serial port and baud rate for programming (flashing)
TARGET_PORT ?= COM14
TARGET_BAUD ?= 256000

# -------------------------------------------------
#

include $(TOPDIR)/include/esp8266/variants.inc

APP_LD_SCRIPT := $(ARCH_INCLUDE_DIR)/ld/$(BOARD_LD_SCRIPT_$(TARGET_BOARD))
LDFLAGS += -T$(APP_LD_SCRIPT)
LIBDIRS += $(ARCH_INCLUDE_DIR)/ld

CFLAGS := 
CPPFLAGS := -std=c++11
CDEFS := __ets__ ICACHE_FLASH ARDUINO_ARCH_ESP8266 ARDUINO=100 

define esp8266_post_lib
endef

define esp8266_post_app
	@$(ESPTOOL) elf2image $(APP_OUT) -o$(BUILD_TEMP_DIR)/
endef

# vim: syntax=make tabstop=4 noexpandtab
