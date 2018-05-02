//
// Created by WorkSpace on 5/1/2018.
//

#ifndef PAA_FIRST_ASSIGNMENT_SOLUTION_H
#define PAA_FIRST_ASSIGNMENT_SOLUTION_H

#include "Graph.h"
#include "Types.h"
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using std::priority_queue;
using std::greater;
using std::pair;

struct node {
    v_T id;
    w_T distance;

    node(v_T id, w_T distance) : id(id), distance(distance) {}

    bool operator>(const struct node n) const {
        return n.distance > distance;
    }
};

/**
 *
 * @param graph
 * @return
 */
Graph construct_reverse_paths(const Graph& graph);

/**
 *
 * @param graph
 * @return
 */
vector<v_T> list_all_edges(const Graph& graph);

/**
 *
 * @param graph
 * @return
 */
vector<v_T> list_all_essencial_edges(const Graph& graph);



#endif //PAA_FIRST_ASSIGNMENT_SOLUTION_H
