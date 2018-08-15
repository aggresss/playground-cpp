CC = g++
Cflag = -g
SRC = $(wildcard *.cpp)
OBJS = $(patsubst %cpp, %o, $(SRC))
HEADER = $(wildcard ../include/*.h)

#Lib1= -lavfilter -lavformat -lavdevice -lavcodec -lswscale -lavutil -lswresample -lpthread 
#Lib2= -lz -lm -lbz2 -llzma
#Lib3=  -ldl -lrt

PATH_LIB=$(shell cd ../lib && pwd)
PATH_FDKAAC=$(PATH_LIB)/fdk-aac
PATH_X264=$(PATH_LIB)/x264
PATH_FREETYPE=$(PATH_LIB)/freetype
PATH_FFMPEG=$(PATH_LIB)/ffmpeg
export PKG_CONFIG_PATH=$(PATH_X264)/prefix/lib/pkgconfig:$(PATH_FDKAAC)/prefix/lib/pkgconfig:$(PATH_FFMPEG)/prefix/lib/pkgconfig

CFLAGS += `pkg-config --cflags libavfilter libavformat libavdevice libavcodec libswscale libavutil libswresample`
LDFLAGS += `pkg-config --libs libavfilter libavformat libavdevice libavcodec libswscale libavutil libswresample`

Target = ffmpeg_test

all: $(Target)

%.o:%.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(Target):$(OBJS)
	echo ${PKG_CONFIG_PATH}
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY:clean
clean:
	rm *.o $(Target)
