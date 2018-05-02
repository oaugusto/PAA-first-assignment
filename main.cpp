#include <iostream>
#include <fstream>
#include "include/Graph.h"
#include "include/solution.h"

using namespace std;

void sort(vector<e_T>*);

int main(int argc, char* argv[]) {

    // Check the number of parameters
    if (argc < 3) {
        // Tell the user how to run the program
        cerr << "Usage: " << argv[0] << " <in file> <out file>" << endl;
        return 1;
    }

    // input file
    ifstream in(argv[1]);

    if (!in.is_open()) {
        cerr << "error while opening file" << argv[1] << endl;
        return 1;
    }

    //output file
    ofstream out(argv[2]);

    if (!out.is_open()) {
        cerr << "error while opening file" << argv[2] << endl;
        return 1;
    }

    //create a graph from file
    Graph* stadium = Graph::creatGraph(in);
    //stadium->print_graph(); //just for debug

    //create a reverse graph of paths
    Graph* stadium_paths = construct_reverse_paths_graph(stadium, 0);
    //stadium_paths->print_graph(); //just for debug

    //find all edges of reverse graph
    auto all_edges = list_all_edges(stadium_paths);
    sort(all_edges);

    //find crucial edges
    //here

    in.close();
    out.close();

    return 0;
}

void sort(vector<e_T>*) {

}