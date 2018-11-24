# /copyright 2017-2018 Zorxx Software, All Rights Reserved
# /license This file is released under the MIT License. See the LICENSE file for details.
# /brief Build environment for libopencm3 package

include $(PACKAGE_DIR)/arm/libopencm3/package.inc
OPENCM3_DIR := $(LIBOPENCM3_DIR)
-include $(LIBOPENCM3_DIR)/mk/genlink-config.mk

APP_LD_SCRIPT = $(LDSCRIPT)
APP_LD_DIR = $(BUILD_TEMP_DIR)

CFLAGS += $(genlink_cppflags)
CPPFLAGS += $(genlink_cppflags)
LDFLAGS += $(ARCH_FLAGS) $(shell $(OPENCM3_DIR)/scripts/genlink.py $(DEVICES_DATA) $(DEVICE) DEFS)
LDFLAGS += -specs=nano.specs -specs=nosys.specs

LIBS += opencm3_$(genlink_family)

TARGET_CPU = $(genlink_cpu) 

define $(MB_TARGET)_APP_PREACTION
	$(call libopencm3_app_preaction)
endef

define libopencm3_app_preaction
	-$(MKDIR) -p $(APP_LD_DIR) > /dev/null
	$(CC) $(LDFLAGS) $(LD_GEN) -P -E $(LIBOPENCM3_DIR)/ld/linker.ld.S > $(APP_LD_DIR)/$(APP_LD_SCRIPT).tmp
	gawk '!/.*eh_frame.*/' $(APP_LD_DIR)/$(APP_LD_SCRIPT).tmp > $(APP_LD_DIR)/$(APP_LD_SCRIPT)
	rm $(APP_LD_DIR)/$(APP_LD_SCRIPT).tmp
endef
