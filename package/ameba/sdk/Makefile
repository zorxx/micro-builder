# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for Ameba SDK package

include ../../../include/mb.inc

PACKAGE_NAME := sdk

# Download information
$(PACKAGE_NAME)_FILENAME := sdk.zip
$(PACKAGE_NAME)_SOURCE := "https://www.rtl8710forum.com/download/file.php?id=4&sid=0c0cd27c93139c900756c2f6bf795d2a"
$(PACKAGE_NAME)_SOURCE_METHOD := wget

SRCDIR := $(AMEBA_SRC_DIR)/component

LIB_NAME_CMSIS := lib$(PACKAGE_NAME)_cmsis
$(LIB_NAME_CMSIS)_obj := $(foreach file, \
		$(SRCDIR)/soc/realtek/8195a/cmsis/device/system_8195a.c, \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

LIB_NAME_CONSOLE := lib$(PACKAGE_NAME)_console
$(LIB_NAME_CONSOLE)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/common/api/at_cmd/*.c) \
		$(SRCDIR)/soc/realtek/8195a/misc/driver/low_level_io.c \
		$(SRCDIR)/soc/realtek/8195a/misc/driver/rtl_consol.c, \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

LIB_NAME_NETWORK := lib$(PACKAGE_NAME)_network
$(LIB_NAME_NETWORK)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/common/api/wifi/*.c) \
		$(wildcard $(SRCDIR)/common/api/wifi/rtw_wpa_supplicant/*.c) \
		$(wildcard $(SRCDIR)/common/drivers/wlan/realtek/src/*.c) \
		$(wildcard $(SRCDIR)/common/api/*.c), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

LIB_NAME_APP := lib$(PACKAGE_NAME)_app
$(LIB_NAME_APP)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/common/api/network/src/*.c) \
        	$(SRCDIR)/common/utilities/ssl_client.c \
        	$(SRCDIR)/common/utilities/tcptest.c \
        	$(SRCDIR)/common/utilities/update.c, \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

LIB_NAME_LWIP := lib$(PACKAGE_NAME)_lwip
$(LIB_NAME_LWIP)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/common/network/lwip/lwip_v1.4.1/src/api/*.c), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

LIB_NAME_CORE := lib$(PACKAGE_NAME)_core
$(LIB_NAME_CORE)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/common/network/lwip/lwip_v1.4.1/src/core/ipv4/*.c) \
		$(wildcard $(SRCDIR)/common/network/lwip/lwip_v1.4.1/src/core/*.c) \
		$(wildcard $(SRCDIR)/common/network/dhcp/*.c) \
		$(wildcard $(SRCDIR)/common/network/mdns/*.c) \
        	$(SRCDIR)/common/network/lwip/lwip_v1.4.1/src/netif/etharp.c \
        	$(SRCDIR)/common/network/lwip/lwip_v1.4.1/port/realtek/freertos/ethernetif.c \
        	$(SRCDIR)/common/network/lwip/lwip_v1.4.1/port/realtek/freertos/sys_arch.c \
        	$(SRCDIR)/common/drivers/wlan/realtek/src/osdep/lwip_intf.c, \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

LIB_NAME_OS := lib$(PACKAGE_NAME)_os
$(LIB_NAME_OS)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/os/freertos/freertos_v8.1.2/Source/portable/GCC/ARM_CM3/*.c) \
		$(wildcard $(SRCDIR)/os/freertos/freertos_v8.1.2/Source/*.c) \
		$(wildcard $(SRCDIR)/os/os_dep/*.c) \
		$(wildcard $(SRCDIR)/os/freertos/*.c) \
        	$(SRCDIR)/os/freertos/freertos_v8.1.2/Source/portable/MemMang/heap_5.c, \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

LIB_NAME_PERIPHERAL := lib$(PACKAGE_NAME)_peripheral
$(LIB_NAME_PERIPHERAL)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/common/mbed/targets/hal/rtl8195a/*.c) \
		$(wildcard $(SRCDIR)/common/mbed/common/*.c), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

LIB_NAME_HAL := lib$(PACKAGE_NAME)_hal
$(LIB_NAME_HAL)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/soc/realtek/8195a/fwlib/src/*.c) \
		$(wildcard $(SRCDIR)/soc/realtek/8195a/fwlib/rtl8195a/src/*.c), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

LIB_NAME_POLARSSL := lib$(PACKAGE_NAME)_polarssl
$(LIB_NAME_POLARSSL)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/common/network/ssl/polarssl-1.3.8/library/*.c) \
		$(wildcard $(SRCDIR)/common/network/ssl/ssl_ram_map/*.c) \
		$(wildcard $(SRCDIR)/common/network/ssl/ssl_ram_map/rom/*.c), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

LIB_NAME_WIGADGET := lib$(PACKAGE_NAME)_wigadget
$(LIB_NAME_WIGADGET)_obj := $(foreach file, \
		$(wildcard $(SRCDIR)/common/application/wigadget/*.c), \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

LIB_NAME_MISC := lib$(PACKAGE_NAME)_misc
$(LIB_NAME_MISC)_obj := $(foreach file, \
		$(SRCDIR)/common/api/platform/stdlib_patch.c, \
                $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

LIBRARY_TARGETS += $(LIB_NAME_CMSIS) $(LIB_NAME_CONSOLE) $(LIB_NAME_NETWORK) $(LIB_NAME_APP) \
 $(LIB_NAME_LWIP) $(LIB_NAME_CORE) $(LIB_NAME_OS) $(LIB_NAME_PERIPHERAL) $(LIB_NAME_HAL) \
 $(LIB_NAME_POLARSSL) $(LIB_NAME_WIGADGET) $(LIB_NAME_MISC)
LIBRARY_SUBMAKE := true

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
