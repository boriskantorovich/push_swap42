# all source files for both makefiles are here

SRCDIR := $(dir $(lastword $(MAKEFILE_LIST)))

FINDEXCL := -not -path '*/libft/*' -not -path '*/includes/*' \
            -not -path '*/tests/*' -not -path '*/scripts/*'

LOGICSRCS := $(notdir $(shell find $(SRCDIR) -name '*.c' $(FINDEXCL) \
             -not -name 'input.c'))
LOGICDIRS := $(sort $(dir $(shell find $(SRCDIR) -name '*.c' $(FINDEXCL))))

# How it works:
#
# $(lastword $(MAKEFILE_LIST))
# = path to this file. called from root: sources.mk, called from tests: ../sources.mk
#
# $(dir …) = ./ or ../.
# = where the real sources live
#
# find $(SRCDIR) -name '*.c' $(FINDEXCL)
# = recurse every subfolder, drop libft / includes / tests / scripts
#
# -not -name 'input.c'
# = drop input.c (the main) from the logic build
#
# $(notdir …)
# = strip dir: bare errors.c stack_api/pa_pb.c -> pa_pb.c
#
# LOGICDIRS = unique source dirs, fed to "vpath %.c" so make finds bare names
