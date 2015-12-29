# \copyright 2015 Zorxx Software, All Rights Reserved
# \copyright (c) 2010 Espressif System
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Settings specific to hardware variants

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
