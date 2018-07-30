# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Rules for building applications

ifeq ($(MISSING_PREREQS),)

# Dependency includes
-include $(foreach dep,$(dependencies),$(TOPDIR)/$(dep)/package.inc)

ifneq ($(APP_VARIANTS),)
APP_TARGETS := $(foreach var,$(APP_VARIANTS),$(foreach app,$(APP_TARGETS),$(app).$(var)))
endif

all:: $(foreach app,$(APP_TARGETS),$(BUILD_TEMP_DIR)/$(app).elf)

clean:: $(foreach app,$(APP_TARGETS),$(app)_app_clean)

# If the user just runs "make flash", flash the first application listed in the makefile
flash: $(firstword $(APP_TARGETS))_flash

# If the user just runs "make info", show info for the first application listed in the makefile
info: $(firstword $(APP_TARGETS))_app_info

else

all::
	$(info Missing prerequisite(s): $(MISSING_PREREQS))

endif

# vim: syntax=make tabstop=4 noexpandtab
