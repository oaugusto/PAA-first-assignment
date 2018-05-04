#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "include/Graph.h"
#include "include/solution.h"

#define TESTMODE true

using namespace std;

int main(int argc, char* argv[]) {

    //*******************************************************************
    //count the time in each function
    fstream times_file;
    clock_t begin, end;

    if(TESTMODE) {
        string test = "data/time/";
        test.append("time.text");
        times_file.open(test.c_str(), std::fstream::in | std::fstream::out | fstream::trunc);
    }
    //*******************************************************************

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

    //*******************************************************************
    //first timer - Dijkstra algorithm
    begin = clock();
    //*******************************************************************

    //create a reverse graph of paths
    Graph* stadium_paths = construct_reverse_paths_graph(stadium);
    //stadium_paths->print_graph(); //just for debug

    //*******************************************************************
    //close timer
    end = clock();
    if (TESTMODE) {
        double elapsed_secs = double(end - begin);
        times_file << elapsed_secs
                   << " "
                   << elapsed_secs*1.0/CLOCKS_PER_SEC << endl;
        //append time
    }
    //*******************************************************************

    //remove edges not belong to path
    stadium_paths = clean_graph(stadium_paths);

    //*******************************************************************
    //second timer - BFS algorithm
    begin = clock();
    //*******************************************************************

    /*find all edges of reverse graph*/
    auto all_edges = list_all_edges(stadium_paths);

    //*******************************************************************
    //close timer
    end = clock();
    if (TESTMODE) {
        double elapsed_secs = double(end - begin);
        times_file << elapsed_secs
                   << " "
                   << elapsed_secs*1.0/CLOCKS_PER_SEC << endl;
        //append time
    }
    //*******************************************************************

    //write size and edges in output file
    sort(all_edges->begin(), all_edges->end());
    out << all_edges->size() << endl;
    if (!all_edges->empty()) {
        for (v_T i = 0; i < all_edges->size() - 1; i++) {
            out << (*all_edges)[i] << " ";
        }
        out << (*all_edges)[all_edges->size() - 1] << endl;
    }

    //make the graph undirected in order to use next function
    make_graph_undirected(stadium_paths);

    //*******************************************************************
    //third timer - BFS algorithm
    begin = clock();
    //*******************************************************************

    /*find crucial edges*/
    auto essential_edges = list_all_essential_edges(stadium_paths);

    //*******************************************************************
    //close timer
    end = clock();
    if (TESTMODE) {
        double elapsed_secs = double(end - begin);
        times_file << elapsed_secs
                   << " "
                   << elapsed_secs*1.0/CLOCKS_PER_SEC << endl;
        //append time
    }
    //*******************************************************************

    //write size and essential edges in output file
    sort(essential_edges->begin(), essential_edges->end());
    out << essential_edges->size() << endl;
    if (!essential_edges->empty()) {
        for (v_T i = 0; i < essential_edges->size() - 1; i++) {
            out << (*essential_edges)[i] << " ";
        }
        out << (*essential_edges)[essential_edges->size() - 1];
    }

    delete(stadium);
    delete(stadium_paths);
    delete(all_edges);
    delete(essential_edges);

    in.close();
    out.close();
    times_file.close();

    return 0;
}
