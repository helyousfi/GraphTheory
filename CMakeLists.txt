cmake_minimum_required(VERSION 3.10)
project(GraphX LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include and source directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/algorithms)

# Library
add_library(GraphLibrary
    src/adjacency_matrix_graph.cpp
    src/algorithms/shortest_path_algorithms.cpp
)

# Example executable
add_executable(example examples/example_shortest_paths.cpp)

target_link_libraries(example PRIVATE GraphLibrary)
