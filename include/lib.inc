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

# library_info(name)
define library_info
	$(OBJDUMP) -ft $(LIB_BIN_DIR)/$1.a
endef

# library_clean(name)
define library_clean
	$(ECHO) "CLEAN $1.a"
	$(RM) -f $(LIB_BIN_DIR)/$1.a
endef

# build_library(name)
define build_library
	$(MAKE) --no-print-directory $(LIB_BIN_DIR)/$1.a
endef

ifeq ($(filter-out $(PACKAGES),$($(LIB_NAME)_package_deps)),)
all: $(LIB_BIN_DIR)/$(LIB_NAME).a
else
all:
	$(info $(LIB_NAME) package dependencies not enabled: $(filter-out $(PACKAGES),$($(LIB_NAME)_package_deps)))
endif
clean:
	@$(call library_clean,$(LIB_NAME))
	@$(call build_clean)

# vim: syntax=make tabstop=4 noexpandtab
