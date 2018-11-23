# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top make include file for STM32F1 architectures

include $(INCLUDE_DIR)/arm/stm32/stm32.inc

CFLAGS += -march=armv7-m
CPPFLAGS += -march=armv7-m

# vim: syntax=make tabstop=4 noexpandtab
