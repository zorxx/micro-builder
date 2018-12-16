# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Build environment for freertos package

FREERTOS_VERSION := 10.1.1
FREERTOS_DIR := $(PACKAGE_DIR)/common/freertos
FREERTOS_SRCDIR := freertos_source/FreeRTOSv$(FREERTOS_VERSION)/FreeRTOS/Source/

INCDIR += $(FREERTOS_DIR)/$(FREERTOS_SRCDIR)/include
INCDIR += $(FREERTOS_DIR)/$(FREERTOS_SRCDIR)/portable/$(FREERTOS_COMPILER)/$(FREERTOS_ARCH)

LIBS += freertos 

# vim: syntax=make tabstop=4 noexpandtab
