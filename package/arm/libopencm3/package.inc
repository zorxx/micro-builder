# /copyright 2017-2018 Zorxx Software, All Rights Reserved
# /license This file is released under the MIT License. See the LICENSE file for details.
# /brief Build environment for libopencm3 package

LIBOPENCM3_DIR := $(PACKAGE_DIR)/arm/libopencm3/libopencm3_source

INCDIR += $(LIBOPENCM3_DIR)/include
LIBDIRS += $(LIBOPENCM3_DIR)/lib

# vim: syntax=make tabstop=4 noexpandtab
