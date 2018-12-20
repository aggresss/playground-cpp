# Makefile for apr
CC = gcc
CXX = g++
CFLAGS = -g
CXXFLAGS = -g -std=c++14
OBJS = $(patsubst %c, %o, $(wildcard *.c))
OBJS += $(patsubst %cpp, %o, $(wildcard *.cpp))
HEADER = $(wildcard ../include/*.h)


PATH_REPO=$(shell git rev-parse --show-toplevel)
PATH_PWD=$(shell pwd)
PATH_LIB=$(PATH_PWD)/../../lib
PATH_APR=$(PATH_LIB)/apr
PATH_APR_PREFIX=$(PATH_APR)/prefix

CFLAGS += -I$(PATH_APR_PREFIX)/include/apr-1
CXXFLAGS += -I$(PATH_APR_PREFIX)/include/apr-1
LDFLAGS += -L$(PATH_APR_PREFIX)/lib -l:libapr-1.a
LDFLAGS += -lpthread -ldl -lrt

Target = apr_pool_test.out

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
	rm -rf *.o *.out $(Target) $(DEPS)

