# \copyright 2015 Zorxx Software, All Rights Reserved.
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level makefile for libraries

include ../include/top.inc

SKIP_DIRS := ./bin/ ./ignore/ ./
SUBDIRS := $(filter-out $(SKIP_DIRS), $(dir $(wildcard ./*/)))
all:
	@$(foreach dir,$(SUBDIRS), make --no-print-directory -C $(dir);)
clean:
	@$(foreach dir,$(SUBDIRS), make --no-print-directory -C $(dir) clean;)
	@$(RM) -rf $(LIB_BIN_DIR) 

include ../include/bottom.inc

