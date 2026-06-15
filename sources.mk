# all source files for both makefiles are here

SRCDIR := $(dir $(lastword $(MAKEFILE_LIST)))
LOGICSRCS := $(notdir $(filter-out $(SRCDIR)input.c, $(wildcard $(SRCDIR)*.c)))

# How it works:
#
# $(lastword $(MAKEFILE_LIST)) 
# = path to this file. called from root: sources.mk, called from tests: ../sources.mk
#
# $(dir …) = ./ or ../. 
# = where the real sources live
#
# $(wildcard $(SRCDIR)*.c) 
# = all .c there
#
# $(filter-out $(SRCDIR)input.c, …)
# = drop input.c.
#
# $(notdir …)
# = strip dir: bare errors.c stack_algo.c 


