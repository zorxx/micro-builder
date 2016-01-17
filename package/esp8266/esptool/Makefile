# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 esptool package

include ../../../include/mb.inc

PACKAGE_NAME := esp8266_esptool

# Download information
$(PACKAGE_NAME)_SOURCE_METHOD := wget
ESPTOOL_VERSION := 0.4.6
ESPTOOL_FILE_EXTENSION := tar.gz

all: determine_host_options .$(PACKAGE_NAME).download
	@$(MV) ./source/esptool-$(ESPTOOL_VERSION)-$(ESPTOOL_VARIANT)/* ./source
clean:
	$(call package_clean,$(PACKAGE_NAME))

determine_host_options:
	$(if $(findstring Linux_64,$(HOST_ARCH)), \
		$(eval ESPTOOL_VARIANT := linux64), \
		$(if $(findstring Linux_32,$(HOST_ARCH)), \
			$(eval ESPTOOL_VARIANT := linux32), \
			$(if $(findstring WIN,$(HOST_ARCH)), \
				$(eval ESPTOOL_VARIANT := win32) $(eval ESPTOOL_FILE_EXTENSION := zip), \
				$(if $(findstring OSX,$(HOST_ARCH)), \
					$(eval ESPTOOL_VARIANT := osx), \
					$(error Unsupported host architecture: "$(HOST_ARCH)") \
				) \
			) \
		) \
	)
	$(info Download file: "$($(PACKAGE_NAME)_FILENAME)")
	$(eval $(PACKAGE_NAME)_FILENAME := esptool-$(ESPTOOL_VERSION)-$(ESPTOOL_VARIANT).$(ESPTOOL_FILE_EXTENSION))
	$(eval $(PACKAGE_NAME)_SOURCE := https://github.com/igrr/esptool-ck/releases/download/$(ESPTOOL_VERSION)/$($(PACKAGE_NAME)_FILENAME))

# vim: syntax=make tabstop=4 noexpandtab
