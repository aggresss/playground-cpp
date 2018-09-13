# Makefile for static test
# environment create by https://github.com/aggresss/docker-library/blob/glibc/glibc/2.27/Dockerfile
# docker pull aggresss/glibc:2.27
# conclution:
# if LDFLAGS no "-static" will -> "Segmentation fault" and size smaller than add it.

LIBP_GLIBC = /usr/local/lib
CC = gcc
CLAGS += -g

LDFLAGS += -static
LDFLAGS += -L$(LIBP_GLIBC) -l:libm-2.27.a -Wl,--whole-archive -l:libpthread.a -Wl,--no-whole-archive -l:libc.a -l:libdl.a

# equal as => LDFLAGS += -L$(LIBP_GLIBC) $(LIBP_GLIBC)/libm-2.27.a -Wl,--whole-archive $(LIBP_GLIBC)/libpthread.a -Wl,--no-whole-archive $(LIBP_GLIBC)/libc.a $(LIBP_GLIBC)/libdl.a

test.out: gethostbyname.o
	$(CC) $^ $(LDFLAGS) -o $@

%.o : %.c
	echo "CC" $<
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o *.out

