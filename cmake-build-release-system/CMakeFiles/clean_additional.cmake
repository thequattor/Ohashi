# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/tcp_broker_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/tcp_broker_autogen.dir/ParseCache.txt"
  "tcp_broker_autogen"
  )
endif()
