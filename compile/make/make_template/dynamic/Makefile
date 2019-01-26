######################################
# dynamic Makefile template
######################################

#target you can change test to what you want
TARGET  := libtest.so

#compile and lib parameter
CC      := gcc
LIBS    :=
LDFLAGS :=
DEFINES :=
INCLUDE := -I.
CFLAGS  := -g -Wall -O3 $(DEFINES) $(INCLUDE)
CXXFLAGS:= $(CFLAGS) -DHAVE_CONFIG_H
SHARE   := -fPIC -shared -o

#source file
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

.PHONY : objs clean distclean rebuild

all : $(TARGET)

objs : $(OBJS)

rebuild: distclean all

clean :
	rm -fr *.o

distclean : clean
	rm -fr $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) $(SHARE) $@ $(OBJS) $(LDFLAGS) $(LIBS)

