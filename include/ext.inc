# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Rules for building external packages

all:: $(foreach target,$(EXTERNAL_TARGETS),.$(target).external)
clean:: $(foreach target,$(EXTERNAL_TARGETS),$(target).external_clean)

# vim: syntax=make tabstop=4 noexpandtab
