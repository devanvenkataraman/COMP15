// main driver for findpath program. Ensures that the user has provided
// the correct arguments, then initializes the graph. fields commands from cin.
// main.cpp
// Author: Devan Venkataraman
// Date: 04/08/20

#include <iostream>
#include <string>
#include <iomanip>
#include "graph.h"

using namespace std;

int main (int argc, char *argv[]) {
    if (argc != 3) {
            cerr << "Usage:  findpath vertex_data edge_data" << endl;
        return 1;
    }
    Graph g(argv[1], argv[2]);
    string command;
    while (cin >> command) {
        if (command == "quit") {
            break;
        }
        else if (command == "list") {
            g.listVertices();
        }
        else if (command == "dist") {
            string city1, city2;
            cin >> city1 >> city2;
            cout << fixed << setprecision(2)
                 << g.findDistance(city1, city2) << endl;
        }
        cout << "-EOT-" << endl;
    }
    return 0;
}
