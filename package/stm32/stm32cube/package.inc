#\copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment configuration for STM32cube package

STM32CUBE_DIR := $(PACKAGE_DIR)/stm32/stm32cube
STM32CUBE_SRCDIR := $(STM32CUBE_DIR)/stm32cube_source
STM32CUBE_HAL_DIR := $(STM32CUBE_SRCDIR)/Drivers/STM32${STM32_FAMILY}xx_HAL_Driver
STM32CUBE_COMPONENTS_DIR := $(STM32CUBE_SRCDIR)/Drivers/BSP/Components
STM32CUBE_UTILITIES_DIR := $(STM32CUBE_SRCDIR)/Utilities
STM32CUBE_LINKINFO_DIR := $(STM32CUBE_SRCDIR)/Drivers/CMSIS/Device/ST/STM32${STM32_FAMILY}xx/Source/Templates

STM32CUBE_COMPONENTS := ak4343 Common cs43l22 hx8347d ili9320 ili9325 lis302dl spfd5408 st7735 stlm75 stmpe811
STM32CUBE_UTILITIES := Fonts

INCDIR += ${STM32CUBE_HAL_DIR}/Inc
INCDIR += ${STM32CUBE_SRCDIR}/Drivers/CMSIS/Device/ST/STM32${STM32_FAMILY}xx/Include
INCDIR += ${STM32CUBE_SRCDIR}/Drivers/CMSIS/Include
INCDIR += $(foreach comp,$(STM32CUBE_COMPONENTS),$(STM32CUBE_COMPONENTS_DIR)/$(comp))
INCDIR += $(STM32CUBE_UTILITIES_DIR)

LIBS += stm32cube

# vim: syntax=make tabstop=4 noexpandtab
