# Makefile for googletest test
CC = gcc
CXX = g++
CFLAGS = -g
CXXFLAGS = -g -std=c++11
OBJS = $(patsubst %c, %o, $(wildcard *.c))
OBJS += $(patsubst %cpp, %o, $(wildcard *.cpp))
HEADER = $(wildcard ../include/*.h)

PATH_LIB=$(shell cd ../../lib && pwd)
PATH_GOOGLETEST=$(PATH_LIB)/googletest
PATH_GOOGLETEST_BUILD=$(PATH_GOOGLETEST)/build

CFLAGS += -I$(PATH_GOOGLETEST)/googletest/include -DGTEST_HAS_PTHREAD=1 -pthread
CFLAGS += -I$(PATH_GOOGLETEST)/googlemock/include
CXXFLAGS += -I$(PATH_GOOGLETEST)/googletest/include -DGTEST_HAS_PTHREAD=1 -pthread
CXXFLAGS += -I$(PATH_GOOGLETEST)/googlemock/include

LDFLAGS += -L$(PATH_GOOGLETEST_BUILD)/lib -l:libgmock.a -l:libgtest.a
LDFLAGS += -lpthread -ldl

Target = gmock_test.out

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
	rm -rf *.o *.out $(DEPS) $(Target)
