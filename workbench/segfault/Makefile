all: segfault_hello.o
	gcc -finstrument-functions -rdynamic segfault_hello.o -o segfault_hello.out
segfault_hello.o:
	gcc -O0 -g -finstrument-functions -c segfault_hello.c
clean:
	rm *.o *.out -rf
