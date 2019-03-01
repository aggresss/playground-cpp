#!/bin/sh

aclocal && \
	autoheader && \
	libtoolize && \
	autoconf && \
	touch NEWS README AUTHORS ChangeLog && \
	automake --add-missing --force-missing --copy
