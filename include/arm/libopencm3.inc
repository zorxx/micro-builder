LD_GEN = $(system gawk -v PAT="$(DEVICE)" -f $(LIBOPENCM3_DIR)/scripts/genlink.awk $(LIBOPENCM3_DIR)/ld/devices.data 2>/dev/null)
APP_LD_SCRIPT = $(DEVICE).ld
APP_LD_DIR = $(BUILD_TEMP_DIR)

DEVICES_DATA = $(LIBOPENCM3_DIR)/ld/devices.data

genlink_family    = $(shell gawk -v PAT="$(DEVICE)" -v MODE="FAMILY" -f $(LIBOPENCM3_DIR)/scripts/genlink.awk $(DEVICES_DATA))
genlink_subfamily = $(shell gawk -v PAT="$(DEVICE)" -v MODE="SUBFAMILY" -f $(LIBOPENCM3_DIR)/scripts/genlink.awk $(DEVICES_DATA))
genlink_cpu       = $(shell gawk -v PAT="$(DEVICE)" -v MODE="CPU" -f $(LIBOPENCM3_DIR)/scripts/genlink.awk $(DEVICES_DATA))
genlink_fpu       = $(shell gawk -v PAT="$(DEVICE)" -v MODE="FPU" -f $(LIBOPENCM3_DIR)/scripts/genlink.awk $(DEVICES_DATA))
genlink_cppflags  = $(shell gawk -v PAT="$(DEVICE)" -v MODE="CPPFLAGS" -f $(LIBOPENCM3_DIR)/scripts/genlink.awk $(DEVICES_DATA))
genlink_cdefs     = $(shell gawk -v PAT="$(DEVICE)" -v MODE="DEFS" -f $(LIBOPENCM3_DIR)/scripts/genlink.awk $(DEVICES_DATA))

CFLAGS += $(genlink_cppflags)
CPPFLAGS += $(genlink_cppflags)
LDFLAGS += $(genlink_cdefs)

TARGET_CPU = $(genlink_cpu) 

define libopencm3_app_preaction
	-$(MKDIR) -p $(APP_LD_DIR) > /dev/null
	$(CC) $(LDFLAGS) $(LD_GEN) -P -E $(LIBOPENCM3_DIR)/ld/linker.ld.S > $(APP_LD_DIR)/$(APP_LD_SCRIPT).tmp
	gawk '!/.*eh_frame.*/' $(APP_LD_DIR)/$(APP_LD_SCRIPT).tmp > $(APP_LD_DIR)/$(APP_LD_SCRIPT)
	rm $(APP_LD_DIR)/$(APP_LD_SCRIPT).tmp
endef

