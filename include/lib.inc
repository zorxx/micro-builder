# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Rules for building libraries

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
