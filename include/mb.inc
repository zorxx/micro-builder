# \copyright 2015-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief file to be included at the top of each GNU makefile
# This file contains a wide variety of definitions (directories, tools, compiler/linker
#  definitions, etc.). Any of the definitions in this file can be overridden (or appended-to)
#  by the calling makefile.

.DEFAULT_GOAL := all

# Directories
TOPDIR:=$(abspath $(lastword $(MAKEFILE_LIST))/../..)
APP_DIR := $(TOPDIR)/app
BIN_DIR := $(TOPDIR)/bin
INCLUDE_DIR := $(TOPDIR)/include
LIBRARIES_DIR := $(TOPDIR)/lib
PACKAGE_DIR := $(TOPDIR)/package
USER_DIR := $(TOPDIR)/user

# Determine host architecture
include $(TOPDIR)/config.inc
include $(TOPDIR)/include/host.inc
include $(TOPDIR)/include/util.inc

# Host tools
WGET	:= wget
MKDIR	:= mkdir
RM	:= rm
CD	:= cd
CP	:= cp
MV	:= mv
UNZIP	:= unzip
TAR	:= tar
GIT	:= git
HG	:= hg
SVN	:= svn
PYTHON	:= python
ECHO	:= echo
TOUCH	:= touch
DATE	:= date
PATCH	:= patch

# ----------------------------------------------------------------------------------------
# Top-level configuration, needed first in order to determine
#  TARGET_ARCH and TARGET_VARIANT

ifndef MB_TARGET
$(error "Need to specify MB_TARGET")
endif
MB_TARGET := $(strip $(MB_TARGET))

TARGET_ARCH := $(firstword $(subst _, ,$(MB_TARGET)))
TARGET_VARIANT := $(subst $(TARGET_ARCH)_,,$(MB_TARGET))
ARCH_INCLUDE_DIR := $(INCLUDE_DIR)/$(TARGET_ARCH)
config_info:
ifeq ($(wildcard $(ARCH_INCLUDE_DIR)/.),)
	$(error "Invalid target architecture $(TARGET_ARCH)")
else
ifeq ($(wildcard $(ARCH_INCLUDE_DIR)/variants/$(TARGET_VARIANT).inc),)
	$(error "Invalid variant $(TARGET_VARIANT) for arch $(TARGET_ARCH)")
endif
endif
.PHONY: config_info

-include $(ARCH_INCLUDE_DIR)/variants/$(TARGET_VARIANT).inc

TARGET_BIN_DIR := $(BIN_DIR)/$(MB_TARGET)
LIB_BIN_DIR := $(TARGET_BIN_DIR)
BUILD_TEMP_DIR := ./.build_$(MB_TARGET)

# ----------------------------------------------------------------------------------------
# Defaults

CFLAGS += -Wall
CPPFLAGS += -Wall
CDEFS +=
ARFLAGS =
ASMFLAGS +=
INCDIR += $(TOPDIR) $(ARCH_INCLUDE_DIR)
LDFLAGS +=
LIBDIRS += $(LIB_BIN_DIR)

# ----------------------------------------------------------------------------------------
# Includes

# Prerequisite includes
-include $(foreach prereq,$(PREREQS),$(TOPDIR)/$(prereq)/package.inc)    
-include $(foreach prereq,$(required_prereqs),$(TOPDIR)/$(prereq)/package.inc)

include $(INCLUDE_DIR)/external_helpers.inc
include $(INCLUDE_DIR)/application_helpers.inc

-include ./package.inc

# ----------------------------------------------------------------------------------------
# Compilation/Assembly

# Save intermediate files in the build directory
.SECONDARY:

# Macro for reversing a list of strings. This is used to reverse the list of include directories
#  because it's defined in order of least-specific to most-specific, but we want the opposite order
#  to allow multiple header files to be named the same thing, and the most-specific include
#  directory (e.g. the application's local include directory) to take precedence (be listed
#  first in the compliation step).
reverse_list = $(if $(1),$(call reverse_list,$(wordlist 2,$(words $(1)),$(1)))) $(firstword $(1))

$(BUILD_TEMP_DIR)/%.o: %.c
	@$(ECHO) "CC $^"
	@$(MKDIR) -p $(dir $@)
	@$(CC) $(foreach inc,$(call reverse_list,$(INCDIR)),-I$(inc)) $(CFLAGS) $(foreach def,$(CDEFS),-D$(def)) -c $^ -o $@

$(BUILD_TEMP_DIR)/%.o: %.cpp
	@$(ECHO) "CPP $^"
	@$(MKDIR) -p $(dir $@)
	@$(CXX) $(foreach inc,$(call reverse_list,$(INCDIR)),-I$(inc)) $(CPPFLAGS) $(foreach def,$(CDEFS),-D$(def)) -c $^ -o $@

$(BUILD_TEMP_DIR)/%.o: %.ino
	@$(ECHO) "INO $^"
	@$(MKDIR) -p $(dir $@)
	@$(CXX) $(foreach inc,$(call reverse_list,$(INCDIR)),-I$(inc)) $(CPPFLAGS) $(foreach def,$(CDEFS),-D$(def)) -c $^ -o $@

$(BUILD_TEMP_DIR)/%.o: %.S
	@$(ECHO) "ASM $^"
	@$(MKDIR) -p $(dir $@)
	@$(CC) $(foreach inc,$(call reverse_list,$(INCDIR)),-I$(inc)) $(ASMFLAGS) $(foreach def,$(CDEFS),-D$(def)) -c $^ -o $@

$(BUILD_TEMP_DIR)/%.o: %.s
	@$(ECHO) "ASM $^"
	@$(MKDIR) -p $(dir $@)
	@$(CC) $(foreach inc,$(call reverse_list,$(INCDIR)),-I$(inc)) $(ASMFLAGS) $(foreach def,$(CDEFS),-D$(def)) -c $^ -o $@

$(BUILD_TEMP_DIR)/%.bin.o : %.html
	@$(ECHO) "BIN $^"
	@$(MKDIR) -p $(dir $@)
	@$(OBJCOPY) -I binary $(OBJCOPYDEFS) $^ $@

$(BUILD_TEMP_DIR)/%.bin.o : %.js
	@$(ECHO) "BIN $^"
	@$(MKDIR) -p $(dir $@)
	@$(OBJCOPY) -I binary $(OBJCOPYDEFS) $^ $@

$(BUILD_TEMP_DIR)/%.bin.o : %.css
	@$(ECHO) "BIN $^"
	@$(MKDIR) -p $(dir $@)
	@$(OBJCOPY) -I binary $(OBJCOPYDEFS) $^ $@

$(BUILD_TEMP_DIR)/%.bin.o : %.png
	@$(ECHO) "BIN $^"
	@$(MKDIR) -p $(dir $@)
	@$(OBJCOPY) -I binary $(OBJCOPYDEFS) $^ $@

# ----------------------------------------------------------------------------------------
# Dependencies and prerequisites

MISSING_PREREQS = $(foreach req,$(required_prereqs),$(filter-out $(PREREQS),$(req)))
DEPENDENCY_DIRS = $(foreach dep,$(PREREQS) $(dependencies),$(abspath $(TOPDIR)/$(dep)))

%/.done_$(MB_TARGET) :
	@$(ECHO) "Building dependency: $*"
	@$(MAKE) --no-print-directory -C $*
	@$(TOUCH) $@
.PHONY: %/.done_$(MB_TARGET)

all:: config_info

# Determine if we're currently building a prerequisite. If so, don't attempt to build any other
#  dependencies (prerequisites), otherwise undesirable recursion will result.
CURRENT_IS_PREREQ = $(filter $(abspath $(CURDIR)),$(foreach prereq,$(PREREQS),$(abspath $(TOPDIR)/$(prereq))))
ifeq ($(CURRENT_IS_PREREQ),)

all:: $(filter-out $(abspath $(CURDIR)/.done_$(MB_TARGET)),$(foreach dep,$(PREREQS) $(dependencies),$(abspath $(TOPDIR)/$(dep)/.done_$(MB_TARGET))))

endif

# ----------------------------------------------------------------------------------------
# Miscellanous Productions and Functions

# build_clean()
define build_clean
	@$(RM) -rf $(BUILD_TEMP_DIR)
endef

rebuild: clean all
.PHONY: all clean

erase_flash:
	@$(call $(TARGET_ARCH)_flash_erase)
.PHONY: erase_flash

flash_boot:
	@$(call $(TARGET_ARCH)_flash_boot)
.PHONY: flash_boot

# vim: syntax=make tabstop=4 noexpandtab
