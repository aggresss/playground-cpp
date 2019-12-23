CC:=$(CROSS_COMPILE)gcc
all:
	$(CC) $(CFLAGS) -O0 -g -rdynamic -Wall -fstack-protector-all stack_protector_hello.c -lpthread -o stack_protector_hello.out
clean:
	rm *.o *.out -rf
