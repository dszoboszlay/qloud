# This line tells Emacs to use -*- conf -*- mode

TEMPLATE = app

HEADERS = 
SOURCES = src/main.cpp
FORMS =

CONFIG += qt debug_and_release precompile_header

PRECOMPILED_HEADER = include/common.hpp
build_pass:CONFIG(debug, debug|release) {
  TARGET = qloud_d
} else {
  TARGET = qloud
}
