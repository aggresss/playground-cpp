cmake_minimum_required(VERSION 2.6)

PROJECT(cpack-test)

ADD_EXECUTABLE(Hello hello.c)
INSTALL(TARGETS Hello DESTINATION distance)

SET(CPACK_GENERATOR "TGZ")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Jagger Yu") #required

INCLUDE(CPack)

# To use this:
# make package
# sudo dpkg -i DistanceBetweenPoints-0.1.1-Linux.deb

# This will result in the file:
#/usr/distance/DistanceBetweenPoints

