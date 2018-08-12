FROM ubuntu:16.04

MAINTAINER yujia <aggresss@163.com>

# Pick up some build dependencies
RUN sed -i 's/archive.ubuntu/mirrors.aliyun/g' /etc/apt/sources.list && \
apt-get update && apt-get install -y --no-install-recommends \
sudo \
tzdata \
curl \
wget \
vim \
ssh \
git \
ca-certificates \
unzip \
xz-utils \
build-essential \
gdb \
autoconf \
automake \
libtool \
python \
pkg-config \
flex \
bison \
yasm \
&& \
apt-get clean && \
rm -rf /var/lib/apt/lists/*

# Modify timezone to GTM+8
ENV TZ=Asia/Shanghai
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN git clone --depth=1 https://github.com/ossrs/srs.git && \
cd srs/trunk && \
./configure && \
make

EXPOSE 8080
EXPOSE 1935

WORKDIR /srs/trunk
ENTRYPOINT ["/srs/trunk/objs/srs"]
CMD ["-c", "conf/http.flv.live.conf"]
