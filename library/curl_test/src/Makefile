CC = gcc
CXX = g++
CFLAGS = -g
CXXFLAGS = -g -std=c++11
OBJS = $(patsubst %c, %o, $(wildcard *.c))
OBJS += $(patsubst %cpp, %o, $(wildcard *.cpp))
HEADER = $(wildcard ../include/*.h)

PATH_LIB=$(shell cd ../lib && pwd)
PATH_CURL_PREFIX=$(PATH_LIB)/curl/prefix
PATH_OPENSSL_PREFIX=$(PATH_LIB)/openssl/prefix

CFLAGS += -I$(PATH_CURL_PREFIX)/include -I$(PATH_OPENSSL_PREFIX)/include
CXXFLAGS += -I$(PATH_CURL_PREFIX)/include -I$(PATH_OPENSSL_PREFIX)/include
LDFLAGS += -L$(PATH_CURL_PREFIX)/lib -l:libcurl.a
LDFLAGS += -L$(PATH_OPENSSL_PREFIX)/lib -l:libssl.a -l:libcrypto.a
LDFLAGS += -lpthread -ldl

Target = curl_test.out

all: $(Target)

DEPS := $(OBJS:.o=.d)
-include $(DEPS)
CFLAGS += -MMD -MP
CXXFLAGS += -MMD -MP

%.o:%.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(Target):$(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY:clean
clean:
	rm -rf *.o $(DEPS) $(Target)
