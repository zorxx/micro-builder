# \copyright 2017-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Rules for generic targets 

ifeq ($(MISSING_PREREQS),)

# Dependency includes
-include $(foreach dep,$(dependencies),$(TOPDIR)/$(dep)/package.inc)

.%.generic:
	@$(call GENERIC_$*)
	@$(ECHO) "$(shell $(DATE))" > $@
.PHONY: .%.generic
.PRECIOUS: .%.generic

.%.generic_clean:
	@$(ECHO) "CLEAN $*"
	@$(RM) -f .$*.generic

all:: $(foreach gen,$(GENERIC_TARGETS),.$(gen).generic)

clean:: $(foreach gen,$(GENERIC_TARGETS),.$(gen).generic_clean)

else
$(error Missing prerequisite(s): $(MISSING_PREREQS))
endif

# vim: syntax=make tabstop=4 noexpandtab
