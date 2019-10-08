all: hello.o
	gcc -finstrument-functions -finstrument-functions segfault_hello.o -o segfault_hello
hello.o:
	gcc  -finstrument-functions  -c segfault_hello.c
clean:
	rm *.o hello -rf
