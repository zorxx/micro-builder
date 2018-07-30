# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Rules for building applications

# ---------------------------------------------------------------------------------------
# Pre-action: things to be done before building an application

.%.app_preaction:
	@$(call $*_PREACTION)
	@$(ECHO) "$(shell $(DATE))" > $@
.PHONY: .%.app_preaction
.PRECIOUS: .%.app_preaction

.$(MB_TARGET).app_preaction:
	@$(call $(MB_TARGET)_APP_PREACTION)
	@$(ECHO) "$(shell $(DATE))" > $@
.PHONY: .$(MB_TARGET).app_preaction
.PRECIOUS: .$(MB_TARGET).app_preaction

# ---------------------------------------------------------------------------------------
# Appliction build

.SECONDEXPANSION:
$(BUILD_TEMP_DIR)/%.elf: .%.app_preaction .$(MB_TARGET).app_preaction $$($$(firstword $$(subst ., ,$$*))_obj)
	@$(ECHO) "LD $(notdir $@)"
	@$(call $(MB_TARGET)_checkboard)
	@$(LD) $(foreach libdir,$(LIBDIRS),-L$(libdir)) $(foreach var,$(subst ., ,$(basename $(notdir $@))),$($(var)_LDFLAGS)) $(LDFLAGS) -Wl,-Map=$(addsuffix .map,$(basename $@)) -Wl,--start-group $(foreach lib,$(LIBS),-l$(lib)) $(foreach lib,$($(basename $(notdir $@))_libs),-l$(lib)) $(filter %.o,$^) -Wl,--end-group -o $@
	@$(if $(MB_TARGET)_post_app,$(call $(MB_TARGET)_post_app,$@))

%_app_info:
	@$(call $(MB_TARGET)_app_info,$*.elf,$(BUILD_TEMP_DIR))
%_flash: $(BUILD_TEMP_DIR)/%.elf
	@$(call $(MB_TARGET)_app_flash,$*.elf,$(BUILD_TEMP_DIR))
%_app_clean:
	@$(ECHO) "CLEAN $*.elf"
	@$(RM) -rf $(BUILD_TEMP_DIR)
	@$(RM) -f .$*.app_preaction
	@$(RM) -f .$(MB_TARGET).app_preaction

# vim: syntax=make tabstop=4 noexpandtab
