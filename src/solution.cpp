//
// Created by WorkSpace on 5/1/2018.
//

#include "../include/solution.h"


Graph* construct_reverse_paths_graph(Graph* graph) {
    v_T num_v = graph->get_num_v();
    v_T source = 0; //source is always 0

    //reverse graph
    auto rGraph = new Graph(num_v);

    //priority queue to represent a heap
    priority_queue<struct node, vector<struct node>, greater<struct node>> heap;

    //vector with all distances inicial all inf
    vector<w_T> dist(num_v, numeric_limits<w_T>::max());

    //put the source on the heap and set distance to 0
    heap.push(node(source, 0));
    dist[source] = 0;

    while (!heap.empty()) {
        // extract the min item
        v_T id = heap.top().id;
        heap.pop();

        //iterate over all adjacency vertex
        for (auto it = graph->begin(id); it != graph->end(id); it++) {
            v_T neighbor = (*it).get_dest();
            w_T edge_weigth = (*it).get_weigth();

            if (dist[neighbor] > dist[id] + edge_weigth) {
                dist[neighbor] =  dist[id] + edge_weigth;
                heap.push(node(neighbor, dist[neighbor]));

                rGraph->remove_edges(neighbor);
                rGraph->insert(Edge(neighbor, id, 0, (*it).get_label()));

            } else if (dist[neighbor] == dist [id] + edge_weigth) {
                rGraph->insert(Edge(neighbor, id, 0, (*it).get_label()));
            }
        }

    }

    return rGraph;
}


vector<e_T>* list_all_edges(Graph* graph) {
    auto end = graph->get_num_v();
    auto edges = new vector<e_T>;

    for (int i = 0; i < end; i++) {
        for (auto it = graph->begin(i); it != graph->end(i); it++) {
            edges->push_back((*it).get_label());
        }
    }

    return edges;
}


vector<v_T>* list_all_essencial_edges(Graph* graph) {

}