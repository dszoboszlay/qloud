# This line tells Emacs to use -*- conf -*- mode

TEMPLATE = app

HEADERS = include/propset.hpp \
	  include/clouddef.hpp \
	  include/factory.hpp \
	  include/setter.hpp \
	  include/simplesetter.hpp \
	  include/cloudgen.hpp
SOURCES = src/propset.cpp \
	  src/clouddef.cpp  \
	  src/cloudgen.cpp \
	  src/main.cpp
FORMS =

CONFIG += qt debug_and_release precompile_header

PRECOMPILED_HEADER = include/common.hpp
build_pass:CONFIG(debug, debug|release) {
  TARGET = qloud_d
} else {
  TARGET = qloud
}
