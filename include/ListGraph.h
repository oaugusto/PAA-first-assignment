//
// Created by WorkSpace on 4/14/2018.
//

#ifndef PAA_FIRST_ASSIGNMENT_LISTGRAPH_H
#define PAA_FIRST_ASSIGNMENT_LISTGRAPH_H

#include <list>
#include <vector>
#include <algorithm>
#include <limits>
#include "Graph.h"

class ListGraph: public Graph {
public:
    explicit ListGraph(v_T n);

    void insert(const Edge& edge) override ;

    bool  is_edge(v_T source, v_T destination) const override ;

    Edge get_edge(v_T source, v_T destination) const override ;

    void remove_edge(v_T source, v_T destination) override ;

    void remove_edge(const Edge& edge) override ;

    void remove_edges(v_T source) override ;

    iterator begin(v_T source) const override ;

    iterator end(v_T source) const override ;

    class iter_impl: public Graph::iter_impl {
    private:
        iter_impl(std::list<Edge>::const_iterator start) : current(start) {}
    public:
        Edge operator*() override {
            return *current;
        }

        Graph::iter_impl& operator++() override {
            ++current;
            return *this;
        }

        bool operator==(const Graph::iter_impl& other) const override {
            const iter_impl* ptr_other =
                    dynamic_cast<const iter_impl*>(&other);
        }

        Graph::iter_impl* clone() override {
            return new iter_impl(current);
        }

        ~iter_impl() override {}

    private:
        std::list<Edge>::const_iterator current;
        friend class ListGraph;
    };

private:
    std::vector<std::list<Edge>> edges;

};

#endif //PAA_FIRST_ASSIGNMENT_LISTGRAPH_H
