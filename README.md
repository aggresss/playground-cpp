# playground-cpp

[![GitHub license](https://img.shields.io/github/license/aggresss/playground-cpp.svg)](https://github.com/aggresss/playground-cpp/blob/master/LICENSE)
[![Build Status](https://www.travis-ci.org/aggresss/playground-cpp.svg?branch=master)](https://www.travis-ci.org/aggresss/playground-cpp)
[![Coverage Status](https://coveralls.io/repos/github/aggresss/playground-cpp/badge.svg?branch=master)](https://coveralls.io/github/aggresss/playground-cpp?branch=master)

CFLAGS
  1. -D macro => current directory => -I path
  2. Environment Variables => CPATH / C_INCLUDE_PATH / CPLUS_INCLUDE_PATH / OBJC_INCLUDE_PATH
  3. /usr/include => /usr/local/include => /usr/lib/gcc/x86_64-xxxxxx => .....

LDFLAGS
  1. -L
  2. LIBRARY_PATH
  3. /usr/local/lib => /lib/x86_64-linux-gnu => /usr/lib/x86_64-linux-gnu => /lib => /usr/lib

ref: https://gcc.gnu.org/onlinedocs/gcc/Environment-Variables.html

pkg-config
  - PKG_CONFIG_PATH
  
ref: https://linux.die.net/man/1/pkg-config

load and run
- LD_LIBRARY_PATH

---

apt-file list libc++-dev >> ~/temp.txt && vim ~/temp.txt => :%g!/.a$/d
- libc++-dev: /usr/lib/x86_64-linux-gnu/libc++.a
- libc++-dev: /usr/lib/x86_64-linux-gnu/libc++experimental.a

apt-file list libc6-dev >> ~/temp.txt && vim ~/temp.txt => :%g!/.a$/d
- libc6-dev: /usr/lib/x86_64-linux-gnu/libBrokenLocale.a
- libc6-dev: /usr/lib/x86_64-linux-gnu/libanl.a
- libc6-dev: /usr/lib/x86_64-linux-gnu/libc.a
- libc6-dev: /usr/lib/x86_64-linux-gnu/libc_nonshared.a
- libc6-dev: /usr/lib/x86_64-linux-gnu/libcrypt.a
- libc6-dev: /usr/lib/x86_64-linux-gnu/libdl.a
- libc6-dev: /usr/lib/x86_64-linux-gnu/libg.a
- libc6-dev: /usr/lib/x86_64-linux-gnu/libm-2.27.a
- libc6-dev: /usr/lib/x86_64-linux-gnu/libm.a
- libc6-dev: /usr/lib/x86_64-linux-gnu/libmcheck.a
- libc6-dev: /usr/lib/x86_64-linux-gnu/libmvec.a
- libc6-dev: /usr/lib/x86_64-linux-gnu/libmvec_nonshared.a
- libc6-dev: /usr/lib/x86_64-linux-gnu/libnsl.a
- libc6-dev: /usr/lib/x86_64-linux-gnu/libpthread.a
- libc6-dev: /usr/lib/x86_64-linux-gnu/libpthread_nonshared.a
- libc6-dev: /usr/lib/x86_64-linux-gnu/libresolv.a
- libc6-dev: /usr/lib/x86_64-linux-gnu/librpcsvc.a
- libc6-dev: /usr/lib/x86_64-linux-gnu/librt.a
- libc6-dev: /usr/lib/x86_64-linux-gnu/libutil.a

musl-1.1.19 => ./configure --disable-shared
- Scrt1.o
- crt1.o
- crti.o
- crtn.o
- rcrt1.o
- libc.a
- libcrypt.a
- libdl.a
- libm.a
- libpthread.a
- libresolv.a
- librt.a
- libutil.a
- libxnet.a
- musl-gcc.specs

