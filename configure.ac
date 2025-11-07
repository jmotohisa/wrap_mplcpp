#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.72])
AC_INIT(testmpl, 0.1a, motohisa@ist.hokudai.ac.jp)
AC_CONFIG_SRCDIR([matplotlibcpp.h])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE
dnl AC_PROG_LIBTOOL

SHARED_VERSION_INFO="0:0:0" # CURRENT:REVISION:AGE
AC_CONFIG_MACRO_DIR([m4])
AC_SUBST(SHARED_VERSION_INFO)

dnl AM_INIT_AUTOMAKE
dnl AC_PROG_LIBTOOL

AC_ENABLE_SHARED
LT_INIT

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL
dnl AC_PROG_RANLIB

# Checks for libraries.
AC_CHECK_LIB([m], [main])

# checks for python
##############################################################################

AC_ARG_WITH(python,
	[AS_HELP_STRING([--without-python],[compile without Python interface])],
        with_python=$withval,with_python=yes)

AC_CHECK_PROG(SWIG, swig, swig, echo)
if test "$USE_MAINTAINER_MODE" = yes && (test "x$with_python" = "xyes" || test "x$with_scheme" = "xyes") && test "x$SWIG" = xecho; then
  AC_MSG_ERROR([SWIG not found; configure --without-python --without-scheme or use a release tarball])
fi

AC_ARG_WITH(coverage, [AS_HELP_STRING([--with-coverage],[enable Python coverage tests])],
            with_coverage=$withval, with_coverage=no)

if test "x$with_python" = xno; then
  have_python=no
else
  if test "x$have_libctlgeom" = xno; then
    AC_MSG_ERROR([libctlgeom was not found, is required for Python interface])
  fi

  if test "$enable_shared" = no; then
     AC_MSG_WARN([Python interface requires --enable-shared; disabling])
     have_python=no
  else

    AM_PATH_PYTHON([],[have_python=yes],[have_python=no])
    if test $have_python = yes; then

      AC_MSG_CHECKING([for Python library directory])
      pinc=`echo "import sysconfig; print(sysconfig.get_config_var('LIBDIR'))" | $PYTHON - 2>/dev/null`
      AC_MSG_RESULT([${pinc:-unknown}])
      test -n "$pinc" && PYTHON_LIBS="-L$pinc"
      save_LDFLAGS=$LDFLAGS
      LDFLAGS="$LDFLAGS $PYTHON_LIBS"

      AC_MSG_CHECKING([for Python include directory])
      pinc=`echo "import sysconfig; print(sysconfig.get_path('include'))" | $PYTHON - 2>/dev/null`
      AC_MSG_RESULT([${pinc:-unknown}])
      test -n "$pinc" && PYTHON_INCLUDES="-I$pinc"
      save_CPPFLAGS=$CPPFLAGS
      CPPFLAGS="$CPPFLAGS $PYTHON_INCLUDES"
      AC_CHECK_HEADER([Python.h], [], [AC_MSG_WARN([disabling Python wrappers])
                                       have_python=no])

      if test $have_python = yes; then
        AC_MSG_CHECKING([for Numpy include directory])
        pinc=`echo "import numpy; print (numpy.get_include())" | $PYTHON - 2>/dev/null`
        AC_MSG_RESULT([${pinc:-unknown}])
        test -n "$pinc" && PYTHON_INCLUDES="$PYTHON_INCLUDES -I$pinc"
        CPPFLAGS="$save_CPPFLAGS $PYTHON_INCLUDES"
        AC_CHECK_HEADER([numpy/arrayobject.h],[],[
          AC_MSG_WARN([disabling Python wrappers])
          have_python=no],[#include <Python.h>])

        if test x"$with_coverage" = xyes; then
          AC_MSG_CHECKING([for coverage module])
          $PYTHON -c 'import coverage' 2>/dev/null
          if test $? = 0; then
            AC_MSG_RESULT([yes])
          else
            AC_MSG_RESULT([no])
            with_coverage=no
          fi
        fi
      fi

      CPPFLAGS=$save_CPPFLAGS
    fi # have_python

  fi # enabled_shared
fi # with_python

AC_SUBST(PYTHON_INCLUDES)
AC_SUBST(PYTHON_LIBS)
AM_CONDITIONAL(WITH_PYTHON, test x"$have_python" = "xyes")
AM_CONDITIONAL(WITH_COVERAGE, test x"$with_coverage" = "xyes")

##############################################################################
# Compiler flags
AC_ARG_ENABLE(debug,
              [AS_HELP_STRING([--enable-debug],[compile for debugging])],
	      enable_debug=$enableval, enable_debug=no)
if test "$enable_debug" = "yes"; then
	CFLAGS="-g -Wall -O0"
	CXXFLAGS="-g -Wall -O0"
	FFLAGS="-g -Wall -O0"
	AC_DEFINE(DEBUG,1,[define to enable debugging code])
fi

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_INT8_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
