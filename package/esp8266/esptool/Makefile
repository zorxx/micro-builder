# \copyright 2015-2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 esptool package

include ../../../include/mb.inc

PACKAGE_NAME := esptool
$(PACKAGE_NAME)_SOURCE_METHOD := wget
ESPTOOL_VERSION := 0.4.11

# Default file extension
ESPTOOL_FILE_EXTENSION := $(if $(findstring WIN,$(HOST_ARCH)),zip,tar.gz)

# Determine the download filename, based on the host architecture
ESPTOOL_VARIANT := $(strip $(if $(findstring Linux_64,$(HOST_ARCH)),linux64, \
                             $(if $(findstring Linux_32,$(HOST_ARCH)),linux32, \
                               $(if $(findstring OSX,$(HOST_ARCH)),osx, \
                                 $(if $(findstring WIN,$(HOST_ARCH)),win32, \
					               unknown)))))
$(PACKAGE_NAME)_FILENAME := esptool-$(ESPTOOL_VERSION)-$(ESPTOOL_VARIANT).$(ESPTOOL_FILE_EXTENSION)
$(PACKAGE_NAME)_SOURCE := https://github.com/igrr/esptool-ck/releases/download/$(ESPTOOL_VERSION)/$($(PACKAGE_NAME)_FILENAME)

# Move the esptool binary to the source directory
define $(PACKAGE_NAME)_POSTACTION
	$(if $(wildcard ./$1/esptool-$(ESPTOOL_VERSION)-$(ESPTOOL_VARIANT)/*),$(shell $(MV) ./$1/esptool-$(ESPTOOL_VERSION)-$(ESPTOOL_VARIANT)/* ./$1))
endef

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
