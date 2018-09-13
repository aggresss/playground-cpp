# Makefile for static test
# environment create by https://github.com/aggresss/docker-library/blob/glibc/glibc/2.27/Dockerfile
# conclution:
# if LDFLAGS no "-static-libgcc" will -> "Segmentation fault" and size smaller than add it.

LIBP_GLIBC = .
CC = gcc
CLAGS += -g

LDFLAGS += -L$(LIBP_GLIBC) $(LIBP_GLIBC)/libm-2.27.a -Wl,--whole-archive $(LIBP_GLIBC)/libpthread.a -Wl,--no-whole-archive $(LIBP_GLIBC)/libc.a $(LIBP_GLIBC)/libdl.a \
    -static-libgcc

test.out: gethostbyname.o
    $(CC) $^ $(LDFLAGS) -o $@

%.o : %.c
	echo "CC" $<
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o *.out

