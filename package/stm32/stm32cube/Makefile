# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for STM32F1 Arduino package

include ../../../include/mb.inc

PACKAGE_NAME := stm32cube

$(PACKAGE_NAME)_FILENAME := en.stm32cube$(call lc,$(STM32_FAMILY)).zip
$(PACKAGE_NAME)_SOURCE_METHOD := archive

define $(PACKAGE_NAME)_PREACTION
	$(if $(wildcard $($(PACKAGE_NAME)_FILENAME)),,$(error The archive $($(PACKAGE_NAME)_FILENAME) must be obtained from https://st.com and copied to $(STM32CUBE_DIR)))
endef

# Rename directory to remove version 
define $(PACKAGE_NAME)_POSTACTION
        $(MV) $(STM32CUBE_SRCDIR)/STM32Cube_*/* $(STM32CUBE_SRCDIR) 
        sed -i /^0/d $(STM32CUBE_LINKINFO_DIR)/gcc/linker/$(call uc,$(STM32_CPU))_FLASH.ld
endef

# ----------------------------------------------------------------------------------------
# Library 

LIB_NAME_CORE := lib$(PACKAGE_NAME)
$(LIB_NAME_CORE)_obj := $(foreach file, \
                $(wildcard $(STM32CUBE_HAL_DIR)/Src/*.c) \
	        $(wildcard $(STM32CUBE_TEMPLATE_DIR)/Src/system_*.c) \
	        $(STM32CUBE_LINKINFO_DIR)/gcc/startup_$(call lc,${STM32_CPU}).s, \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))


LIB_NAME_BSP := lib$(PACKAGE_NAME)_bsp
$(LIB_NAME_BSP)_obj := $(foreach file, \
                $(wildcard $(STM32CUBE_BSP_DIR)/*.c), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

LIBRARY_TARGETS += $(LIB_NAME_CORE) $(LIB_NAME_BSP)

# ----------------------------------------------------------------------------------------

EXTERNAL_TARGETS += $(PACKAGE_NAME)
LIBRARY_SUBMAKE := true

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
