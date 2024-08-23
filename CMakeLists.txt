cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CacheSimulator)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(cache_simulator
    main.cc
    cache.cc
)

# Include the current directory
target_include_directories(cache_simulator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

