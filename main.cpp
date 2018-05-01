#include <iostream>
#include "include/ListGraph.h"

using namespace std;

int main() {
   // ListGraph test(10);
    Edge e(1,2,10,1);
    Edge k(1,2,15,2);

    cout << e.to_string() << endl;
    cout << k.to_string() << endl;

    if(e == k) {
        cout << "equal" << endl;
    }

    return 0;
}