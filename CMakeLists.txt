cmake_minimum_required(VERSION 3.10)
project(PAA_first_assignment)

set(CMAKE_CXX_STANDARD 11)

add_executable(PAA_first_assignment main.cpp include/Graph.h src/Graph.cpp include/timer.h include/ListGraph.h include/MatrixGraph.h src/ListGraph.cpp src/MatrixGraph.cpp include/Types.h include/Edge.h)