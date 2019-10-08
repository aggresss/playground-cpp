all:
	gcc -O0 -g -rdynamic -finstrument-functions -funwind-tables segfault_catch.c hello.c -lpthread -o segfault_hello.out
clean:
	rm *.o *.out -rf
