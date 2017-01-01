# /copyright 2016 Zorxx Software, All Rights Reserved
# /license This file is released under the MIT License. See the LICENSE file for details.
# /brief Build environment for Ameba SDK package

AMEBA_SDK_VERSION := v3.4b3
AMEBA_SRC_DIR := sdk_source/sdk-ameba1-$(AMEBA_SDK_VERSION)_without_NDA
AMEBA_SDK_DIR := $(PACKAGE_DIR)/ameba/sdk/$(AMEBA_SRC_DIR)

INCDIR += \
$(AMEBA_SDK_DIR)/project/realtek_ameba1_va0_example/inc

INCDIR += \
$(AMEBA_SDK_DIR)/component/soc/realtek/common/bsp \
$(AMEBA_SDK_DIR)/component/os/freertos \
$(AMEBA_SDK_DIR)/component/os/freertos/freertos_v8.1.2/Source/include \
$(AMEBA_SDK_DIR)/component/os/freertos/freertos_v8.1.2/Source/portable/GCC/ARM_CM3 \
$(AMEBA_SDK_DIR)/component/os/os_dep/include \
$(AMEBA_SDK_DIR)/component/soc/realtek/8195a/misc/driver \
$(AMEBA_SDK_DIR)/component/common/api/network/include \
$(AMEBA_SDK_DIR)/component/common/api \
$(AMEBA_SDK_DIR)/component/common/api/platform \
$(AMEBA_SDK_DIR)/component/common/api/wifi \
$(AMEBA_SDK_DIR)/component/common/api/wifi/rtw_wpa_supplicant/src \
$(AMEBA_SDK_DIR)/component/common/application \
$(AMEBA_SDK_DIR)/component/common/example \
$(AMEBA_SDK_DIR)/component/common/example/wlan_fast_connect \
$(AMEBA_SDK_DIR)/component/common/mbed/api \
$(AMEBA_SDK_DIR)/component/common/mbed/hal \
$(AMEBA_SDK_DIR)/component/common/mbed/hal_ext \
$(AMEBA_SDK_DIR)/component/common/mbed/targets/hal/rtl8195a \
$(AMEBA_SDK_DIR)/component/common/network \
$(AMEBA_SDK_DIR)/component/common/network/lwip/lwip_v1.4.1/port/realtek/freertos \
$(AMEBA_SDK_DIR)/component/common/network/lwip/lwip_v1.4.1/src/include \
$(AMEBA_SDK_DIR)/component/common/network/lwip/lwip_v1.4.1/src/include/lwip \
$(AMEBA_SDK_DIR)/component/common/network/lwip/lwip_v1.4.1/src/include/ipv4 \
$(AMEBA_SDK_DIR)/component/common/network/lwip/lwip_v1.4.1/port/realtek \
$(AMEBA_SDK_DIR)/component/common/test \
$(AMEBA_SDK_DIR)/component/soc/realtek/8195a/cmsis \
$(AMEBA_SDK_DIR)/component/soc/realtek/8195a/cmsis/device \
$(AMEBA_SDK_DIR)/component/soc/realtek/8195a/fwlib \
$(AMEBA_SDK_DIR)/component/soc/realtek/8195a/fwlib/rtl8195a \
$(AMEBA_SDK_DIR)/component/common/drivers/wlan/realtek/include \
$(AMEBA_SDK_DIR)/component/common/drivers/wlan/realtek/src/osdep \
$(AMEBA_SDK_DIR)/component/common/drivers/wlan/realtek/src/hci \
$(AMEBA_SDK_DIR)/component/common/drivers/wlan/realtek/src/hal \
$(AMEBA_SDK_DIR)/component/common/drivers/wlan/realtek/src/hal/OUTSRC \
$(AMEBA_SDK_DIR)/component/soc/realtek/8195a/fwlib/ram_lib/wlan/realtek/wlan_ram_map/rom \
$(AMEBA_SDK_DIR)/component/common/network/ssl/polarssl-1.3.8/include \
$(AMEBA_SDK_DIR)/component/common/network/ssl/ssl_ram_map/rom \
$(AMEBA_SDK_DIR)/component/common/utilities \
$(AMEBA_SDK_DIR)/component/soc/realtek/8195a/misc/rtl_std_lib/include \
$(AMEBA_SDK_DIR)/component/soc/realtek/8195a/fwlib/ram_lib/usb_otg/include \
$(AMEBA_SDK_DIR)/component/common/video/v4l2/inc \
$(AMEBA_SDK_DIR)/component/common/media/codec \
$(AMEBA_SDK_DIR)/component/common/drivers/usb_class/host/uvc/inc

INCDIR += \
$(AMEBA_SDK_DIR)/component/soc/realtek/8195a/cmsis \
$(AMEBA_SDK_DIR)/component/os/os_dep/include \
$(AMEBA_SDK_DIR)/component/os/freertos/freertos_v8.1.2/Source/include \
$(AMEBA_SDK_DIR)/component/os/freertos/freertos_v8.1.2/Source/portable/GCC/ARM_CM3

INCDIR += \
$(AMEBA_SDK_DIR)/component/soc/realtek/common/bsp \
$(AMEBA_SDK_DIR)/component/os/freertos \
$(AMEBA_SDK_DIR)/component/os/freertos/freertos_v8.1.2/Source/include \
$(AMEBA_SDK_DIR)/component/os/freertos/freertos_v8.1.2/Source/portable/GCC/ARM_CM3 \
$(AMEBA_SDK_DIR)/component/os/os_dep/include \
$(AMEBA_SDK_DIR)/component/soc/realtek/8195a/misc/driver \
$(AMEBA_SDK_DIR)/component/common/api/platform \
$(AMEBA_SDK_DIR)/component/common/api/network/include \
$(AMEBA_SDK_DIR)/component/common/api \
$(AMEBA_SDK_DIR)/component/common/api/wifi \
$(AMEBA_SDK_DIR)/component/common/api/wifi/rtw_wpa_supplicant/src \
$(AMEBA_SDK_DIR)/component/common/application/iotdemokit \
$(AMEBA_SDK_DIR)/component/common/application/google \
$(AMEBA_SDK_DIR)/component/common/mbed/hal \
$(AMEBA_SDK_DIR)/component/common/mbed/targets/hal/rtl8195a \
$(AMEBA_SDK_DIR)/component/common/network \
$(AMEBA_SDK_DIR)/component/common/network/lwip/lwip_v1.4.1/port/realtek/freertos \
$(AMEBA_SDK_DIR)/component/common/network/lwip/lwip_v1.4.1/src/include \
$(AMEBA_SDK_DIR)/component/common/network/lwip/lwip_v1.4.1/src/include/lwip \
$(AMEBA_SDK_DIR)/component/common/network/lwip/lwip_v1.4.1/src/include/ipv4 \
$(AMEBA_SDK_DIR)/component/common/network/lwip/lwip_v1.4.1/port/realtek \
$(AMEBA_SDK_DIR)/component/common/test \
$(AMEBA_SDK_DIR)/component/soc/realtek/8195a/cmsis \
$(AMEBA_SDK_DIR)/component/soc/realtek/8195a/cmsis/device \
$(AMEBA_SDK_DIR)/component/soc/realtek/8195a/fwlib \
$(AMEBA_SDK_DIR)/component/soc/realtek/8195a/fwlib/rtl8195a \
$(AMEBA_SDK_DIR)/component/common/drivers/wlan/realtek/include \
$(AMEBA_SDK_DIR)/component/common/drivers/wlan/realtek/src/osdep \
$(AMEBA_SDK_DIR)/component/common/drivers/wlan/realtek/src/hci \
$(AMEBA_SDK_DIR)/component/common/drivers/wlan/realtek/src/hal \
$(AMEBA_SDK_DIR)/component/common/drivers/wlan/realtek/src/hal/OUTSRC \
$(AMEBA_SDK_DIR)/component/soc/realtek/8195a/fwlib/ram_lib/wlan/realtek/wlan_ram_map/rom \
$(AMEBA_SDK_DIR)/component/common/network/ssl/polarssl-1.3.8/include \
$(AMEBA_SDK_DIR)/component/common/network/ssl/ssl_ram_map/rom \
$(AMEBA_SDK_DIR)/component/soc/realtek/8195a/misc/rtl_std_lib/include \
$(AMEBA_SDK_DIR)/component/common/mbed/hal_ext \
$(AMEBA_SDK_DIR)/component/common/application/apple/WACServer/External/Curve25519 \
$(AMEBA_SDK_DIR)/component/common/application/apple/WACServer/External/GladmanAES \
$(AMEBA_SDK_DIR)/component/common/utilities \
$(AMEBA_SDK_DIR)/component/soc/realtek/8195a/fwlib/ram_lib/usb_otg/include \
$(AMEBA_SDK_DIR)/component/common/video/v4l2/inc \
$(AMEBA_SDK_DIR)/component/common/media/codec \
$(AMEBA_SDK_DIR)/component/common/drivers/usb_class/host/uvc/inc

LIBS +=
#LIBS += rom.a

LIBDIRS += $(AMEBA_SDK_DIR)/component/soc/realtek/8195a/misc/bsp/lib/va0
CDEFS +=

# vim: syntax=make tabstop=4 noexpandtab
