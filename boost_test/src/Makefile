CC = gcc
CXX = g++
CFLAGS = -g
CXXFLAGS = -g -std=c++11
OBJS = $(patsubst %c, %o, $(wildcard *.c))
OBJS += $(patsubst %cpp, %o, $(wildcard *.cpp))
HEADER = $(wildcard ../include/*.h)


PATH_LIB=$(shell cd ../lib && pwd)
PATH_BOOST=$(PATH_LIB)/boost_1_68_0
PATH_BOOST_PREFIX=$(PATH_BOOST)/prefix

CFLAGS += -I$(PATH_BOOST_PREFIX)/include
CXXFLAGS += -I$(PATH_BOOST_PREFIX)/include
LDFLAGS += -lboost_system -L$(PATH_BOOST_PREFIX)/lib
LDFLAGS += -lpthread -ldl -lrt

Target = boost_test

all: $(Target)

%.o:%.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(Target):$(OBJS)
	echo ${PKG_CONFIG_PATH}
	$(CXX) -o $@ $^ $(LDFLAGS)
.PHONY:clean
clean:
	rm *.o $(Target)
