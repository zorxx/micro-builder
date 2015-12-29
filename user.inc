# \copyright 2015 Zorxx Software, All Rights Reserved
# \copyright (c) 2010 Espressif System
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief User-specific settings, including target hardware type and connection settings

# Serial port and baud rate for programming (flashing)
TARGET_PORT ?= COM14
TARGET_BAUD ?= 256000

# Target board type
# Valid options:
#   adafruit
#   nodemcu
TARGET_BOARD ?= nodemcu

# TODO: Implement flash filesystem support, with configuration

