#!/bin/bash

env HEAPCHECK=normal HEAP_PROFILE_ALLOCATION_INTERVAL=1048576 HEAPPROFILE="/tmp/test.log" ./heap_profiler_test.out

pprof --text ./heap_profiler_test.out /tmp/*.heap

rm -rf /tmp/*.heap

