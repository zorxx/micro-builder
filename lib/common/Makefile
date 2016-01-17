# \copyright 2015-2016 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level makefile for common libraries

include ../../include/mb.inc

SKIP_DIRS := ./ignore/ ./
SUBDIRS := $(filter-out $(SKIP_DIRS), $(dir $(wildcard ./*/)))

PREREQ_DIRS := $(foreach subdir,$(SUBDIRS),$(if $(findstring $(realpath $(subdir)),$(foreach prereq,$(PREREQS),$(realpath $(TOPDIR)/$(prereq)))),$(subdir)))

all::
	@$(foreach subdir,$(PREREQ_DIRS),$(ECHO) "Building prerequisite $(subdir)";$(MAKE) --no-print-directory -C $(subdir);)
clean::
	@$(foreach subdir,$(PREREQ_DIRS),$(ECHO) "Cleaning prerequisite $(subdir)";$(MAKE) --no-print-directory -C $(subdir) clean;)

# vim: tabstop=4 noexpandtab
