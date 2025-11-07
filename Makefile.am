ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = test1
test1_SOURCES = test1.c
test1_LDADD = libwrapmplcpp.a

lib_LIBRARIES = libwrapmplcpp.a
libwrapmplcpp_a_SOURCES = wrap_matplotlibcpp.cpp
libwrapmplcpp_a_CPPFLAGS = $(PYTHON_INCLUDES)
libwrapmplcpp_a_LDFLAGS = $(PYTHON_LIBS)
