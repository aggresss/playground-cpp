FROM ubuntu:16.04

MAINTAINER yujia <yujia@qiniu.com>

# Pick up some build dependencies
RUN sed -i 's/archive.ubuntu/mirrors.aliyun/g' /etc/apt/sources.list && \
apt-get update && apt-get install -y --no-install-recommends \
tzdata \
curl \
vim \
ssh \
git \
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
zlib1g-dev \
libbz2-dev \
liblzma-dev \
&& \
apt-get clean && \
rm -rf /var/lib/apt/lists/*

# Modify timezone to GTM+8
ENV TZ=Asia/Shanghai
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

