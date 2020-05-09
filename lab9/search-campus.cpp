/*
 *
 * Filename: search-campus.cpp
 * Contains: Driver for lab 9, BFS for the Tufts campus
 * Part of: Lab assignment "Graph Traversal" for Comp 15
 *
 */


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Graph.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

const int NUM_BUILDINGS = 15;

void populate_graph_from_file(char *filename, Graph<string> &g);
void BFS(Graph<string> &g, string start, string end);

// Function: main
// Parameters: integer and string
// Returns: integer
// Does: main driver: reads filcname given by parameter
//       asks for start and end destinations and runs BFSon graph
int main(int argc, char *argv[])
{
    if (argc != 2) {
            cerr << "Error. This program needs one parameter."
                 << endl
                 << "Execute using:  ./search inputfile\n";
        return 1;
    }

    Graph<string> g(NUM_BUILDINGS);
    populate_graph_from_file(argv[1], g);

    string start, end;
    cout << "Where are you starting from?\n";
    cin >> start;
        while (not g.is_vertex(start)) {
        cout << "Never heard of it.  Enter again, please\n";
        cin >> start;
    }

    cout << "Where are you going to?\n";
    cin >> end;
    while (not g.is_vertex(end)) {
         cout << "No such place. Enter again, please\n";
         cin >> end;
    }

    cout << "\nHow to get there:\n";
    BFS(g, start, end);

    return 0;
}

// Function populate_graph_from_file
// Parameters: char *filename of adjacency matrix, Graph of strings (ref)
// Returns: void
// Does: creates one vertex for each building
//       and one edge for each non-zero entry in adjacency matrix
void populate_graph_from_file(char *filename, Graph<string> &g)
{
    ifstream infile;
    infile.open(filename);
    if (not infile.is_open()) {
        cerr << "Could not open " << filename << " for reading\n";
        exit(1);
    }

    string buildings[NUM_BUILDINGS];
    string v;

    for (int i = 0; i < NUM_BUILDINGS; i++) {
        infile >> v;
        buildings[i] = v;
        g.add_vertex(v);
    }

    for (int i = 0; i < NUM_BUILDINGS; i++) {
        infile >> v;
        for (int j = 0; j < NUM_BUILDINGS; j++) {
            int edge_weight;
            infile >> edge_weight;
            if (edge_weight > 0)
                g.add_edge(v, buildings[j], edge_weight);
        }
    }
    infile.close();
}


// Function populate_graph_from_file
// Parameters: graph, start node and end node
// Returns: void
// Does: searches for a shortest path from start to end
//       using BFS and reports the path found (if any)
//       you can assume that the path always exists
void BFS(Graph<string> &g, string start, string end)
{
    g.clear_marks();
    g.initialize_path();

    Queue<string> queue1;
    Queue<string> queue2;
    queue1.enqueue(start);
    bool found = false;
    string curr, neighbor;

    while (!queue1.is_empty() and !found) {
            queue1.dequeue(curr);
            if (curr == end) {
                    found = true;
            }
            else {
                    if (!g.is_marked(curr)) {
                            g.mark_vertex(curr);
                            g.get_to_vertices(curr, queue2);
                            while (!queue2.is_empty()) {
                                    queue2.dequeue(neighbor);
                                    if (!g.is_marked(neighbor)) {
                                            queue1.enqueue(neighbor);
                                            g.update_predecessor(curr, neighbor);
                                            if (neighbor == end) {
                                                    found = true;
                                                    break;
                                            }
                                    }
                            }
                    }
            }
    }

    if (!found) {
            cout << "No path found" << endl;
    }
    else {
            g.report_path(cout, start, end);
    }

}
