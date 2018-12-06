# Makefile for cpputest
CC = gcc
CXX = g++
CFLAGS = -g
CXXFLAGS = -g -std=c++14
OBJS = $(patsubst %c, %o, $(wildcard src/*.c))
OBJS += $(patsubst %cpp, %o, $(wildcard test/*.cpp))


PATH_REPO=$(shell git rev-parse --show-toplevel)
PATH_PWD=$(shell pwd)
PATH_LIB=$(PATH_PWD)/lib
PATH_CPPUTEST=$(PATH_LIB)/cpputest
PATH_CPPUTEST_PREFIX=$(PATH_CPPUTEST)/prefix

CFLAGS += -DCPPUTEST
CXXFLAGS += -DCPPUTEST
CFLAGS += -I$(PATH_CPPUTEST_PREFIX)/include -I$(PATH_PWD)/src
CXXFLAGS += -I$(PATH_CPPUTEST_PREFIX)/include -I$(PATH_PWD)/src
LDFLAGS += -L$(PATH_CPPUTEST_PREFIX)/lib -l:libCppUTest.a
LDFLAGS += -lpthread -ldl -lrt

Target = cpputest_test.out

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
	rm -rf *.o $(Target)
	cd $(PATH_PWD)/src && rm -rf *.o
	cd $(PATH_PWD)/test && rm -rf *.o

