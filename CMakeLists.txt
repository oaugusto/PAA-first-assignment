cmake_minimum_required(VERSION 3.10)
project(PAA_first_assignment)

set(CMAKE_CXX_STANDARD 11)

add_executable(PAA_first_assignment main.cpp include/graph.h include/heap.h src/graph.cpp include/timer.h include/adjacencylist.h include/adjacencymatrix.h src/adjacencylist.cpp src/adjacencymatrix.cpp src/heap.cpp)