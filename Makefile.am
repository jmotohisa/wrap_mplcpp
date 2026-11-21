# This Makefile works OK with ./configure

ACLOCAL_AMFLAGS = -I m4

test1: test1.c .libs/libwrapmplcpp.la
	gcc -c test1.c 
	g++ -o test1 test1.o .libs/libwrapmplcpp.a -std=c++11 `python3-config --includes` `python3 -c 'import numpy; print("-I"+numpy.get_include())'` `python3-config --ldflags --embed`


bin_PROGRAMS = test2 test3

# test2 works ok
test2_SOURCES = test1.c 
test2_LDADD = libwrapmplcpp.la 

## test3 does not work
# test3_SOURCES = test1.c wrap_matplotlibcpp.cpp
# test3_CXXFLAGS = $(PYTHON_INCLUDES)

# 
# インストール対象の Libtool ライブラリを指定
lib_LTLIBRARIES = libwrapmplcpp.la

# ビルドするソースファイル
libwrapmplcpp_la_SOURCES = wrap_matplotlibcpp.cpp 

# 公開するヘッダファイル（必要な場合）
include_HEADERS = wrap_matplotlibcpp.h

# プリプロセッサフラグ（Python や NumPy のインクルードパス）
libwrapmplcpp_la_CPPFLAGS = $(AM_CPPFLAGS)
if WITH_PYTHON
libwrapmplcpp_la_CPPFLAGS += $(PYTHON_INCLUDES)
endif

# リンクするライブラリ（libpython など）
libwrapmplcpp_la_LIBADD =
if WITH_PYTHON
libwrapmplcpp_la_LIBADD += $(PYTHON_LIBS)
endif

# リンカフラグ（共有ライブラリのバージョン情報など）
libwrapmplcpp_la_LDFLAGS = -version-info 0:0:0

# include_HEADERS = wrap_matplotlibcpp.h
# lib_LTLIBRARIES = libwrapmplcpp.la
# libwrapmplcpp_la_SOURCES = wrap_matplotlibcpp.cpp 
# libwrapmplcpp_la_CXXFLAGS = $(PYTHON_INCLUDES)
# libwrapmplcpp_la_LDFLAGS = $(PYTHON_LIBS)
