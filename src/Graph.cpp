//
// Created by WorkSpace on 4/14/2018.
//

#include "../include/Graph.h"


bool Graph::is_edge(v_T source, v_T destination) const {
    auto it = find(edges[source].cbegin(), edges[source].cend(), Edge(source, destination));

    return it != edges[source].end();
}

Edge Graph::get_edge(v_T source, v_T destination) const {
    auto it = find(edges[source].cbegin(), edges[source].cend(), Edge(source, destination));

    if (it != edges[source].end()) {
        return *it;
    } else {
        Edge(source, destination, numeric_limits<w_T>::infinity());
    }
}

void Graph::insert(const Edge& edge) {
    edges[edge.get_source()].push_back(edge);
}

list<Edge>::iterator Graph::begin(v_T source) {
    return edges[source].begin();
}


list<Edge>::iterator Graph::end(v_T source) {
    return edges[source].end();
}


void Graph::remove_edge(v_T source, v_T destination) {
    auto it = find(edges[source].begin(), edges[source].end(), Edge(source, destination));

    if (it !=  edges[source].end()) {
        edges[source].remove(*it);
    }
}

void Graph::remove_edge(const Edge& edge) {
    auto it = find(edges[edge.get_source()].begin(),
                                              edges[edge.get_source()].end(),
                                              Edge(edge.get_source(), edge.get_dest()));

    if (it !=  edges[edge.get_source()].end()) {
        edges[edge.get_source()].remove(*it);
    }
}

void Graph::remove_edges(v_T source) {
    edges[source].clear();
}

void Graph::load_edges_from_file(std::istream &in) {

}

Graph *Graph::creatGraph(std::istream &in, const std::string &type) {
    return nullptr;
}