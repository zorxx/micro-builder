# \copyright 2017-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief nodemcu Arduino Variant

PREREQS := package/esp8266/arduino_toolchain package/xtensa/ztool package/xtensa/zboot \
           package/esp8266/arduino package/xtensa/esptool_py

TARGET_FLASH_SIZE := 4M
TARGET_FLASH_MODE := qio
TARGET_FLASH_SPEED := 80

TARGET_CPU_SPEED := 80000000
TARGET_BOARD := nodemcu

APP_LD_SCRIPT ?= eagle.flash.1m.ld
CDEFS += ARDUINO_ESP8266_NODEMCU

# This must be last
include $(INCLUDE_DIR)/xtensa/esp8266/esp8266.inc 

# vim: syntax=make tabstop=4 noexpandtab
