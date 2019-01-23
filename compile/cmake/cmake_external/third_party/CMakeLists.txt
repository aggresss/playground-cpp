include(ExternalProject)

ExternalProject_Add(external-wolfssl
        GIT_REPOSITORY https://github.com/wolfssl/wolfssl.git
        GIT_TAG v3.15.7-stable
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/wolfssl
        CONFIGURE_COMMAND ./autogen.sh &&
            ./configure
            --enable-static
            --disable-shared
            --enable-opensslextra
            --disable-debug
            --host=${TOOLCHAIN_PREFIX}
            --prefix=${CMAKE_CURRENT_SOURCE_DIR}/wolfssl/output/${TOOLCHAIN_TRIPLET}
        BUILD_COMMAND make
        BUILD_IN_SOURCE 1
        INSTALL_COMMAND make install
)

ExternalProject_Add(external-curl
        GIT_REPOSITORY https://github.com/curl/curl.git
        GIT_TAG curl-7_63_0
        CONFIGURE_COMMAND ./buildconf &&
            ./configure
            --host=${TOOLCHAIN_PREFIX}
            --prefix=${CMAKE_CURRENT_SOURCE_DIR}/curl/output/${TOOLCHAIN_TRIPLET}
            --with-wolfssl=${CMAKE_CURRENT_SOURCE_DIR}/wolfssl/output/${TOOLCHAIN_TRIPLET}
            --enable-shared=no
            --without-zlib
            --without-libidn2
            --disable-libtool-lock
            --enable-http
            --disable-ftp
            --disable-file
            --disable-ldap
            --disable-ldaps
            --disable-rtsp
            --disable-proxy
            --disable-dict
            --disable-telnet
            --disable-tftp
            --disable-pop3
            --disable-imap
            --disable-smb
            --disable-smtp
            --disable-gopher
            --disable-manual
            --disable-libcurl-option
            --enable-ipv6
            --disable-largefile
            --disable-sspi
            --disable-ntlm-wb
            --disable-unix-sockets
            --disable-cookies
            --disable-crypto-auth
            --disable-tls-srp
            --without-ssl
        BUILD_COMMAND make
        BUILD_IN_SOURCE 1
        INSTALL_COMMAND make install
)
