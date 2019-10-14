#!/bin/sh
#disassemble a function

routine=$1
func=$2

if [ -z "$routine" ]; then
    exit
fi

start=$(nm -n $routine | grep "\w\s$func" | awk '{print "0x"$1;exit}')
end=$(nm -n $routine | grep -A1 "\w\s$func" | awk '{getline; print "0x"$1;exit}')

if [ -z "$func" ]; then
    objdump -d $routine
else
    echo "start-address: $start, end-address: $end"
    objdump -d $routine --start-address=$start --stop-address=$end
fi

