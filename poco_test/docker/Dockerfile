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

# VIM configuration
RUN wget -P /root https://raw.githubusercontent.com/aggresss/dotfiles/master/vim/.vimrc

# Modify timezone to GTM+8
ENV TZ=Asia/Shanghai
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone



