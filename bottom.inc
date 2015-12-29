# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief File to be included at the bottom of each GNU makefile 
# This file contains GNU make productions that are useful for a variety of actions, such
#  as creation of libraries and applications

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

library: $(LIB_OUT)
library_info: $(LIB_OUT)
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
	@$(LD) -flto $(APP_LIBDIRS) -T$(APP_LD_SCRIPT) $(LDFLAGS) -Wl,--start-group $(APP_LIBS) $^ -Wl,--end-group -o $@
	@$(ESPTOOL) elf2image $@ -o$(BUILD_TEMP_DIR)/ $(flashimageoptions)

app: checkboard $(APP_OUT)
app_info: app
	@$(OBJDUMP) -h -j .data -j .rodata -j .bss -j .text -j .irom0.text $(APP_OUT)
app_clean:
	@$(ECHO) "CLEAN $(APP_FILENAME)"
	@$(RM) -rf $(BUILD_TEMP_DIR)

app_flash: app
	@$(ECHO) "Flashing at: $(foreach file,$(wildcard $(BUILD_TEMP_DIR)/0x*.bin),$(notdir $(basename $(file))))"
	@$(ESPTOOL) -p $(TARGET_PORT) -b $(TARGET_BAUD) write_flash $(foreach file,$(wildcard $(BUILD_TEMP_DIR)/0x*.bin),$(notdir $(basename $(file))) $(file))

# ----------------------------------------------------------------------------------------
# Miscellanous Productions

rebuild: clean all

checkboard:
    ifeq ($(BOARD_LD_SCRIPT_$(TARGET_BOARD)),)
    $(error "Invalid board type specification ($(TARGET_BOARD))")
    endif
       
