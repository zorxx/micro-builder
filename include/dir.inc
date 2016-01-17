# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Rules for building a directory

all::
	@$(ECHO) "$(shell $(DATE))" > .done
clean::
	@$(RM) -f .done

# vim: syntax=make tabstop=4 noexpandtab
