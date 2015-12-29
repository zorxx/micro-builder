# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Top-level makefile for 

include top.inc

# ----------------------------------------------------------------------------------------
# Top-level productions

all : sdk_install tools_install arduino_install subdirs
clean : sdk_clean tools_clean arduino_clean subdirs_clean

# ----------------------------------------------------------------------------------------
# SDK Download/Installation

$(ESP8266_SDK_INSTALL_DIR):
	@$(ECHO) "Downloading and installing ESP8266 SDK..."
	@$(MKDIR) -p $@
	@$(WGET) -nc $(ESP8266_SDK_SOURCE) -O $@/sdk.zip
	@$(CD) $@;$(UNZIP) -q sdk.zip

sdk_install: $(ESP8266_SDK_INSTALL_DIR)
sdk_clean:
	@$(RM) -rf $(SDK_DIR)

# ----------------------------------------------------------------------------------------
# Espressif Tools Download/Installation

$(ESPTOOL_DIR):
	@$(GIT) clone $(ESPTOOL_SOURCE) $@

$(TOOLS_DIR):
	@$(MKDIR) -p $@

tools_install: $(TOOLS_DIR) $(ESPTOOL_DIR)
tools_clean:
	@$(RM) -rf $(TOOLS_DIR)

# ----------------------------------------------------------------------------------------
# ESP8266/Arduino

$(ESP8266_ARDUINO_INSTALL_DIR): $(ESP8266_ARDUINO_DIR)
	@$(GIT) clone $(ESP8266_ARDUINO_SOURCE) $@
$(ESP8266_ARDUINO_DIR):
	@$(MKDIR) -p $@
arduino_install: $(ESP8266_ARDUINO_INSTALL_DIR)
arduino_clean:
	@$(RM) -rf $(ESP8266_ARDUINO_DIR)

# ----------------------------------------------------------------------------------------
# Subdirectories

SUBDIRS := lib examples
subdirs:
	@$(foreach dir,$(SUBDIRS), $(ECHO) "Building subdirectory: $(dir)"; make --no-print-directory -C $(dir);)
subdirs_clean:
	@$(foreach dir,$(SUBDIRS), $(ECHO) "Cleaning subdirectory: $(dir)"; make --no-print-directory -C $(dir) clean;)   	
.PHONY: subdirs subdirs_clean

include bottom.inc
