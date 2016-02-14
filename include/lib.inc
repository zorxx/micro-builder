# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Rules for building libraries

ifeq ($(MISSING_PREREQS),)

# Dependency includes
-include $(foreach dep,$(dependencies),$(TOPDIR)/$(dep)/package.inc)

# If the LIBRARY_SUBMAKE variable is defined (can be set to anything), spawn a new make
#  process before building the LIBRARY_TARGETS. This is done to allow a single makefile
#  define an arbitrary set of files to be used for building the library (e.g. using the
#  wildcard function) and perform multiple steps where the library source files are generated
#  in the first step and the build is performed in a later step. An example of this is an
#  external package makefile where library source is downloaded in one step and built in
#  a second step in the same makefile.
ifneq ($(LIBRARY_SUBMAKE),)
lib:
	@$(MAKE) --no-print-directory $(foreach lib,$(LIBRARY_TARGETS),$(LIB_BIN_DIR)/$(lib).a)
.PHONY: lib
else
lib: $(foreach lib,$(LIBRARY_TARGETS),$(LIB_BIN_DIR)/$(lib).a)
endif
lib_clean: $(foreach lib,$(LIBRARY_TARGETS),$(lib).library_clean)
	@$(RM) -rf $(BUILD_TEMP_DIR)
lib_info: $(foreach lib,$(LIBRARY_TARGETS),$(lib).library_info)

all:: lib 
clean:: lib_clean 

else

all::
	$(info Missing prerequisite(s): $(MISSING_PREREQS))

endif

# vim: syntax=make tabstop=4 noexpandtab
