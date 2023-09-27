# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/HelloWorldQT_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/HelloWorldQT_autogen.dir/ParseCache.txt"
  "HelloWorldQT_autogen"
  )
endif()
