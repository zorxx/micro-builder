# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 Arduino toolchain package

include ../../../include/mb.inc

PACKAGE_NAME := esp8266_arduino_toolchain

# Download information
$(PACKAGE_NAME)_SOURCE_METHOD := wget

all: determine_host_options .$(PACKAGE_NAME).download
clean:
	$(call package_clean,$(PACKAGE_NAME))

determine_host_options:
	$(if $(findstring Linux_64,$(HOST_ARCH)), \
		$(eval $(PACKAGE_NAME)_FILENAME := linux64-xtensa-lx106-elf-gb404fb9.tar.gz), \
		$(if $(findstring Linux_32,$(HOST_ARCH)), \
			$(eval $(PACKAGE_NAME)_FILENAME := linux32-xtensa-lx106-elf-gb404fb9.tar.gz), \
			$(if $(findstring WIN,$(HOST_ARCH)), \
				$(eval $(PACKAGE_NAME)_FILENAME := win32-xtensa-lx106-elf-gb404fb9-2.tar.gz), \
				$(if $(findstring OSX,$(HOST_ARCH)), \
					$(eval $(PACKAGE_NAME)_FILENAME := osx-xtensa-lx106-elf-gb404fb9-2.tar.gz), \
					$(error Unsupported host architecture: "$(HOST_ARCH)") \
				) \
			) \
		) \
	)
	$(info Download file: "$($(PACKAGE_NAME)_FILENAME)")
	$(eval $(PACKAGE_NAME)_SOURCE := http://arduino.esp8266.com/$($(PACKAGE_NAME)_FILENAME))


# vim: syntax=make tabstop=4 noexpandtab
