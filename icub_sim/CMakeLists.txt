# set up our program
add_executable(icub_sim)

# declare our source files
target_sources(icub_sim PRIVATE main.cpp)

# link with YARP libraries
target_link_libraries(icub_sim PRIVATE YARP::YARP_os
                                          YARP::YARP_init)
