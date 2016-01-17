# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Rules for building applications

# Dependency includes
-include $(foreach dep,$(dependencies),$(TOPDIR)/$(dep)/package.inc)

# First, make sure all dependencies have been built
all:: $(foreach dep,$(dependencies),$(TOPDIR)/$(dep)/.done)
all:: $(foreach app,$(APP_TARGETS),$(BUILD_TEMP_DIR)/$(app).elf)

clean:: $(foreach app,$(APP_TARGETS),$(app)_app_clean)

# If the user just runs "make flash", flash the first application listed in the makefile
flash: $(firstword $(APP_TARGETS))_flash

# vim: syntax=make tabstop=4 noexpandtab
