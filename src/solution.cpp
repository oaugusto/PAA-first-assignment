//
// Created by WorkSpace on 5/1/2018.
//

#include "../include/solution.h"


Graph construct_reverse_paths_graph(Graph& graph, v_T source) {
    v_T num_v = graph.get_num_v();

    //reverse graph
    Graph rGraph(num_v);

    //priority queue to represent a heap
    priority_queue<struct node, vector<struct node>, greater<struct node>> heap;

    //vector with all distances inicial all inf
    vector<w_T> dist(num_v, numeric_limits<w_T>::infinity());

    //put the source on the heap and set distance to 0
    heap.push(node(source, 0));
    dist[source] = 0;

    while (!heap.empty()) {
        // extract the min item
        v_T id = heap.top().id;
        heap.pop();

        //iterate over all adjacency vertex
        for (auto it = graph.begin(id); it != graph.end(id); it++) {
            v_T neighbor = (*it).get_dest();
            w_T edge_weigth = (*it).get_weigth();

            if (dist[neighbor] > dist[id] + edge_weigth) {
                dist[neighbor] =  dist[id] + edge_weigth;
                heap.push(node(neighbor, dist[neighbor]));

                rGraph.remove_edges(neighbor);
                rGraph.insert(Edge(neighbor, id));

            } else if (dist[neighbor] == dist [id] + edge_weigth) {
                rGraph.insert(Edge(neighbor, id));
            }
        }

    }


    return rGraph;

}


vector<v_T> list_all_edges(const Graph& graph) {

}


vector<v_T> list_all_essencial_edges(const Graph& graph) {

}