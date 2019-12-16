CROSS_COMPILE?=arm-hisiv300-linux-
export CC:=$(CROSS_COMPILE)gcc
all:
	$(CC) $(CFLAGS) -O0 -g3 -rdynamic -finstrument-functions -funwind-tables segfault_catch.c hello.c -lpthread -o segfault_hello.out
clean:
	rm *.o *.out -rf
