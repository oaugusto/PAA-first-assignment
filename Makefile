CC = g++
FLAGS = -std=c++11

main : include/* src/*
	$(CC) $(FLAGS) main.cpp src/Graph.cpp src/solution.cpp -o bin/PAA_first_assignment
