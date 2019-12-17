#!/bin/sh
#disassemble a function

#CROSS=arm-hisiv300-linux-
NM=${CROSS}nm
OBJDUMP=${CROSS}objdump

routine=$1
func=$2

if [ -z "$routine" ]; then
    exit
fi

start=$(${NM} -n $routine | grep "\w\s$func\$" | awk '{print "0x"$1;exit}')
end=$(${NM} -n $routine | grep -A1 "\w\s$func\$" | awk '{getline; print "0x"$1;exit}')

if [ -z "$func" ]; then
    ${OBJDUMP} -d $routine
else
    echo "start-address: $start, end-address: $end"
    ${OBJDUMP} -d $routine --start-address=$start --stop-address=$end
fi

