# \copyright 2018 Zorxx Software, All Rights Reserved
# \license This file is released under the MIT License. See the LICENSE file for details.
# \brief Recipe for mongoose Library

MONGOOSE_LIB_DIR := $(LIBRARIES_DIR)/common/mongoose/mongoose_source
INCDIR += $(MONGOOSE_LIB_DIR)
CDEFS += MG_ENABLE_HTTP_STREAMING_MULTIPART=1
LIBS += mongoose

# vim: syntax=make tabstop=4 noexpandtab
