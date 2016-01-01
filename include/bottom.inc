# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief File to be included at the bottom of each GNU makefile 
# This file contains GNU make productions that are useful for a variety of actions, such
#  as creation of libraries and applications

-include $(TOPDIR)/include/$(TARGET_ARCH)/$(TARGET_ARCH)_bottom.inc
include $(TOPDIR)/include/package.inc

# build_clean()
define build_clean
	@$(RM) -rf $(BUILD_TEMP_DIR)
endef

# ----------------------------------------------------------------------------------------
# Compilation

DEFS := $(foreach def,$(CDEFS),-D$(def))
C_INC := $(foreach inc,$(INCDIR) $(PACKAGE_INCDIRS),-I$(inc))
$(BUILD_TEMP_DIR)/%.o: %.c
	@$(ECHO) "CC $(filter %.c, $^)"
	@$(MKDIR) -p $(dir $@)
	@$(CC) $(C_INC) $(CFLAGS) $(DEFS) -c $(filter %.c, $^) -o $@

$(BUILD_TEMP_DIR)/%.o: %.cpp
	@$(ECHO) "CC $(filter %.cpp, $^)"
	@$(MKDIR) -p $(dir $@)
	@$(CC) $(C_INC) $(CPPFLAGS) $(DEFS) -c $(filter %.cpp, $^) -o $@

# ----------------------------------------------------------------------------------------
# Library

.SECONDEXPANSION:
$(LIB_BIN_DIR)/%.a: $(BUILD_TEMP_DIR)/$$(%_obj)
	@$(ECHO) "AR $(notdir $@)"
	@$(MKDIR) -p $(dir $@)
	@$(AR) rcs $@ $(filter %.o, $^)
	@$(if $(TARGET_ARCH)_post_lib,$(call $(TARGET_ARCH)_post_lib,$@))
.PRECIOUS: $(BUILD_TEMP_DIR)/%.o

# library_info(name)
define library_info
	@$(OBJDUMP) -ft $(LIB_BIN_DIR)/$1.a
endef

# library_clean(name)
define library_clean
	@$(ECHO) "CLEAN $1.a"
	@$(RM) -f $(LIB_BIN_DIR)/$1.a
endef

# ----------------------------------------------------------------------------------------
# Application

APP_OBJ := $(patsubst %.c, $(BUILD_TEMP_DIR)/%.o, $(SRC))
APP_LIBDIRS := $(foreach libdir,$(LIBDIRS),-L$(libdir))
APP_LIBS := $(foreach lib,$(LIBS),-l$(lib))
APP_FILENAME := $(APP_NAME).out
APP_OUT	:= $(BUILD_TEMP_DIR)/$(APP_FILENAME)

.SECONDEXPANSION:
$(BUILD_TEMP_DIR)/%.out: $(BUILD_TEMP_DIR)/$$(%_obj)
	@$(ECHO) "LD $(notdir $@)"
	@$(call $(TARGET_ARCH)_checkboard)
	@$(LD) -flto $(APP_LIBDIRS) $(LDFLAGS) -Wl,-Map=$(addsuffix .map,$(basename $@)) -Wl,--start-group $(foreach lib,$($(basename $(notdir $@))_libs),-l$(lib)) $^ -Wl,--end-group -o $@
	@$(if $(TARGET_ARCH)_post_app,$(call $(TARGET_ARCH)_post_app,$@))

app: $(APP_OUT)
app_info:
	$(call $(TARGET_ARCH)_app_info)
app_flash: app
	$(call $(TARGET_ARCH)_app_flash)
app_clean:
	@$(ECHO) "CLEAN $(APP_FILENAME)"
	@$(RM) -rf $(BUILD_TEMP_DIR)

# ----------------------------------------------------------------------------------------
# Miscellanous Productions

rebuild: clean all
       
# vim: syntax=make tabstop=4 noexpandtab
