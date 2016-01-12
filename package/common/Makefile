# \copyright 2015-2016 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level makefile for common packages

include ../../include/mb.inc

SKIP_DIRS := ignore/ ./
SUBDIRS := $(patsubst %/,%,$(filter-out $(SKIP_DIRS), $(dir $(wildcard */))))

all:
	@$(foreach subdir,$(SUBDIRS),$(if $(findstring $(realpath $(subdir)),$(foreach dir,$(PACKAGES),$(realpath $(PACKAGE_DIR)/$(dir)))),$(ECHO) "Building directory $(subdir)";$(MAKE) --no-print-directory -C $(subdir);,$(ECHO) "Not building directory $(subdir)";))
clean:
	@$(foreach subdir,$(SUBDIRS),$(if $(findstring $(realpath $(subdir)),$(foreach dir,$(PACKAGES),$(realpath $(PACKAGE_DIR)/$(dir)))),$(MAKE) --no-print-directory -C $(subdir) clean;,$(ECHO) "Not cleaning directory $(subdir)";))

# vim: tabstop=4 noexpandtab
