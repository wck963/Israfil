#!/usr/bin/bash
LD_LIBRARY_PATH=$(pwd)
echo $LD_LIBRARY_PATH
LD_LIBRARY_PATH=$LD_LIBRARY_PATH ./$1 