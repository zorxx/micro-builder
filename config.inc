# \copyright 2015-2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level configuration

ifeq ($(OS),Windows_NT)
TARGET_PORT ?= COM1
else
TARGET_PORT ?= /dev/ttyUSB0
endif

TARGET_BAUD=230400

# vim: syntax=make tabstop=4 noexpandtab
