# \copyright 2017-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Adafruit HUZZAH Variant

PREREQS := package/esp8266/toolchain packages/esp8266/ztool packages/esp8266/zboot \
           package/esp8266/esptool package/esp8266/esp8266_sdk

TARGET_FLASH_SIZE := 32M
TARGET_FLASH_MODE := qio
TARGET_FLASH_SPEED := 40

TARGET_CPU_SPEED := 80000000
TARGET_BOARD := generic

APP_LD_SCRIPT ?= $(ARCH_INCLUDE_DIR)/esp8266/ld/eagle.flash.1m.ld
LIBDIRS += $(ARCH_INCLUDE_DIR)/esp8266/ld

# This must be last
include $(INCLUDE_DIR)/xtensa/esp8266/esp8266.inc 

# vim: syntax=make tabstop=4 noexpandtab
