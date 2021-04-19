# Makefile for abseil
CXX = g++
CXXFLAGS = -g -std=c++11
OBJS += $(patsubst %cpp, %o, $(wildcard *.cpp))
HEADER = $(wildcard ../include/*.h)

PATH_LIB=$(shell cd ../lib && pwd)
PATH_ABSEIL=$(PATH_LIB)/abseil
PATH_ABSEIL_OUT=$(PATH_ABSEIL)/out

CXXFLAGS += -I$(PATH_ABSEIL_OUT)/include

LDFLAGS += -L$(PATH_ABSEIL_OUT)/lib
LDFLAGS += -lpthread -ldl

Target = abseil_test.out

all: $(Target)

DEPS := $(OBJS:.o=.d)
-include $(DEPS)
CXXFLAGS += -MMD -MP

%.o:%.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(Target):$(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY:clean
clean:
	rm -rf *.o *.out $(DEPS) $(Target)
