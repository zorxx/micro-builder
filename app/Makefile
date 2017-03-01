# \copyright 2015-2017 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level makefile for example applications

include ../include/mb.inc

SUBDIRS := $(TARGET_ARCH)

default: all

$(SUBDIRS)::
	@$(echo Building $@)
	@$(MAKE) -C $@ $(MAKECMDGOALS)
	
all clean :: $(SUBDIRS)

# vim: tabstop=4 noexpandtab
