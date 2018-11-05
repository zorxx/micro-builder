# \copyright 2016-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Rules for building external packages

ifeq ($(MISSING_PREREQS),)

EXTERNAL_TARGETS:=$(strip $(EXTERNAL_TARGETS))

all:: $(foreach target,$(EXTERNAL_TARGETS),.$(target).external)
clean:: $(foreach target,$(EXTERNAL_TARGETS),$(target).external_clean)

else
$(error Missing prerequisite(s): $(MISSING_PREREQS))
endif

# vim: syntax=make tabstop=4 noexpandtab
