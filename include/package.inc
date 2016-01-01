# \copyright 2015 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Rules for dowloading/building external packages

PKG_SRC_DIR := source

# Package includes
# TODO: make this more efficient by including only the directories listed in the PACKAGES variable,
#       and include the directory heirarchy in the package name
PACKAGE_ROOT_DIRS := $(PACKAGE_DIR)/common $(PACKAGE_DIR)/$(TARGET_ARCH)
-include $(foreach pkg,$(PACKAGES),$(foreach rootdir,$(PACKAGE_ROOT_DIRS),$(rootdir)/$(pkg)/$(pkg).inc))

# ---------------------------------------------------------------------------------------
# Top-level productions

packages:
	@$(MAKE) $(PACKAGE_DIR)
packages_list:
	@$(ECHO) "$(PACKAGES)"
packages_clean:
	@$(foreach pkg,$(PACKAGES),$(call package_clean,$(pkg)))
.PHONY: packages packages_list packages_clean

# ---------------------------------------------------------------------------------------
# Download

.%.download:
	@$(call package_download_$($(strip $(patsubst .%.download,%,$@)_SOURCE_METHOD)),$(patsubst .%.download,%,$@))
	@$(call package_patch,$(patsubst .%.download,%,$@),$(PKG_SRC_DIR))
	@$(ECHO) "$(shell $(DATE))" > $@

# package_download_git(package_name)
define package_download_git
	$(ECHO) "Download (git): $1"
	$(GIT) clone $($1_SOURCE) $(PKG_SRC_DIR)
	$(if $($1_VERSION),$(ECHO) "Version: $($1_VERSION)";$(CD) $(PKG_SRC_DIR);$(GIT) checkout -q "$($1_VERSION)",$(ECHO) "Default version")
endef

# package_download_wget(package_name)
define package_download_wget
	$(ECHO) "Download (wget): $1"
	$(MKDIR) -p $(PKG_SRC_DIR)
	$(CD) $(PKG_SRC_DIR);$(WGET) --no-check-certificate -nc $($1_SOURCE) -O $($1_FILENAME)
	$(call package_extract,$($1_FILENAME),$(PKG_SRC_DIR))
endef

define package_extract
	$(CD) $2; \
		$(if $(findstring .tar.gz,$1),$(TAR) xzf $1) \
		$(if $(findstring .tar.bz2,$1),$(TAR) xjf $1) \
		$(if $(findstring .tar.xz,$1),$(TAR) xJf $1) \
		$(if $(findstring .zip,$1),$(UNZIP) $1)
endef

define package_patch
	$(foreach patchfile,$(abspath $(wildcard *$1.patch)),$(PATCH) --directory=$2 -p1 -i $(patchfile))
endef

# ---------------------------------------------------------------------------------------
# Clean

# package_clean(name)
define package_clean
	@$(ECHO) "Cleaning: $1";
	@$(RM) -rf $(PKG_SRC_DIR)
	@$(RM) -f .$1.download
endef

# vim: syntax=make tabstop=4 noexpandtab
