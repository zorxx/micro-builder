# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Rules for building applications

APP_LIBDIRS := $(foreach libdir,$(LIBDIRS),-L$(libdir))
APP_LIBS := $(foreach lib,$(LIBS),-l$(lib))

.SECONDEXPANSION:
$(BUILD_TEMP_DIR)/%.out: $$(%_obj)
	@$(ECHO) "LD $(notdir $@)"
	@$(call $(TARGET_ARCH)_checkboard)
	@$(LD) $(APP_LIBDIRS) $(LDFLAGS) -Wl,-Map=$(addsuffix .map,$(basename $@)) -Wl,--start-group $(foreach lib,$($(basename $(notdir $@))_libs),-l$(lib)) $^ -Wl,--end-group -o $@
	@$(if $(TARGET_ARCH)_post_app,$(call $(TARGET_ARCH)_post_app,$@))

%_app_deps:
	$(if $(filter-out $(PACKAGES),$($*_package_deps)), \
		$(info Missing dependencies: $(filter-out $(PACKAGES),$($*_package_deps))))
%_app_info:
	$(call $(TARGET_ARCH)_app_info,$*.out,$(BUILD_TEMP_DIR))
%_app_flash: $(BUILD_TEMP_DIR)/%.out
	$(call $(TARGET_ARCH)_app_flash,$*.out,$(BUILD_TEMP_DIR))
%_app_clean:
	@$(ECHO) "CLEAN $*.out"
	@$(RM) -rf $(BUILD_TEMP_DIR)

ifeq ($(filter-out $(PACKAGES),$($(APP_NAME)_package_deps)),)
all: $(BUILD_TEMP_DIR)/$(APP_NAME).out
else
all:
	$(info $(APP_NAME) package dependencies not enabled: $(filter-out $(PACKAGES),$($(APP_NAME)_package_deps)))
endif
clean: $(APP_NAME)_app_clean
flash: $(APP_NAME)_app_flash

# vim: syntax=make tabstop=4 noexpandtab
