CC = gcc
CXX = g++
CFLAGS = -g
OBJS = $(patsubst %c, %o, $(wildcard *.c))
OBJS += $(patsubst %cpp, %o, $(wildcard *.cpp))
HEADER = $(wildcard ../include/*.h)


PATH_LIB=$(shell cd ../lib && pwd)
PATH_PJSIP=$(PATH_LIB)/pjproject
export PKG_CONFIG_PATH=$(PATH_PJSIP)/prefix/lib/pkgconfig

CFLAGS += `pkg-config --cflags libpjproject`
LDFLAGS += `pkg-config --libs libpjproject`

Target = pjsip_test.out

all: $(Target)

%.o:%.cpp $(HEADER)
	$(CXX) $(CFLAGS) -c $< -o $@

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(Target):$(OBJS)
	echo ${PKG_CONFIG_PATH}
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY:clean
clean:
	rm *.o $(Target)
