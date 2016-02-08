# \copyright 2016 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top make include file for AVR architecture

# -------------------------------------------------
#

LDFLAGS += -Os -Wl,--gc-sections -mmcu=$(TARGET_MCU)

LIBDIRS += $(ARCH_INCLUDE_DIR)/ld

CFLAGS += -Os -g -Wall -MMD -std=gnu11 -ffunction-sections -fdata-sections -mmcu=$(TARGET_MCU) 
CPPFLAGS += -Os -g -Wall -fno-exceptions -std=gnu++11 -MMD -ffunction-sections -fdata-sections -fno-threadsafe-statics -mmcu=$(TARGET_MCU)
ASMFLAGS += -c -g -x assembler-with-cpp -MMD -mlongcalls -mtext-section-literals -mmcu=$(TARGET_MCU)
CDEFS += __AVR_$(TARGET_CPU)__ F_CPU=$(TARGET_CPU_SPEED)

# ----------------------------------------------------------------------------------------
# Architecture-specific Library Steps

define avr_post_lib
endef

# ----------------------------------------------------------------------------------------
# Architecture-specific Application Steps

# avr_post_app(app_out_file)
define avr_post_app
	$(OBJCOPY) -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 $1 $(basename $1).eep
	$(OBJCOPY) -O ihex -R .eeprom $1 $(basename $1).hex
endef

# avr_app_info(app_file,app_dir)
define avr_app_info
endef

# avr_app_flash(app_file,app_dir)
define avr_app_flash
$(AVRDUDE) -C$(ARCH_INCLUDE_DIR)/avrdude.conf -v -p$(TARGET_MCU) -carduino -P$(TARGET_PORT) -b$(TARGET_BAUD) -D -Uflash:w:$2/$(basename $1).hex:i
endef

# ----------------------------------------------------------------------------------------
# Other

# avr_checkboard(app_file,app_dir)
define avr_checkboard(app_file,app_dir)
endef

# vim: syntax=make tabstop=4 noexpandtab
