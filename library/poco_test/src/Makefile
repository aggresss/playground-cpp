CC = g++
CFLAGS = -g
SRC = $(wildcard *.cpp)
OBJS = $(patsubst %cpp, %o, $(SRC))
HEADER = $(wildcard ../include/*.h)


PATH_LIB=$(shell cd ../lib && pwd)
PATH_POCO=$(PATH_LIB)/poco

LIBS = -lPocoJSON -lPocoXML -lPocoUtil -lPocoNet -lPocoEncodings -lPocoFoundation

CFLAGS += -I$(PATH_POCO)/prefix/include

# ld faild.
# LDFLAGS += -L$(PATH_POCO)/prefix/lib $(LIBS)

# ld ok. size:4.6M  time:0m0.786s
# LDFLAGS += -L$(PATH_POCO)/prefix/lib -Wl,--whole-archive $(LIBS) -Wl,--no-whole-archive

# ld ok. size:2.9M time:0m0.659s
# LDFLAGS += -L$(PATH_POCO)/prefix/lib -Wl,--start-group $(LIBS) -Wl,--end-group

# ld ok. size:2.9M time:0m0.656s
LDFLAGS += -L$(PATH_POCO)/prefix/lib -Xlinker "-(" $(LIBS) -Xlinker "-)"

LDFLAGS += -lpthread -ldl -lrt

DEPS := $(OBJS:.o=.d)
-include $(DEPS)
CFLAGS += -MMD -MP
CXXFLAGS += -MMD -MP


Target = poco_test.out

.PHONY:all
all: $(Target)

%.o:%.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(Target):$(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY:clean
clean:
	rm -rf $(Target) $(DEPS) *.o
