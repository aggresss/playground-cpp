#!/bin/bash
# environment file for create third-part library 

# viriable for build
BASE_URL="http://pdi3zh561.bkt.clouddn.com/libs"

###  function for download and extract to assign path ####
# $1 download URL
# $2 local path 
function down_load
{
    DOWN_FILE=`echo "$1" | awk -F "/" '{print $NF}'`
    curl -OL $1
    mkdir -p $2
    tar -vxf ${DOWN_FILE} -C $2 --strip-components 1
    rm -rf ${DOWN_FILE}
}

###  function for git clone specify branch to assign path ###
# $1 git repo URL
# $2 branch or tag
# $3 local path
function git_clone
{
    git clone --depth=1 $1 -b $2 $3
}
