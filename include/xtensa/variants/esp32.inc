# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief nodemcu Variant

PREREQS := package/esp32/esp_toolchain package/xtensa/zboot package/xtensa/esptool_py \
           package/xtensa/ztool package/esp32/sdk

TARGET_FLASH_SIZE := 4M
TARGET_FLASH_MODE := qio
TARGET_FLASH_SPEED := 80

TARGET_CPU_SPEED := 80000000
TARGET_BOARD := nodemcu

# This must be last
include $(INCLUDE_DIR)/xtensa/esp32/esp32.inc 

# vim: syntax=make tabstop=4 noexpandtab
