
ifeq (yes,$(strip $(DEBUG_ACTION)))
    OPT_DEFS += -DDEBUG_ACTION
endif
