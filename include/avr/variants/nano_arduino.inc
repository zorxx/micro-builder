# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief nano Arduino Variant

PREREQS := package/avr/arduino

TARGET_CPU := ATmega328
TARGET_MCU := atmega328p
TARGET_CPU_SPEED := 16000000

# This must be last
include $(INCLUDE_DIR)/avr/avr.inc 

# vim: syntax=make tabstop=4 noexpandtab
