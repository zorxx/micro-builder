# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level makefile for micro-builder 

include include/mb.inc

# ----------------------------------------------------------------------------------------
# Top-level productions

all : subdirs
clean : subdirs_clean

# ----------------------------------------------------------------------------------------
# Subdirectories

SUBDIRS := package lib examples
subdirs:
	@$(foreach dir,$(SUBDIRS), $(ECHO) "Building subdirectory: $(dir)"; make --no-print-directory -C $(dir);)
subdirs_clean:
	@$(foreach dir,$(SUBDIRS), $(ECHO) "Cleaning subdirectory: $(dir)"; make --no-print-directory -C $(dir) clean;)   	
.PHONY: subdirs subdirs_clean

# vim: tabstop=4 noexpandtab
