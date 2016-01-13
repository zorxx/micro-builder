# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Rules for building applications

ifeq ($(filter-out $(PACKAGES),$($(APP_NAME)_package_deps)),)
all: $(BUILD_TEMP_DIR)/$(APP_NAME).out
else
all:
	$(info $(APP_NAME) package dependencies not enabled: $(filter-out $(PACKAGES),$($(APP_NAME)_package_deps)))
endif
clean: $(APP_NAME)_app_clean
flash: $(APP_NAME)_app_flash

# vim: syntax=make tabstop=4 noexpandtab
