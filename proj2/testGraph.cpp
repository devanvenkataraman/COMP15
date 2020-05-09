// test file for Graph class
// testGraph.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include "graph.h"

using namespace std;

void testList(Graph &graph);
void testDist(Graph &graph);

int main () {

    // normal setup
    Graph g("ta.vdat", "ta.adat");
    // test with invalid file name
    // Graph g("fake.file", "ta.adat");

    testList(g);
    testDist(g);

    return 0;
}

void testList(Graph &graph) {
    graph.listVertices();
}

void testDist(Graph &graph) {
    // test the first 10 cities dist with each of the second 10
    for (int i = 0; i < 10; i++) {
        for (int j = 10; j < 20; j++) {
            cout << fixed << setprecision(2)
            << graph.findDistance(graph.vertices.at(i).name, graph.vertices.at(j).name)
            << endl;
        }
    }
    // test dist w invalid city
    cout << fixed << setprecision(2)
    << graph.findDistance("fake city", "fake city 2") << endl;
}
