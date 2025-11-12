cmake_minimum_required(VERSION 3.10)
project(GraphX LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include and source directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/algorithms)

add_library(GraphLibrary INTERFACE)

# Tell CMake where the headers are
target_include_directories(GraphLibrary INTERFACE ${CMAKE_SOURCE_DIR}/include)

# Example executable
add_executable(example examples/example_basic.cpp)

# Link the interface library
target_link_libraries(example PRIVATE GraphLibrary)
