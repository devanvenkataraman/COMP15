// Interface of graph class.
// graph.h
// Author: Devan Venkataraman
// Date: 04/08/20

#include <iostream>
#include <ostream>
#include <string>
#include "vertex.h"

#ifndef GRAPH_H_
#define GRAPH_H_

using namespace std;

class Graph
{
public:
    Graph(string file_one, string file_two);
    void listVertices();
    double findDistance(string city1, string city2);
    bool findPaths(string city1, string city2, int num_paths);
    void printEdges();

private:
    void readVdat(string file);
    void readAdat(string file);
    void populateVdat(ifstream &ifs);
    void populateAdat(ifstream &ifs);
    double calcCordinates(int deg, int min);
    int searchForPaths(int paths_left, int cityind1, int cityind2,
            vector<vector<int>> &all_paths, vector<int> &this_path);
    int findCityIndex(string city);
    bool checkPath(vector<int> path, int city_ind);

    int num_vertices;
    vector <Vertex> vertices;
};
#endif
