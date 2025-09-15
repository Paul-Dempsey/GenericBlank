RACK_DIR ?= ../..

FLAGS +=

SOURCES += src/plugin.cpp
SOURCES += src/Blank.cpp

DISTRIBUTABLES += res
# DISTRIBUTABLES += presets
# DISTRIBUTABLES += selections

# Include the VCV Rack plugin Makefile framework
include $(RACK_DIR)/plugin.mk