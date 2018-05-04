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

            //if dist is greater, update dist and update graph removing all edges
            if (dist[neighbor] > dist[id] + edge_weigth) {
                dist[neighbor] =  dist[id] + edge_weigth;
                heap.push(node(neighbor, dist[neighbor]));

                rGraph->remove_edges(neighbor);
                rGraph->insert(Edge(neighbor, id, 0, (*it).get_label()));

              //else just update graph append a new edge
            } else if (dist[neighbor] == dist [id] + edge_weigth) {
                rGraph->insert(Edge(neighbor, id, 0, (*it).get_label()));
            }
        }

    }

    return rGraph;
}


vector<e_T>* list_all_edges(Graph* graph) {
    v_T n_v = graph->get_num_v();
    auto edges = new vector<e_T>;

    queue<v_T> q; //
    vector<v_T> color(static_cast<unsigned long>(n_v), 0); //all vertex with white color

    color[n_v - 1] = 1; //color grey
    q.push(n_v - 1);

    while (!q.empty()) {
        v_T v = q.front();
        q.pop();

        for (auto it = graph->begin(v); it != graph->end(v); it++) {
            v_T dest = (*it).get_dest();

            if (color[dest] == 0) {
                color[dest] = 1; //color grey
                q.push(dest);
            }

            edges->push_back((*it).get_label());
        }
    }

    return edges;
}


vector<e_T>* list_all_essential_edges(Graph* graph) {
    v_T n_v = graph->get_num_v();
    auto edges = new vector<e_T>;

    auto q_level = new queue<v_T>;
    vector<v_T> color(static_cast<unsigned long>(n_v), 0); //all vertex with white color
    vector<v_T> nodes_level(static_cast<unsigned long>(n_v), -1); //level of each node

    color[n_v - 1] = 1; //color grey
    q_level->push(n_v - 1);

    bool finished = false;
    v_T level = 0;

    while (!finished) {
        auto q_backup = new queue<v_T>;
        vector<Edge> edges_level;

        while (!q_level->empty()) {
            v_T v = q_level->front();
            q_level->pop();

            //update level of the node
            nodes_level[v] = level;

            for (auto it = graph->begin(v); it != graph->end(v); it++) {
                if (nodes_level[(*it).get_dest()] != level) {
                    edges_level.push_back((*it));
                }

                //if the next node was not already visited
                v_T dest = (*it).get_dest();
                if (color[dest] == 0) {
                    color[dest] = 1; //color grey
                    q_backup->push(dest);
                }
            }
        }

        //no more nodes to explore
        if (q_backup->empty()) {
            finished = true;
        }

        //increment level
        level = level + 1;

        //if just one edge
        if (edges_level.size() == 1) {
            edges->push_back(edges_level.front().get_label());
        }

        auto aux = q_level;
        q_level = q_backup;
        q_backup = aux;
        delete(q_backup);
    }

    delete(q_level);

    return edges;
}