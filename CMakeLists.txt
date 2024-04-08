cmake_minimum_required(VERSION 3.28)
project(tcp_broker)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/Qt/6.7.0/gcc_64")

add_subdirectory(src)