CC = gcc
CXX = g++
Cflag = -g
OBJS = $(patsubst %c, %o, $(wildcard *.c))
OBJS += $(patsubst %cpp, %o, $(wildcard *.cpp))
HEADER = $(wildcard ../include/*.h)


#Libs = -lavfilter -lpostproc -lavformat -lavcodec -lswscale -lavutil -lswresample -lx264 -lfdk-aac -lfreetype -lpthread
#Libs += -lz -lm -lbz2 -llzma
#Libs +=  -ldl -lrt

PATH_LIB=$(shell cd ../lib && pwd)
PATH_OPENSSL=$(PATH_LIB)/openssl
PATH_FDKAAC=$(PATH_LIB)/fdk-aac
PATH_X264=$(PATH_LIB)/x264
PATH_FREETYPE=$(PATH_LIB)/freetype
PATH_FFMPEG=$(PATH_LIB)/ffmpeg

CFLAGS += `pkg-config --cflags libavfilter libavformat libavcodec libswscale libavutil libswresample`
LDFLAGS += `pkg-config --libs libavfilter libavformat libavcodec libswscale libavutil libswresample`

Target = ffmpeg_test.out

all: $(Target)

DEPS := $(OBJS:.o=.d)
-include $(DEPS)
CFLAGS += -MMD -MP
CXXFLAGS += -MMD -MP

%.o:%.cpp $(HEADER)
	$(CXX) $(CFLAGS) -c $< -o $@

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(Target):$(OBJS)
	echo ${PKG_CONFIG_PATH}
	pkg-config --cflags libavfilter libavformat libavcodec libswscale libavutil libswresample
	pkg-config --libs libavfilter libavformat libavcodec libswscale libavutil libswresample
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY:clean
clean:
	rm *.o $(DEPS) $(Target)
