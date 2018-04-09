# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for stm32cube_bsp package

STM32CUBE_BSP_DIR := $(PACKAGE_DIR)/stm32/stm32cube_bsp/stm32cube_bsp_source
STM32CUBE_BSP_SRCDIR := $(STM32CUBE_BSP_DIR)/stm32$(call lc,$(STM32_FAMILY))/$(STM32_BSP)
INCDIR += $(STM32CUBE_BSP_SRCDIR)
LIBS += stm32cube_bsp

# vim: syntax=make tabstop=4 noexpandtab
