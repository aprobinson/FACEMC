#!/bin/sh
rm -f CMakeCache.txt
/home/philip/software/cmake/bin/cmake  -DCMAKE_BUILD_TYPE:STRING="Debug" -DCMAKE_CXX_COMPILER:FILEPATH="/usr/bin/g++-7" -DCMAKE_C_COMPILER:FILEPATH="/usr/bin/gcc-7" -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL="TRUE" /home/philip/software/FRENSIE/src 
