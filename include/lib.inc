# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Rules for building libraries

# Dependency includes
ifeq ($(MISSING_PREREQS),)
-include $(foreach dep,$(dependencies),$(TOPDIR)/$(dep)/package.inc)
endif

# ----------------------------------------------------------------------------------------

$(LIB_BIN_DIR)/%.a: $$($$*_obj)
	@$(ECHO) "AR $(notdir $@)"
	@$(MKDIR) -p $(dir $@)
	@@$(AR) rcs $(ARFLAGS) $@ $(filter %.o, $^)
	@$(if $(MB_TARGET)_post_lib,$(call $(MB_TARGET)_post_lib,$@))
.PRECIOUS: $(BUILD_TEMP_DIR)/%.o

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

# ----------------------------------------------------------------------------------------

%.library_info:
	@$(OBJDUMP) -ft $(LIB_BIN_DIR)/$*.a

lib_info: $(foreach lib,$(LIBRARY_TARGETS),$(lib).library_info)

# ----------------------------------------------------------------------------------------

# library_clean(name)
%.library_clean:
	@$(ECHO) "CLEAN $*.a"
	@$(RM) -f $(LIB_BIN_DIR)/$*.a
.PHONY: %.library_clean

lib_clean: $(foreach lib,$(LIBRARY_TARGETS),$(lib).library_clean)
	@$(RM) -rf $(BUILD_TEMP_DIR)

# ----------------------------------------------------------------------------------------

ifeq ($(MISSING_PREREQS),)
all:: lib 
else
all::
	$(info Missing prerequisite(s): $(MISSING_PREREQS))
endif

clean:: lib_clean 

# vim: syntax=make tabstop=4 noexpandtab
