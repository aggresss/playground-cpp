CC = gcc
CXX = g++
CFLAGS = -g
CXXFLAGS = -g -std=c++14
OBJS = $(patsubst %c, %o, $(wildcard *.c))
OBJS += $(patsubst %cpp, %o, $(wildcard *.cpp))
HEADER = $(wildcard ../include/*.h)

PATH_LIB=$(shell cd ../../lib && pwd)
PATH_LIBUV=$(PATH_LIB)/libuv/prefix

CFLAGS += -I$(PATH_LIBUV)/include
CXXFLAGS += -I$(PATH_LIBUV)/include
LDFLAGS += -L$(PATH_LIBUV)/lib -l:libuv.a
LDFLAGS += -lrt -lpthread -lnsl -ldl 

Target = $(shell pwd | xargs basename).out

all: $(Target)

%.o:%.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(Target):$(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY:clean
clean:
	rm -rf *.o $(DEPS) $(Target)
