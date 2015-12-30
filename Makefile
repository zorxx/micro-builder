# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level makefile for 

include include/top.inc

# ----------------------------------------------------------------------------------------
# Top-level productions

all : $(TARGET_ARCH)_externals subdirs
clean : $(TARGET_ARCH)_externals_clean subdirs_clean
    @$(RM) -rf $(EXTERNALS_DIR)/*

# ----------------------------------------------------------------------------------------
# Subdirectories

SUBDIRS := lib examples
subdirs:
	@$(foreach dir,$(SUBDIRS), $(ECHO) "Building subdirectory: $(dir)"; make --no-print-directory -C $(dir);)
subdirs_clean:
	@$(foreach dir,$(SUBDIRS), $(ECHO) "Cleaning subdirectory: $(dir)"; make --no-print-directory -C $(dir) clean;)   	
.PHONY: subdirs subdirs_clean

include include/bottom.inc
