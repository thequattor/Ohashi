find_package(Qt6 COMPONENTS
        Core
        Network
        REQUIRED)

add_executable(tcp_broker main.cpp
        tcp_client.cpp
        common.cpp
        tcp_server.cpp)

target_link_libraries(tcp_broker
        Qt6::Core
        Qt6::Network)