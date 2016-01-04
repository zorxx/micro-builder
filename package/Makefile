# \copyright 2015 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level makefile for packages

include ../include/mb.inc

SUBDIRS := common $(TARGET_ARCH)
all:
	@$(foreach dir,$(SUBDIRS), $(ECHO) "Building subdirectory: $(dir)"; make --no-print-directory -C $(dir);)
clean:
	@$(foreach dir,$(SUBDIRS), $(ECHO) "Cleaning subdirectory: $(dir)"; make --no-print-directory -C $(dir) clean;)
	@$(RM) -rf $(LIB_BIN_DIR) 
.PHONY: all clean

# vim: tabstop=4 noexpandtab
