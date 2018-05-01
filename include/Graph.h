//
// Created by WorkSpace on 4/14/2018.
//

#ifndef PAA_FIRST_ASSIGNMENT_GRAPH_H
#define PAA_FIRST_ASSIGNMENT_GRAPH_H

#include <iosfwd>
#include "Types.h"
#include "Edge.h"

class Graph {
public:

    class iterator;

    //constructor
    explicit Graph(v_T n) : num_v(n) {}

    //destructor
    virtual ~Graph() {}

    v_T get_num_v() { return num_v; }

    virtual void insert(const Edge& edge) = 0;

    virtual bool  is_edge(v_T source, v_T destination) const = 0;

    virtual Edge get_edge(v_T source, v_T destination) const = 0;

    virtual void remove_edge(v_T source, v_T destination) = 0;

    virtual  void remove_edge(const Edge& edge) = 0;

    virtual  void remove_edges(v_T source) = 0;

    virtual iterator begin(v_T source) const = 0;

    virtual iterator end(v_T source) const = 0;

    void load_edges_from_file(std::istream& in);

    static Graph* creatGraph(std::istream& in, const std::string& type);

    class iter_impl {
    public:
        virtual Edge operator*() = 0;
        virtual iter_impl& operator++() = 0;
        virtual bool operator==(const iter_impl&) const = 0;
        virtual iter_impl* clone() = 0;
        virtual  ~iter_impl() {}
    };

    class iterator {
    public:

        //return the current edge
        Edge operator*() {
            return ptr_to_impl->operator*();
        }

        //go to the next edge
        iterator& operator++() {
            ++(*ptr_to_impl);
            return *this;
        }

        iterator& operator++(int) {
            iterator tmp(*this);
            ++(*ptr_to_impl);
            return tmp;
        }

        //return true if those two edges are equal
        bool operator==(const iterator& other) const {
            return *ptr_to_impl == *other.ptr_to_impl;
        }

        bool operator!=(const iterator& other) const {
            return !((*this) == other);
        }

        ~iterator() {
            delete ptr_to_impl;
        }

        iterator(const iterator& other) :
            ptr_to_impl(other.ptr_to_impl->clone()) {}

        iterator(iter_impl* p_impl) : ptr_to_impl(p_impl) {}

    private:
        iter_impl* ptr_to_impl;
    }; //end iterator

protected:
    //the number of nodes of the graph
    v_T num_v;
};


#endif //PAA_FIRST_ASSIGNMENT_GRAPH_H