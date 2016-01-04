# \copyright 2015 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level makefile for ESP8266 libraries

include ../../include/mb.inc

SKIP_DIRS := ./ignore/ ./
SUBDIRS := $(filter-out $(SKIP_DIRS), $(dir $(wildcard ./*/)))
all:
	@$(foreach dir,$(SUBDIRS), make --no-print-directory -C $(dir);)
clean:
	@$(foreach dir,$(SUBDIRS), make --no-print-directory -C $(dir) clean;)

# vim: tabstop=4 noexpandtab
