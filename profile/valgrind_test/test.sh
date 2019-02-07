#!/bin/bash

g++ -g test.cpp -o test.out
valgrind --tool=memcheck --leak-check=full ./test.out

