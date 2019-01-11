#!/bin/bash
shopt -s extglob
rm -rf !(sum.c|sum.h|val.c|val.h|get.c|get.h|main.c|Makefile.am|configure.ac|autogen.sh|autoremove.sh) .* >/dev/null 2>&1
