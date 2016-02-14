# \copyright 2016 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level makefile for example applications specific to AVR

include ../../include/mb.inc

SKIP_DIRS := ./ ./ignore/
SUBDIRS := $(filter-out $(SKIP_DIRS), $(dir $(wildcard ./*/)))
all::
	@$(foreach dir,$(SUBDIRS), make --no-print-directory -C $(dir);)
clean::
	@$(foreach dir,$(SUBDIRS), make --no-print-directory -C $(dir) clean;)

# vim: tabstop=4 noexpandtab
