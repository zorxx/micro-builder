#\copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment configuration for STM32cube package

STM32CUBE_DIR := $(PACKAGE_DIR)/stm32/stm32cube
STM32CUBE_SRCDIR := $(STM32CUBE_DIR)/stm32cube_source
STM32CUBE_HAL_DIR := $(STM32CUBE_SRCDIR)/Drivers/STM32${STM32_FAMILY}xx_HAL_Driver
STM32CUBE_LINKINFO_DIR := $(STM32CUBE_SRCDIR)/Drivers/CMSIS/Device/ST/STM32${STM32_FAMILY}xx/Source/Templates

APP_LD_DIR = $(STM32CUBE_LINKINFO_DIR)/gcc/linker
APP_LD_SCRIPT = $(APP_LD_DIR)/$(call uc,$(STM32_CPU))_FLASH.ld

INCDIR += ${STM32CUBE_HAL_DIR}/Inc
INCDIR += ${STM32CUBE_SRCDIR}/Drivers/CMSIS/Device/ST/STM32${STM32_FAMILY}xx/Include
INCDIR += ${STM32CUBE_SRCDIR}/Drivers/CMSIS/Include

LIBS += stm32cube

# vim: syntax=make tabstop=4 noexpandtab
