# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief file to be included at the top of each GNU makefile
# This file contains a wide variety of definitions (directories, tools, compiler/linker
#  definitions, etc.). Any of the definitions in this file can be overridden (or appended-to)
#  by the calling makefile.

.DEFAULT_GOAL := all

# Directories
TOPDIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/..
EXAMPLES_DIR := $(TOPDIR)/examples
INCLUDE_DIR := $(TOPDIR)/include
LIBRARIES_DIR := $(TOPDIR)/lib
LIB_BIN_DIR := $(LIBRARIES_DIR)/bin
PACKAGE_DIR := $(TOPDIR)/package
BUILD_TEMP_DIR := ./build

# Host tools
WGET	:= wget
MKDIR	:= mkdir
RM		:= rm
CD		:= cd
UNZIP	:= unzip
TAR		:= tar
GIT		:= git
PYTHON	:= python
ECHO	:= echo
TOUCH	:= touch
DATE	:= date
PATCH	:= patch

# Top-level configuration, needed first in order to determine TARGET_ARCH
include $(TOPDIR)/config.inc
ARCH_INCLUDE_DIR := $(INCLUDE_DIR)/$(TARGET_ARCH)

# ----------------------------------------------------------------------------------------
# Defaults

# Host tools
CC		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)gcc
CXX		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)g++
AR		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)ar
LD		:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)g++
OBJCOPY	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)objcopy
OBJDUMP	:= $(TOOLCHAIN_BIN_DIR)/$(TOOLCHAIN_PREFIX)objdump

CFLAGS :=
CPPFLAGS :=
CDEFS :=
ASMFLAGS :=
INCDIR := . include $(TOPDIR) $(TOPDIR)/lib $(TOPDIR)/include $(ARCH_INCLUDE_DIR)
LDFLAGS :=
LIBDIRS := $(LIB_BIN_DIR)

# ----------------------------------------------------------------------------------------
# Application

# Include any archiecture-specific configuration
-include $(TOPDIR)/include/$(TARGET_ARCH)/$(TARGET_ARCH).inc

# Rules for handling packages (downloading, etc.)
include $(TOPDIR)/include/package.inc

# ----------------------------------------------------------------------------------------
# Compilation/Assembly

DEFS := $(foreach def,$(CDEFS),-D$(def))
C_INC := $(foreach inc,$(INCDIR) $(PACKAGE_INCDIRS),-I$(inc))
$(BUILD_TEMP_DIR)/%.o: %.c
	@$(ECHO) "CC $^"
	@$(MKDIR) -p $(dir $@)
	@$(CC) $(C_INC) $(CFLAGS) $(DEFS) -c $^ -o $@

$(BUILD_TEMP_DIR)/%.o: %.cpp
	@$(ECHO) "CPP $^"
	@$(MKDIR) -p $(dir $@)
	@$(CXX) $(C_INC) $(CPPFLAGS) $(DEFS) -c $^ -o $@

$(BUILD_TEMP_DIR)/%.o: %.S
	@$(ECHO) "ASM $^"
	@$(MKDIR) -p $(dir $@)
	@$(CC) $(C_INC) $(ASMFLAGS) $(DEFS) -c $^ -o $@

# ----------------------------------------------------------------------------------------
# Library

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

# ----------------------------------------------------------------------------------------
# Application

APP_LIBDIRS := $(foreach libdir,$(LIBDIRS),-L$(libdir))
APP_LIBS := $(foreach lib,$(LIBS),-l$(lib))

.SECONDEXPANSION:
$(BUILD_TEMP_DIR)/%.out: $$(%_obj)
	@$(ECHO) "LD $(notdir $@)"
	@$(call $(TARGET_ARCH)_checkboard)
	@$(LD) $(APP_LIBDIRS) $(LDFLAGS) -Wl,-Map=$(addsuffix .map,$(basename $@)) -Wl,--start-group $(foreach lib,$($(basename $(notdir $@))_libs),-l$(lib)) $^ -Wl,--end-group -o $@
	@$(if $(TARGET_ARCH)_post_app,$(call $(TARGET_ARCH)_post_app,$@))

%_app_info:
	$(call $(TARGET_ARCH)_app_info,$*.out,$(BUILD_TEMP_DIR))
%_app_flash: $(BUILD_TEMP_DIR)/%.out
	$(call $(TARGET_ARCH)_app_flash,$*.out,$(BUILD_TEMP_DIR))
%_app_clean:
	@$(ECHO) "CLEAN $*.out"
	@$(RM) -rf $(BUILD_TEMP_DIR)

# ----------------------------------------------------------------------------------------
# Miscellanous Productions and Functions

# build_clean()
define build_clean
	@$(RM) -rf $(BUILD_TEMP_DIR)
endef

rebuild: clean all

# vim: syntax=make tabstop=4 noexpandtab
