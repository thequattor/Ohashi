find_package(Qt6 COMPONENTS
        Core
        Network
        REQUIRED)

add_executable(ohashi main.cpp
        common.cpp
        tcp_client.cpp
        tcp_server.cpp)

target_link_libraries(ohashi
        Qt6::Core
        Qt6::Network)