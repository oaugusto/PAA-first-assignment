//
// Created by WorkSpace on 5/1/2018.
//

#include "../include/solution.h"


Graph construct_reverse_paths_graph(Graph& graph, v_T source) {
    v_T num_v = graph.get_num_v();

    //reverse graph
    Graph rGraph(num_v);

    priority_queue<struct node, vector<struct node>, greater<struct node>> p_queue;

    for(auto i = graph.begin(); i != graph.end(); i++) {
    }


}


vector<v_T> list_all_edges(const Graph& graph) {

}


vector<v_T> list_all_essencial_edges(const Graph& graph) {

}