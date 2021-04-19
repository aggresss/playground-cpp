# Makefile for lua_test
CC = gcc
CXX = g++
CFLAGS = -g
CXXFLAGS = -g -std=c++14
OBJS = $(patsubst %.c, %.o, $(wildcard *.c))
OBJS += $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADER = $(wildcard ../include/*.h)
HEADER += $(wildcard ../include/*.hpp)
BINS = $(OBJS:%.o=%.out)
PATH_LIBLUA = $(shell cd ../lib && pwd)/lua/prefix
CFLAGS += -I$(PATH_LIBLUA)/include
CXXFLAGS += -I$(PATH_LIBLUA)/include
LDFLAGS += -L$(PATH_LIBLUA)/lib -llua -lm -ldl

.PHONY: all
all: $(BINS)

.PHONY: clean
clean:
	rm -rf $(OBJS) $(DEPS) $(BINS)

%.out:%.o
	$(CC) -o $@ $< $(LDFLAGS)

%.o:%.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
