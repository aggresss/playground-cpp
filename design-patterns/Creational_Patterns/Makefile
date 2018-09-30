CXX = g++
CFLAGS = -g -std=c++14 -Wall
LDFLAGS =

target = main.out
srcs = $(wildcard *.cpp)
objs = $(srcs:.cpp=.o)
	headers = $(wildcard *.h)


.PHONY: all
	all: $(target)

$(target): $(objs) $(headers) FORCE
	$(CXX) -o $@ $(objs) $(LDFLAGS)

$(objs):%.o:%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

.PHONY: FORCE
FORCE:

clean:
	rm -f $(target) *.o

