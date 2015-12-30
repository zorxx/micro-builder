# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief File to be included at the bottom of each GNU makefile 
# This file contains GNU make productions that are useful for a variety of actions, such
#  as creation of libraries and applications

-include $(TOPDIR)/include/$(TARGET_ARCH)/$(TARGET_ARCH)_bottom.inc

# ----------------------------------------------------------------------------------------
# Compilation

DEFS := $(foreach def,$(CDEFS),-D$(def))
C_INC := $(foreach inc,$(INCDIR),-I$(inc))
$(BUILD_TEMP_DIR)/%.o: $(BUILD_TEMP_DIR) %.c
	@$(ECHO) "CC $(filter %.c, $^)"
	@$(CC) $(C_INC) $(CFLAGS) $(DEFS) -c $(filter %.c, $^) -o $@

$(BUILD_TEMP_DIR)/%.o: $(BUILD_TEMP_DIR) %.cpp
	@$(ECHO) "CC $(filter %.cpp, $^)"
	@$(CC) $(C_INC) $(CPPFLAGS) $(DEFS) -c $(filter %.cpp, $^) -o $@

$(BUILD_TEMP_DIR):
	@$(MKDIR) -p $@

# ----------------------------------------------------------------------------------------
# Library

LIB_OBJ := $(patsubst %.c, $(BUILD_TEMP_DIR)/%.o, $(SRC)) $(patsubst %.cpp, $(BUILD_TEMP_DIR)/%.o, $(SRC))
LIB_FILENAME := lib$(LIB_NAME).a
LIB_OUT := $(LIB_BIN_DIR)/$(LIB_FILENAME)
$(LIB_OUT): $(LIB_BIN_DIR) $(LIB_OBJ)
	@$(ECHO) "AR $(LIB_FILENAME)"
	@$(AR) rcs $@ $(filter %.o, $^)
.PRECIOUS: $(LIB_OBJ)

$(LIB_BIN_DIR):
	@$(MKDIR) -p $@

library: $(LIB_OUT) $(TARGET_ARCH)_post_lib
library_info: library
	@$(OBJDUMP) -ft $^
library_clean:
	@$(ECHO) "CLEAN $(LIB_FILENAME)"
	@$(RM) -f $(LIB_OUT)
	@$(RM) -rf $(BUILD_TEMP_DIR)
.PHONY: library_clean

# ----------------------------------------------------------------------------------------
# Application

APP_OBJ := $(patsubst %.c, $(BUILD_TEMP_DIR)/%.o, $(SRC))
APP_LIBDIRS := $(foreach libdir,$(LIBDIRS),-L$(libdir))
APP_LIBS := $(foreach lib,$(LIBS),-l$(lib))
APP_FILENAME := $(APP_NAME).out
APP_OUT	:= $(addprefix $(BUILD_TEMP_DIR)/,$(APP_FILENAME))
$(APP_OUT): $(APP_OBJ)
	@$(ECHO) "LD $(APP_FILENAME)"
	@$(LD) -flto $(APP_LIBDIRS) $(LDFLAGS) -Wl,--start-group $(APP_LIBS) $^ -Wl,--end-group -o $@

app: checkboard $(APP_OUT) $(TARGET_ARCH)_post_app
app_info: $(TARGET_ARCH)_app_info
app_flash: app $(TARGET_ARCH)_app_flash
app_clean:
	@$(ECHO) "CLEAN $(APP_FILENAME)"
	@$(RM) -rf $(BUILD_TEMP_DIR)

# ----------------------------------------------------------------------------------------
# Miscellanous Productions

rebuild: clean all

checkboard:
    ifeq ($(BOARD_LD_SCRIPT_$(TARGET_BOARD)),)
    $(error "Invalid board type specification ($(TARGET_BOARD))")
    endif
       
