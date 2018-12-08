#!/bin/bash
# environment file for create third-part library
set -uv

# viriable for build
BASE_URL="http://repo.router7.com/libs"

###  function for download and extract to assign path ####
# $1 download URL
# $2 local path
function down_load
{
    local down_file=`echo "$1" | awk -F "/" '{print $NF}'`
    local file_ext=${down_file##*.}
    if [ $(curl -I -o /dev/null -s -w %{http_code} $1) != 200 ]; then
        echo "Query $1 not exist."
        return 1
    fi
    if ! curl -OL $1; then
        echo "Download $1 failed."
        return 2
    fi
    if [ ! -d $2 ]; then
        mkdir -p $2
    fi
    if [ $file_ext = "gz" -o $file_ext = "bz2" ]; then
        tar -vxf ${down_file} -C $2 --strip-components 1
        rm -rf ${down_file}
    fi
}

###  function for git clone specify branch to assign path ###
# $1 git repo URL
# $2 branch or tag
# $3 local path
function git_clone
{
    git clone --depth=1 $1 -b $2 $3
}
