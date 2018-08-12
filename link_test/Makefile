#
# Makefile for link_test
#

PWD=$(shell pwd)

CPPFLAGS=
CC=gcc
CFLAGS=
LD=ld
LDFLAGS=
LIBS=
CXX=g++
CXXFLAGS=

all:
	echo
so:
	$(CXX) one.cpp two.cpp -fPIC -shared -o libtest.so
a: one.o two.o
	ar -r libtest.a one.o two.o
main: so
	$(CXX) main.cpp -L. -ltest -o main
main-static: a
	# $(CXX) main.cpp libtest.a -static -o main-static
	$(CXX) main.cpp -static -o main-static -L. -ltest
main-compose_1: a
	$(CXX) main.cpp libtest.a -o main-compose_1
main-compose_2: a
	$(CXX) main.cpp -o main-compose_2 -L. -l:libtest.a
run: main
	@export LD_LIBRARY_PATH=.:${LD_LIBRARY_PATH} && ./main
clean:
	rm -rf  *.o *.so *.a main main-compose* main-static

%.o : %.c
	@echo "CC " $<
	@$(CC) $(CFLAGS) -c $<
.cpp.o:
	@echo "CXX " $<
	@$(CXX) $(CXXFLAGS) -c $<

