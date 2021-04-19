CC = gcc
CXX = g++
CFLAGS = -g
CXXFLAGS = -g -std=c++11
OBJS = $(patsubst %c, %o, $(wildcard *.c))
OBJS += $(patsubst %cpp, %o, $(wildcard *.cpp))
HEADER = $(wildcard ../include/*.h)


PATH_LIB=$(shell cd ../lib && pwd)
PATH_BOOST=$(PATH_LIB)/boost
PATH_BOOST_PREFIX=$(PATH_BOOST)/prefix

CFLAGS += -I$(PATH_BOOST_PREFIX)/include
CXXFLAGS += -I$(PATH_BOOST_PREFIX)/include
LDFLAGS += -L$(PATH_BOOST_PREFIX)/lib -lboost_system
LDFLAGS += -lpthread -ldl -lrt

Target = boost_test.out

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
