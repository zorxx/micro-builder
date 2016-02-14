# \copyright 2015-2016 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level makefile for common packages

include ../../include/mb.inc

SKIP_DIRS := ignore/ ./
SUBDIRS := $(patsubst %/,%,$(filter-out $(SKIP_DIRS), $(dir $(wildcard */))))

all::
	@$(foreach subdir,$(SUBDIRS),$(ECHO) "Building subdirectory $(subdir)";$(MAKE) --no-print-directory -C $(subdir);)
clean::
	@$(foreach subdir,$(SUBDIRS),$(ECHO) "Cleaning subdirectory $(subdir)";$(MAKE) --no-print-directory -C $(subdir) clean;)

# vim: tabstop=4 noexpandtab
