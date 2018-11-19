# Makefile for cunit test
CC = gcc
CXX = g++
CFLAGS = -g
CXXFLAGS = -g -std=c++11
OBJS = $(patsubst %c, %o, $(wildcard *.c))
OBJS += $(patsubst %cpp, %o, $(wildcard *.cpp))
HEADER = $(wildcard ../include/*.h)

PATH_LIB=$(shell cd ../lib && pwd)
PATH_CUNIT_PREFIX=$(PATH_LIB)/CUnit/prefix

CFLAGS += -I$(PATH_CUNIT_PREFIX)/include
CXXFLAGS += -I$(PATH_CUNIT_PREFIX)/include
LDFLAGS += -L$(PATH_CUNIT_PREFIX)/lib -l:libcunit.a
LDFLAGS += -lpthread -ldl

Target = cunit_test.out

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
