CXX = g++
CFLAGS = -g -Wall -std=c++14
LDFLAGS =

target = main.out
srcs = $(wildcard *.cpp)
objs = $(srcs:.cpp=.o)
headers = $(wildcard *.hpp)

.PHONY: all
	all: $(target)

$(target): $(objs) $(headers) FORCE
	$(CXX) -o $@ $(objs) $(LDFLAGS)

$(objs):%.o:%.cpp FORCE
	$(CXX) $(CFLAGS) -c $<

.PHONY: FORCE
FORCE:

clean:
	rm -f $(target) *.o
