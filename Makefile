# \copyright 2015-2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level makefile for micro-builder 

include include/mb.inc

# ----------------------------------------------------------------------------------------
# Top-level productions: build any directory that might contain a prerequisite. Sub-makefiles
#  will filter-out directories that aren't included in the list of enabled prerequisites.

PREREQ_DIRS := package lib

all::
	@$(foreach subdir,$(PREREQ_DIRS),$(ECHO) "Building subdirectory: $(subdir)";$(MAKE) --no-print-directory -C $(subdir);)
clean::
	@$(foreach subdir,$(PREREQ_DIRS),$(ECHO) "Cleaning subdirectory: $(subdir)";$(MAKE) --no-print-directory -C $(subdir) clean;)   	

# vim: tabstop=4 noexpandtab
