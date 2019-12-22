CC:=$(CROSS_COMPILE)gcc
all:
	$(CC) $(CFLAGS) -O0 -g -rdynamic -Wall -fsanitize=address asan_hello.c -lpthread -o asan_hello.out
clean:
	rm *.o *.out -rf
