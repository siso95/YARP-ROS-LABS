# set up our program
add_executable(rpc-client)

# declare our source files
target_sources(rpc-client PRIVATE main.cpp)

# link with YARP libraries
target_link_libraries(rpc-client PRIVATE YARP::YARP_os
                                          YARP::YARP_init)
