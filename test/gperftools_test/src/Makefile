# Makefile for gperftools test
CC = gcc
CXX = g++
CFLAGS = -g
CXXFLAGS = -g -std=c++11
OBJS = $(patsubst %c, %o, $(wildcard *.c))
OBJS += $(patsubst %cpp, %o, $(wildcard *.cpp))
HEADER = $(wildcard ../include/*.h)

PATH_LIB=$(shell cd ../lib && pwd)
PATH_GPERFTOOLS=$(PATH_LIB)/gperftools
PATH_GPERFTOOLS_PREFIX=$(PATH_GPERFTOOLS)/prefix

CFLAGS += -I$(PATH_GPERFTOOLS_PREFIX)/include
CXXFLAGS += -I$(PATH_GPERFTOOLS_PREFIX)/include

LDFLAGS += -L$(PATH_GPERFTOOLS_PREFIX)/lib -l:libprofiler.a
LDFLAGS += -lpthread -ldl

Target = gperftools_test.out

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
