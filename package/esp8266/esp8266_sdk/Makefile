# \copyright 2015-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for ESP8266 SDK package

include ../../../include/mb.inc

PACKAGE_NAME := esp8266_sdk

# Download information
$(PACKAGE_NAME)_SOURCE := "https://github.com/espressif/ESP8266_RTOS_SDK.git"
$(PACKAGE_NAME)_SOURCE_METHOD := git

define $(PACKAGE_NAME)_POSTACTION
	$(STRIP) -N printf $(ESP8266_SDK_DIR)/components/esp8266/lib/libcirom.a
	$(STRIP) -N puts $(ESP8266_SDK_DIR)/components/esp8266/lib/libcirom.a
endef

# Common Library
LIB_NAME_COMMON := lib$(PACKAGE_NAME)_common
$(LIB_NAME_COMMON)_obj := $(foreach file, \
                          $(foreach d,$(ESP8266_SDK_SRCDIRS),$(wildcard $(ESP8266_SDK_DIR)/components/$(d)/*.c)) \
                          $(foreach d,$(ESP8266_SDK_SRCDIRS),$(wildcard $(ESP8266_SDK_DIR)/components/$(d)/*.S)), \
                          $(addsuffix .o, $(basename $(BUILD_TEMP_DIR)/$(file))))

CFLAGS += -D_POSIX_SOURCE -DLWIP_OPEN_SRC -DPBUF_RSV_FOR_WLAN -DEBUF_LWIP
CFLAGS += -DMEMLEAK_DEBUG -DICACHE_FLASH
CFLAGS += -DMBEDTLS_CONFIG_FILE='"esp_config.h"' -DMBEDTLS_AES_C

# Configuration parameters
CFLAGS += -DCONFIG_TCP_OVERSIZE_MSS -DCONFIG_TCPIP_TASK_STACK_SIZE=512 -DCONFIG_TCP_MSS=1460
CFLAGS += -DCONFIG_TCP_SND_BUF_DEFAULT=2920 -DCONFIG_UDP_RECVMBOX_SIZE=6
CFLAGS += -DCONFIG_LWIP_DHCP_MAX_NTP_SERVERS=1 -DCONFIG_TCP_WND_DEFAULT=5840
CFLAGS += -DCONFIG_TCP_SYNMAXRTX=6 -DCONFIG_TCP_MAXRTX=12 -DCONFIG_TCP_RECVMBOX_SIZE=6
CFLAGS += -DCONFIG_LWIP_TCP_CLOSE_TIMEOUT_MS_DEFAULT=10000 -DCONFIG_DNS_MAX_SERVERS=2
CFLAGS += -DCONFIG_LWIP_ARP_TABLE_SIZE=10 -DCONFIG_LWIP_ARP_MAXAGE=300
CFLAGS += -DCONFIG_LWIP_DHCPS_MAX_STATION_NUM=8 -DCONFIG_LWIP_DHCPS_LEASE_UNIT=60
CFLAGS += -DCONFIG_PARTITION_TABLE_OFFSET=0x8000
CFLAGS += -DCONFIG_PARTITION_TABLE_CUSTOM_APP_BIN_OFFSET=0x10000

LIBRARY_TARGETS += $(LIB_NAME_COMMON)
LIBRARY_SUBMAKE := true

EXTERNAL_TARGETS += $(PACKAGE_NAME)

include $(INCLUDE_DIR)/ext.inc
include $(INCLUDE_DIR)/lib.inc
include $(INCLUDE_DIR)/dir.inc

# vim: syntax=make tabstop=4 noexpandtab
