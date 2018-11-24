# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief nodemcu with DIO flash Variant

PREREQS := package/esp8266/esp_toolchain package/xtensa/ztool package/xtensa/zboot \
           package/xtensa/esptool_py package/esp8266/sdk

TARGET_FLASH_SIZE := 4M
TARGET_FLASH_MODE := dio
TARGET_FLASH_SPEED := 80

TARGET_CPU_SPEED := 80000000
TARGET_BOARD := nodemcu

# This must be last
include $(INCLUDE_DIR)/xtensa/esp8266/esp8266.inc 

# vim: syntax=make tabstop=4 noexpandtab
