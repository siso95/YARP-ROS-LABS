# set up our program
add_executable(rpc-server)

# declare our source files
target_sources(rpc-server PRIVATE main.cpp)

# link with YARP libraries
target_link_libraries(rpc-server PRIVATE YARP::YARP_os
                                          YARP::YARP_init)
