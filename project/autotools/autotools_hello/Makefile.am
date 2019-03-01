AUTOMARK_OPTIONS = foreign

bin_PROGRAMS = hell hell_static

# Build a libtool library, libhello.la for installation in libdir.
lib_LTLIBRARIES = libhello.la
libhello_la_SOURCES = val.h val.c get.h get.c sum.h sum.c
libhello_la_LDFLAGS = -version-info 3:12:1

# Build hell from main.c and libhello.la
hell_SOURCES = main.c
hell_LDADD = libhello.la

# Create a statically linked version of hell.
hell_static_SOURCES = main.c
hell_static_LDADD = libhello.la
hell_static_LDFLAGS = -static

