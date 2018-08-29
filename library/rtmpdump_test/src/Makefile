CC = gcc
CXX = g++
CFLAGS = -g
CXXFLAGS = -g -std=c++11
OBJS = $(patsubst %c, %o, $(wildcard *.c))
OBJS += $(patsubst %cpp, %o, $(wildcard *.cpp))
HEADER = $(wildcard ../include/*.h)

PATH_LIB=$(shell cd ../lib && pwd)
PATH_RTMPDUMP=$(PATH_LIB)/rtmpdump
PATH_LIBRTMP=$(PATH_RTMPDUMP)/librtmp
PATH_OPENSSL_PREFIX=$(PATH_LIB)/openssl/prefix
PATH_ZLIB_PREFIX=$(PATH_LIB)/zlib/prefix

CFLAGS += -I$(PATH_RTMPDUMP)
CXXFLAGS += -I$(PATH_RTMPDUMP)
LDFLAGS += -l:librtmp.a -L$(PATH_LIBRTMP)

CFLAGS += -I$(PATH_OPENSSL_PREFIX)/include
CXXFLAGS += -I$(PATH_OPENSSL_PREFIX)/include
LDFLAGS += -l:libssl.a -l:libcrypto.a -L$(PATH_OPENSSL_PREFIX)/lib

CFLAGS += -I$(PATH_ZLIB_PREFIX)/include
CXXFLAGS += -I$(PATH_ZLIB_PREFIX)/include
LDFLAGS += -l:libz.a -L$(PATH_ZLIB_PREFIX)/lib

LDFLAGS += -lpthread -ldl

Target = rtmpdump_test.out

all: $(Target)

%.o:%.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(Target):$(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY:clean
clean:
	rm -rf *.o $(Target)
