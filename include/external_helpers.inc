# \copyright 2015-2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Rules for dowloading/building external packages

PKG_SRC_DIR := source

# ---------------------------------------------------------------------------------------
# External package, top-level production

.%.external: .%.external_preaction .%.external_download .%.external_patch .%.external_postaction
	@$(ECHO) "$(shell $(DATE))" > $@

# ---------------------------------------------------------------------------------------
# Pre-action: things to be done before downloading an external package

.%.external_preaction:
	@$(call $*_PREACTION,$*_$(PKG_SRC_DIR))
	@$(ECHO) "$(shell $(DATE))" > $@
.PHONY: .%.external_preaction
.PRECIOUS: .%.external_preaction

# ---------------------------------------------------------------------------------------
# Download an external package

# package_download_git(package_name)
define package_download_git
	$(ECHO) "Download (git): $1"
	$(GIT) clone $(strip $($1_SOURCE)) $1_$(PKG_SRC_DIR)
	$(if $($1_VERSION),$(ECHO) "Version: $($1_VERSION)";$(CD) $1_$(PKG_SRC_DIR);$(GIT) checkout -q "$($1_VERSION)",$(ECHO) "Default version")
endef

# package_download_hg(package_name)
define package_download_hg
	$(ECHO) "Download (hg): $1"
	$(HG) clone $(strip $($1_SOURCE)) $1_$(PKG_SRC_DIR)
	$(if $($1_VERSION),$(ECHO) "Version: $($1_VERSION)";$(CD) $1_$(PKG_SRC_DIR);$(HG) checkout -q "$($1_VERSION)",$(ECHO) "Default version")
endef

# package_download_svn(package_name)
define package_download_svn
	$(ECHO) "Download (svn): $1"
	$(SVN) co $(strip $($1_SOURCE)) $1_$(PKG_SRC_DIR)
endef

# package_download_wget(package_name)
define package_download_wget
	$(ECHO) "Download (wget): $1"
	$(MKDIR) -p $1_$(PKG_SRC_DIR)
	$(CD) $1_$(PKG_SRC_DIR);$(WGET) --no-check-certificate -nc $(strip $($1_SOURCE)) -O $(strip $($1_FILENAME))
	$(call package_extract,$(strip $($1_FILENAME)),$1_$(PKG_SRC_DIR))
endef

define package_extract
	$(CD) $2; \
		$(if $(findstring .tar.gz,$1),$(TAR) xzf $1) \
		$(if $(findstring .tar.bz2,$1),$(TAR) xjf $1) \
		$(if $(findstring .tar.xz,$1),$(TAR) xJf $1) \
		$(if $(findstring .zip,$1),$(UNZIP) -q $1)
endef

.%.external_download:
	@$(call package_download_$($*_SOURCE_METHOD),$*)
	@$(ECHO) "$(shell $(DATE))" > $@
.PHONY: .%.external_download
.PRECIOUS: .%.external_download

# ---------------------------------------------------------------------------------------
# Patch an external package

.%.external_patch:
	@$(foreach patchfile,$(abspath $(wildcard *$*.patch)),$(PATCH) --directory=$*_$(PKG_SRC_DIR) -p1 -i $(patchfile))
	@$(ECHO) "$(shell $(DATE))" > $@
.PHONY: .%.external_patch
.PRECIOUS: .%.external_patch

# ---------------------------------------------------------------------------------------
# Post-action: things to be done after downloading/patching an external package

.%.external_postaction:
	$(call $*_POSTACTION,$*_$(PKG_SRC_DIR))
	@$(ECHO) "$(shell $(DATE))" > $@
.PHONY: .%.external_postaction
.PRECIOUS: .%.external_postaction

# ---------------------------------------------------------------------------------------
# Clean

%.external_clean:
	@$(ECHO) "Cleaning: $*";
	@$(RM) -rf $*_$(PKG_SRC_DIR)
	@$(RM) -f .$*.external_preaction
	@$(RM) -f .$*.external_download
	@$(RM) -f .$*.external_patch
	@$(RM) -f .$*.external_postaction
	@$(RM) -f .$*.external
.PHONY: %.external_clean

# vim: syntax=make tabstop=4 noexpandtab
