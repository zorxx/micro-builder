# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Rules for building applications

.SECONDEXPANSION:
$(BUILD_TEMP_DIR)/%.elf: $$(%_obj)
	@$(ECHO) "LD $(notdir $@)"
	@$(call $(TARGET_ARCH)_checkboard)
	@$(LD) $(foreach libdir,$(LIBDIRS),-L$(libdir)) $(LDFLAGS) -Wl,-Map=$(addsuffix .map,$(basename $@)) -Wl,--start-group $(foreach lib,$(LIBS),-l$(lib)) $(foreach lib,$($(basename $(notdir $@))_libs),-l$(lib)) $^ -Wl,--end-group -o $@
	@$(if $(TARGET_ARCH)_post_app,$(call $(TARGET_ARCH)_post_app,$@))

%_app_info:
	@$(call $(TARGET_ARCH)_app_info,$*.elf,$(BUILD_TEMP_DIR))
%_flash: $(BUILD_TEMP_DIR)/%.elf
	@$(call $(TARGET_ARCH)_app_flash,$*.elf,$(BUILD_TEMP_DIR))
%_app_clean:
	@$(ECHO) "CLEAN $*.elf"
	@$(RM) -rf $(BUILD_TEMP_DIR)

# vim: syntax=make tabstop=4 noexpandtab
