# \copyright 2017 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Ameba variant 

PREREQS := package/arm/toolchain package/ameba/sdk

APP_LD_SCRIPT := $(ARCH_INCLUDE_DIR)/ameba/ld/rlx8195a.ld
CDEFS += CONFIG_PLATFORM_8195A

# This must be last
include $(INCLUDE_DIR)/arm/ameba/ameba.inc 

# vim: syntax=make tabstop=4 noexpandtab
