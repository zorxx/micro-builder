# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Board variants for the ESP8266 architecture

# -------------------------------------------------
# Target boards

# adafruit
# Adafruit HUZZAH (https://www.adafruit.com/products/2471)
BOARD_LD_SCRIPT_adafruit := eagle.flash.1m.ld
BOARD_FLASH_SIZE_adafruit := 32M
BOARD_FLASH_MODE_adafruit := qio
BOARD_FLASH_SPEED_adafruit := 40

# nodemcu
BOARD_LD_SCRIPT_nodemcu := eagle.flash.1m.ld
BOARD_FLASH_SIZE_nodemcu := 32M
BOARD_FLASH_MODE_nodemcu := dio
BOARD_FLASH_SPEED_nodemcu := 40

# vim: syntax=make tabstop=4 noexpandtab
