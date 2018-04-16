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

# Rename the source directory to remove the version number
# Ignore all weak functions. Their implementation won't work when linking statically since the weak function
#  is defined in the same compilation unit as it's called, so the linker will always choose the weak function
#  rather than the BSP-defined function we really want
define $(PACKAGE_NAME)_POSTACTION
        $(MV) $(STM32CUBE_SRCDIR)/STM32Cube_*/* $(STM32CUBE_SRCDIR)
        cd ${STM32CUBE_DIR};patch -p1 -i usart_baud.patch
	find ${STM32CUBE_HAL_DIR} -name *.c -exec echo Fix {} \; -exec awk '/^( *)__weak/ {$$3 = "_ignore_"$$3};{print > "tmp.tmp"}' {} \; -exec mv tmp.tmp {} \;
endef

# ----------------------------------------------------------------------------------------
# Library 

LIB_NAME_CORE := lib$(PACKAGE_NAME)
$(LIB_NAME_CORE)_obj := $(foreach file, \
                $(filter-out %_template.c,$(wildcard $(STM32CUBE_HAL_DIR)/Src/*.c)) \
                $(wildcard $(STM32CUBE_COMPONENTS_DIR)/*/*.c) \
                $(wildcard $(STM32CUBE_UTILITIES_DIR)/Fonts/*.c) \
                $(STM32CUBE_LINKINFO_DIR)/gcc/startup_$(call lc,${STM32_CPU}).s, \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

LIBRARY_TARGETS += $(LIB_NAME_CORE)

# ----------------------------------------------------------------------------------------

EXTERNAL_TARGETS += $(PACKAGE_NAME)
LIBRARY_SUBMAKE := true

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
