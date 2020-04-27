<img src="icon.png" align="right" height="110"/>
# 🚀

<h1 align="center">
  <br>
  playground-cpp
  <br>
</h1>

<h4 align="center">A Playground for C++</h4>
<p align="center">
  <a href="https://badge.fury.io/gh/aggresss%2Fplayground-cpp"><img src="https://badge.fury.io/gh/aggresss%2Fplayground-cpp.svg" alt="GitHub version"></a>
  <a href="https://github.com/aggresss/playground-cpp/blob/master/LICENSE"><img src="https://img.shields.io/github/license/aggresss/playground-cpp.svg" alt="GitHub license"></a>
  <a href="https://www.travis-ci.org/aggresss/playground-cpp"><img src="https://www.travis-ci.org/aggresss/playground-cpp.svg?branch=master" alt="Build Status"></a>
  <a href="https://coveralls.io/github/aggresss/playground-cpp?branch=master"><img src="https://coveralls.io/repos/github/aggresss/playground-cpp/badge.svg?branch=master" alt="Coverage Status"></a>
</p>
<br>

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

  - add LIBRARY to the 'LD_PRELOAD' enrironment variable when need preload
  - add LIBDIR to the 'LD_LIBRARY_PATH' environment variable during execution
  - add LIBDIR to the 'LD_RUN_PATH' environment variable during linking
  - use the '-Wl,-rpath -Wl,LIBDIR' linker flag
  - have your system administrator add LIBDIR to '/etc/ld.so.conf'

---

Some influential environment variables:
 - CC          C compiler command
 - CFLAGS      C compiler flags
 - LDFLAGS     linker flags, e.g. -L\<lib dir\> if you have libraries in a<br>
              nonstandard directory \<lib dir\>
 - LIBS        libraries to pass to the linker, e.g. -l\<library\>
 - CPPFLAGS    (Objective) C/C++ preprocessor flags, e.g. -I\<include dir\> if<br>
              you have headers in a nonstandard directory <include dir>
 - CPP         C preprocessor
 - CXX         C++ compiler command
 - CXXFLAGS    C++ compiler flags

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

---

