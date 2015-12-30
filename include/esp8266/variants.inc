# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief file to be included at the top of each GNU makefile

# -------------------------------------------------
# Target boards

# adafruit
BOARD_LD_SCRIPT_adafruit := eagle.flash.4m.ld
BOARD_FLASH_SIZE_adafruit := 4096
BOARD_FLASH_MODE_adafruit := qio
BOARD_FLASH_SPEED_adafruit := 40

# nodemcu
BOARD_LD_SCRIPT_nodemcu := eagle.flash.4m.ld
BOARD_FLASH_SIZE_nodemcu := 4096
BOARD_FLASH_MODE_nodemcu := qio
BOARD_FLASH_SPEED_nodemcu := 40
                          
