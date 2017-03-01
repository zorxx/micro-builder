# \copyright 2015-2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level makefile for micro-builder 

include include/mb.inc

# ----------------------------------------------------------------------------------------
# Top-level productions: build any directory that might contain a prerequisite. Sub-makefiles
#  will filter-out directories that aren't included in the list of enabled prerequisites.

SUBDIRS := package lib app

default: all

$(SUBDIRS)::
	@$(MAKE) -C $@ $(MAKECMDGOALS)
	
all clean :: $(SUBDIRS)

# vim: tabstop=4 noexpandtab
