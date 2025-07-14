# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appSoduko_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appSoduko_autogen.dir/ParseCache.txt"
  "appSoduko_autogen"
  )
endif()
