# \copyright 2017-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief nodemcu Arduino Variant

PREREQS := package/esp8266/arduino_toolchain package/esp8266/ztool package/esp8266/rboot package/esp8266/arduino package/esp8266/esptool

TARGET_FLASH_SIZE := 4M
TARGET_FLASH_MODE := dio
TARGET_FLASH_SPEED := 80

TARGET_CPU_SPEED := 80000000
TARGET_BOARD := nodemcu

APP_LD_SCRIPT ?= $(ARCH_INCLUDE_DIR)/esp8266/ld/eagle.flash.1m.ld
LIBDIRS += $(ARCH_INCLUDE_DIR)/esp8266/ld
CDEFS += ARDUINO_ESP8266_NODEMCU

# This must be last
include $(INCLUDE_DIR)/xtensa/esp8266/esp8266.inc 

# vim: syntax=make tabstop=4 noexpandtab
