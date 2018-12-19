#!/bin/bash

gcc -pg -o test.out gprofile_test.c
./test.out
gprof -b test.out gmon.out

