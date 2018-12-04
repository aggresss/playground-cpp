# Makefile for coveralls test
CC = gcc
CXX = g++
CFLAGS = -O0 -g -fno-inline
CXXFLAGS = -O0 -g -fno-inline -std=c++14
OBJS = $(patsubst %c, %o, $(wildcard ci/coveralls/src/*.c))
OBJS += $(patsubst %c, %o, $(wildcard ci/coveralls/test/*.c))

CFLAGS += -fprofile-arcs -ftest-coverage
CXXFLAGS += -fprofile-arcs -ftest-coverage
LDFLAGS += -fprofile-arcs -ftest-coverage

Target = test_all.out

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
	cd ci/coveralls/test && rm -rf *.o *.d *.gcov *.gcno *.gcda
	cd ci/coveralls/src && rm -rf *.o *.d *.gcov *.gcno *.gcda

