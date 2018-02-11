# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for freertos package

include ../../../include/mb.inc

PACKAGE_NAME := freertos
$(PACKAGE_NAME)_SOURCE_METHOD := svn
$(PACKAGE_NAME)_SOURCE := "https://svn.code.sf.net/p/freertos/code/trunk"

# ----------------------------------------------------------------------------------------

FREERTOS_PORTABLE_SRCDIR := $(FREERTOS_SRCDIR)/portable/$(FREERTOS_COMPILER)/$(FREERTOS_ARCH)

LIB_NAME_FREERTOS := lib$(PACKAGE_NAME)
$(LIB_NAME_FREERTOS)_obj := $(foreach file, \
                $(wildcard $(FREERTOS_SRCDIR)/*.c) \
                $(wildcard $(FREERTOS_PORTABLE_SRCDIR)/*.c), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

ifdef FREERTOS_HEAP_TYPE
FREERTOS_HEAP_FILE := $(FREERTOS_SRCDIR)/portable/MemMang/heap_$(FREERTOS_HEAP_TYPE).c
$(LIB_NAME_FREERTOS)_obj += $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(FREERTOS_HEAP_FILE)))
endif

LIBRARY_TARGETS += $(LIB_NAME_FREERTOS)

# ----------------------------------------------------------------------------------------

EXTERNAL_TARGETS += $(PACKAGE_NAME)
LIBRARY_SUBMAKE := true

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
