#include <iostream>
#include "include/Graph.h"
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main() {

    Graph graph(2);
    Edge test(1,1);
    Edge test2(1,2);

    graph.insert(test);
    graph.insert(test2);

    if (graph.is_edge(1,2)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }


    return 0;
}