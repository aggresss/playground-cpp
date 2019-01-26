# STEP

- touch Makefile.am
- autoscan -> mv configure.scan configure.ac
- add `AM_INIT_AUTOMAKE()` to configure.ac
- touch AUTHORS COPYING ChangeLog NEWS README
- autoreconf -vif
- ./configure; make; make install

