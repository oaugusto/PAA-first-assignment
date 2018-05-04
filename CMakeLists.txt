cmake_minimum_required(VERSION 3.5)
project(PAA_first_assignment)

set(CMAKE_CXX_STANDARD 11)

add_executable(PAA_first_assignment main.cpp include/Graph.h src/Graph.cpp include/timer.h include/Types.h include/Edge.h include/solution.h src/solution.cpp)
