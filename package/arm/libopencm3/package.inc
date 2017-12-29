# /copyright 2017 Zorxx Software, All Rights Reserved
# /license This file is released under the MIT License. See the LICENSE file for details.
# /brief Build environment for libopencm3 package

LIBOPENCM3_DIR := libopencm3_source

INCDIR += $(LIBOPENCM3_DIR)
LIBS +=
LIBDIRS += $(LIBOPENCM3_DIR)
CDEFS +=

# vim: syntax=make tabstop=4 noexpandtab
