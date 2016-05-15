# \copyright 2015-2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief file to be included at the top of each GNU makefile
# This file contains a wide variety of definitions (directories, tools, compiler/linker
#  definitions, etc.). Any of the definitions in this file can be overridden (or appended-to)
#  by the calling makefile.

.DEFAULT_GOAL := all

# Directories
TOPDIR:=$(abspath $(lastword $(MAKEFILE_LIST))/../..)
EXAMPLES_DIR := $(TOPDIR)/examples
INCLUDE_DIR := $(TOPDIR)/include
LIBRARIES_DIR := $(TOPDIR)/lib
PACKAGE_DIR := $(TOPDIR)/package

# Determine host architecture
include $(TOPDIR)/include/host.inc

# Host tools
WGET	:= wget
MKDIR	:= mkdir
RM		:= rm
CD		:= cd
MV		:= mv
UNZIP	:= unzip
TAR		:= tar
GIT		:= git
HG		:= hg
PYTHON	:= python
ECHO	:= echo
TOUCH	:= touch
DATE	:= date
PATCH	:= patch

# Top-level configuration, needed first in order to determine TARGET_ARCH
ifeq ($(MB_OVERRIDE_CONFIG),)
include $(TOPDIR)/config.inc
config_info:
else
include $(MB_OVERRIDE_CONFIG)
config_info:
ifeq ($(MAKELEVEL),0)
	$(info Using override config: $(MB_OVERRIDE_CONFIG))
endif
endif
.PHONY: config_info
TARGET_ARCH := $(strip $(TARGET_ARCH))

ARCH_INCLUDE_DIR := $(INCLUDE_DIR)/$(TARGET_ARCH)
LIB_BIN_DIR := $(LIBRARIES_DIR)/bin_$(TARGET_ARCH)
BUILD_TEMP_DIR := ./build_$(TARGET_ARCH)

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
INCDIR := $(TOPDIR) $(ARCH_INCLUDE_DIR)
LDFLAGS :=
LIBDIRS := $(LIB_BIN_DIR)

# ----------------------------------------------------------------------------------------
# Includes

# Include any archiecture-specific configuration
-include $(ARCH_INCLUDE_DIR)/$(TARGET_ARCH).inc

# Prerequisite includes
-include $(foreach prereq,$(PREREQS),$(TOPDIR)/$(prereq)/package.inc)    

include $(INCLUDE_DIR)/external_helpers.inc
include $(INCLUDE_DIR)/application_helpers.inc

-include ./package.inc

# ----------------------------------------------------------------------------------------
# Compilation/Assembly

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

$(BUILD_TEMP_DIR)/%.o: %.S
	@$(ECHO) "ASM $^"
	@$(MKDIR) -p $(dir $@)
	@$(CC) $(foreach inc,$(call reverse_list,$(INCDIR)),-I$(inc)) $(ASMFLAGS) $(foreach def,$(CDEFS),-D$(def)) -c $^ -o $@

# ----------------------------------------------------------------------------------------
# Dependencies and prerequisites

MISSING_PREREQS = $(foreach req,$(required_prereqs),$(filter-out $(PREREQS),$(req)))

%/.done_$(TARGET_ARCH) :
	@$(ECHO) "Building dependency: $*"
	@$(MAKE) --no-print-directory -C $*
	@$(TOUCH) $@
.PHONY: %/.done_$(TARGET_ARCH)

all:: config_info

# Determine if we're currently building a prerequisite. If so, don't attempt to build any other
#  dependencies (prerequisites), otherwise undesirable recursion will result.
CURRENT_IS_PREREQ = $(filter $(abspath $(CURDIR)),$(foreach prereq,$(PREREQS),$(abspath $(TOPDIR)/$(prereq))))
ifeq ($(CURRENT_IS_PREREQ),)

all:: $(filter-out $(abspath $(CURDIR)/.done_$(TARGET_ARCH)),$(foreach dep,$(PREREQS) $(dependencies),$(abspath $(TOPDIR)/$(dep)/.done_$(TARGET_ARCH))))

endif

# ----------------------------------------------------------------------------------------
# Miscellanous Productions and Functions

# build_clean()
define build_clean
	@$(RM) -rf $(BUILD_TEMP_DIR)
endef

rebuild: clean all
.PHONY: all clean

# vim: syntax=make tabstop=4 noexpandtab
