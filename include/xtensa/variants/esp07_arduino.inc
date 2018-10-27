# \copyright 2017-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief nodemcu Arduino Variant

PREREQS := package/esp8266/arduino_toolchain package/esp8266/ztool package/esp8266/zboot \
           package/esp8266/arduino package/xtensa/esptool_py

TARGET_FLASH_SIZE := 1M
TARGET_FLASH_MODE := qio
TARGET_FLASH_SPEED := 80

TARGET_CPU_SPEED := 80000000
TARGET_BOARD := nodemcu

ESP8266_APP_FLASH_ADDRESS ?= 0x3000

APP_VARIANTS := app1of2 app2of2
app1of2_LDFLAGS := -T$(ARCH_INCLUDE_DIR)/esp8266/ld/eagle.flash.1of2.ld
app2of2_LDFLAGS := -T$(ARCH_INCLUDE_DIR)/esp8266/ld/eagle.flash.2of2.ld

LIBDIRS += $(ARCH_INCLUDE_DIR)/esp8266/ld
CDEFS += ARDUINO_ESP8266_NODEMCU

# This must be last
include $(INCLUDE_DIR)/xtensa/esp8266/esp8266.inc 

# vim: syntax=make tabstop=4 noexpandtab
