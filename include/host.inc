# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Rules for determining host architecture

ifeq ($(OS),Windows_NT)
	HOST_ARCH := WIN
	ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
		HOST_ARCH := $(HOST_ARCH)_64
	else
		ifeq ($(PROCESSOR_ARCHITECTURE),x86)
			HOST_ARCH := $(HOST_ARCH)_32
		endif
	endif
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		HOST_ARCH := Linux
	else
		ifeq ($(UNAME_S),Darwin)
			HOST_ARCH := OSX
		else
			$(error "Unsupported host architecture")
		endif
	endif

	UNAME_P := $(shell uname -p)
	ifeq ($(UNAME_P),x86_64)
		HOST_ARCH := $(HOST_ARCH)_64
	endif
	ifneq ($(filter %86,$(UNAME_P)),)
		HOST_ARCH := $(HOST_ARCH)_32
	endif
endif

# vim: syntax=make tabstop=4 noexpandtab
