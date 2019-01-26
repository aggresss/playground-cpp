#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])

AM_INIT_AUTOMAKE()

AC_CONFIG_SRCDIR([hello.c])
AC_CONFIG_HEADERS([config.h])

AC_SUBST(VERSION_STRING, [v0.0.1])
AC_CONFIG_FILES([version.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

# with arg test
AC_ARG_WITH([argtest001],
    [AS_HELP_STRING([--with-argtest001],
        [Enable arg_test 001])],
    [argtest001="yes"],
    [])

if test "x$argtest001" = "xyes"; then
    AC_DEFINE(ARG_TEST001, 1, [Enable arg test 001])
fi

AC_CONFIG_FILES([Makefile])
AC_OUTPUT


echo "======== see me ========"

