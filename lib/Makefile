# \copyright 2015-2017 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level makefile for libraries

include ../include/mb.inc

SUBDIRS := $(TARGET_ARCH)

default: all

$(SUBDIRS)::
	@$(MAKE) -C $@ $(MAKECMDGOALS)
	
all :: $(SUBDIRS)

clean :: $(SUBDIRS)
	@$(RM) -rf $(LIB_BIN_DIR) 

# vim: tabstop=4 noexpandtab
