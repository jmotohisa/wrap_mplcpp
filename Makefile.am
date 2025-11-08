# this Makefile works if configured by
# $ ./configure --prefix=/Users/motohisa LDFLAGS='-L/Users/motohisa/miniconda3/envs/jm/lib -lpython3.8 -Wl,-rpath,/Users/motohisa/miniconda3/envs/jm/lib'
# or

ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = test1

test1_SOURCES = test1.c 
test1_LDADD = libwrapmplcpp.la 
# test1_LDFLAGS = -Wl,-rpath,/Users/motohisa/miniconda3/envs/jm/lib -lpython3.8

# include_HEADERS = wrap_matplotlibcpp.h
lib_LTLIBRARIES = libwrapmplcpp.la
libwrapmplcpp_la_SOURCES = wrap_matplotlibcpp.cpp 
libwrapmplcpp_la_CXXFLAGS = $(PYTHON_INCLUDES)

# lib_LIBRARIES = libwrapmplcpp.a
# libwrapmplcpp_a_SOURCES = wrap_matplotlibcpp.cpp 
# libwrapmplcpp_a_CXXFLAGS = $(PYTHON_INCLUDES)
# libwrapmplcpp_a_LDFLAGS = $(PYTHON_LIBS) -lpython3.8 -Wl,-rpath,/Users/motohisa/miniconda3/envs/jm/lib

