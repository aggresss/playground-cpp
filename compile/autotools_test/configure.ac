dnl Example of default-enabled feature

AC_PREREQ(2.59)
AC_INIT(autotools_exe, 1.0)

AC_ARG_ENABLE([foo],
    AS_HELP_STRING([--disable-foo], [Disable feature foo]))

AS_IF([test "x$enable_foo" != "xno"], [
  dnl Do the stuff needed for enabling the feature
])

dnl Example of default-disabled feature
AC_ARG_ENABLE([bar],
    AS_HELP_STRING([--enable-bar], [Enable feature bar]))

AS_IF([test "x$enable_bar" = "xyes"], [
  dnl Do the stuff needed for enabling the feature
])

AC_OUTPUT
