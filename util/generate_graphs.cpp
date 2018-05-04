#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    long int size[] = {10, 50, 100, 150, 200, 250, 300};

    //completos
    for (int i = 0; i < 7; i++) {
        string file = "../data/Com/completo-";
	ostringstream convert;
	convert << size[i];
        file.append(convert.str());
        file.append(".txt");

        ofstream f(file.c_str());

        f << size[i] << " " << (size[i]*size[i] - size[i])<< endl;
        for (int j = 1; j <= size[i]; j++) {
            for (int k = 1; k <= size[i]; k++) {
                if (j != k) {
                    f << j << " " << k << " 1" << endl;
                }
            }
        }

        f.close();
    }
}
