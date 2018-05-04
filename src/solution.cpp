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

Graph* clean_graph(Graph* graph) {
    v_T n_v = graph->get_num_v();
    auto gp = new Graph(n_v);

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

	    gp->insert(Edge((*it).get_source(), (*it).get_dest(), (*it).get_weigth(), (*it).get_label()));
        }
    }

    auto aux = graph;
    graph = gp;
    gp = aux;

    delete(gp);

    return graph;
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

void make_graph_undirected(Graph* graph) {
    v_T n_v = graph->get_num_v();

    for (v_T i = 0; i < n_v; i++) {
        for (auto it = graph->begin(i); it != graph->end(i); it++) {
            auto s = (*it).get_source();
            auto d = (*it).get_dest();

            //if the edge is not in graph
            if (!graph->is_edge(d, s)) {
                graph->insert(Edge(d, s, (*it).get_weigth(), (*it).get_label()));
            }
        }
    }
}


v_T visit_node(Graph* graph, v_T node, bool visited[], v_T pt[], v_T d_time[], v_T* time, vector<e_T>* vet) {
    d_time[node] = *time; // discovery time
    auto lower_time = *time; //the lower time so far
    visited[node] = true; //the node become visited

    *time = *time + 1;

    for (auto it = graph->begin(node); it != graph->end(node); it++) {
        auto dw = (*it).get_dest();
        if (!visited[dw]) {
            pt[dw] = node;

            auto aux = visit_node(graph, dw, visited, pt, d_time, time, vet);
            lower_time = (lower_time < aux) ? lower_time : aux;

            //not found any node lower time than current so is a bridge
            if (aux > d_time[node]) {
                vet->push_back((*it).get_label());
            }
        } else {
            //this means that a found a node that was visited but is not my parent
            //so a could have found a node lower than current
            if (dw != pt[node]) {
                lower_time = (lower_time < d_time[dw]) ? lower_time : d_time[dw];
            }
        }
    }

    return lower_time;
}


vector<e_T>* list_all_essential_edges(Graph* graph) {
    auto n_v = graph->get_num_v();

    auto vet = new vector<e_T>;
    auto visited = new bool[n_v];
    auto parent = new v_T[n_v];
    auto d_time = new v_T[n_v];

    for (v_T i = 0; i < n_v; i++) {
        visited[i] = false;
        parent[i] = -1;
    }

    v_T time = 0;

    visit_node(graph, n_v - 1, visited, parent, d_time, &time, vet);

    return vet;
}
