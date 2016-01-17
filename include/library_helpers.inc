# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Rules for building libraries

.SECONDEXPANSION:
$(LIB_BIN_DIR)/%.a: $$($$*_obj)
	@$(ECHO) "AR $(notdir $@)"
	@$(MKDIR) -p $(dir $@)
	@$(AR) rcs $@ $(filter %.o, $^)
	@$(if $(TARGET_ARCH)_post_lib,$(call $(TARGET_ARCH)_post_lib,$@))
.PRECIOUS: $(BUILD_TEMP_DIR)/%.o

%.library_info:
	@$(OBJDUMP) -ft $(LIB_BIN_DIR)/$*.a

# library_clean(name)
%.library_clean:
	@$(ECHO) "CLEAN $*.a"
	@$(RM) -f $(LIB_BIN_DIR)/$*.a
.PHONY: %.library_clean

# build_library(name)
define build_library
	$(MAKE) --no-print-directory $(LIB_BIN_DIR)/$1.a
endef

# vim: syntax=make tabstop=4 noexpandtab
