cmake_minimum_required(VERSION 3.28)
project(tcp_broker)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/Qt/6.7.0/gcc_64")

find_package(Qt6 COMPONENTS Core Network REQUIRED)

add_executable(tcp_broker main.cpp
        tcp_client.cpp
        common.cpp
        tcp_server.cpp)

target_link_libraries(tcp_broker Qt6::Core Qt6::Network)