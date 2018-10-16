# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for microhttpd library

MICROHTTPD_LIB_DIR := $(LIBRARIES_DIR)/common/microhttpd/microhttpd_source
INCDIR += $(MICROHTTPD_LIB_DIR)
LIBS += microhttpd

# vim: syntax=make tabstop=4 noexpandtab
