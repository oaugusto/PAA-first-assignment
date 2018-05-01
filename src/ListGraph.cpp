//
// Created by WorkSpace on 4/14/2018.
//

#include "../include/ListGraph.h"


ListGraph::ListGraph(v_T n) : Graph(n) {
    edges.resize(n);
}


bool ListGraph::is_edge(v_T source, v_T destination) const {
    /*
    std::list<Edge>::const_iterator it = find(edges[source].begin(),
                                              edges[source].end(),
                                              Edge(source, destination));

    return it != edges[source].end();
     */
}

Edge ListGraph::get_edge(v_T source, v_T destination) const {
    /*
    std::list<Edge>::const_iterator it = find(edges[source].begin(),
                                              edges[source].end(),
                                              Edge(source, destination));

    if (it != edges[source].end()) {
        return *it;
    } else {
        NULL;
    }
     */
}

void ListGraph::insert(const Edge& edge) {
    edges[edge.get_source()].push_back(edge);
}

Graph::iterator ListGraph::begin(v_T source) const {
    return Graph::iterator(new iter_impl(edges[source].begin()));
}

Graph::iterator ListGraph::end(v_T source) const {
    return Graph::iterator(new iter_impl(edges[source].end()));
}

void ListGraph::remove_edge(v_T source, v_T destination) {
    std::list<Edge>::const_iterator it = find(edges[source].begin(),
                                              edges[source].end(),
                                              Edge(source, destination));

    if (it !=  edges[source].end()) {
        edges[source].remove(*it);
    }
}

void ListGraph::remove_edge(const Edge& edge) {
    std::list<Edge>::const_iterator it = find(edges[edge.get_source()].begin(),
                                              edges[edge.get_source()].end(),
                                              Edge(edge.get_source(), edge.get_dest()));

    if (it !=  edges[edge.get_source()].end()) {
        edges[edge.get_source()].remove(*it);
    }
}

void ListGraph::remove_edges(v_T source) {
    edges[source].clear();
}
