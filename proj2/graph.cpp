// Implementation of the graph class
// graph.cpp
// Author: Devan Venkataraman
// Date: 04/08/20

#include "graph.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Graph constructor - takes in two filenames
Graph::Graph(string file_one, string file_two) {
    // intialize num_vertices to 0, call respective read functs
    num_vertices = 0;
    readVdat(file_one);
    readAdat(file_two);
}

// Function readVdat
// Parameters: string file
// Returns: void
// Does: Reads in vdat file, ensures valid, calls populate function
void Graph::readVdat(string file) {
    ifstream ifs(file.c_str());
    if (ifs.fail()) {
        cerr << "Unable to open " << file << endl;
        exit(EXIT_FAILURE); // IS THIS CORRECT EXIT FAILURE?
    }

    populateVdat(ifs);
}

// Function readAdat
// Parameters: string file
// Returns: void
// Does: checks that it's a valid file. Does not and cannot process adat files
//       at this point
void Graph::readAdat(string file) {
    ifstream ifs(file.c_str());
    if (ifs.fail()) {
        cerr << "Unable to open " << file << endl;
        exit(EXIT_FAILURE); // IS THIS CORRECT EXIT FAILURE?
    }

    populateAdat(ifs);
}

// Function populateVdat
// Parameters: address of ifstream
// Returns: void
// Does: reads in vdat file data and stores them as vertices in the graph
void Graph::populateVdat(ifstream &ifs) {
    while (!ifs.eof()) {
        Vertex new_vertex;
        int lat_deg, lat_min, long_deg, long_min;
        ifs >> new_vertex.name >> lat_deg >> lat_min
            >> long_deg >> long_min;
        double latitude = calcCordinates(lat_deg, lat_min);
        double longitude = calcCordinates(long_deg, long_min);
        new_vertex.location.set_location(latitude, longitude);
        vertices.push_back(new_vertex);
        num_vertices++;
    }
    vertices.pop_back();
    num_vertices--;
}

// Function populateAdat
// Parameters: address of ifstream
// Returns: void
// Does: reads in adat file data and stores edges as pointers to vertices
//       in vector in vertices
void Graph::populateAdat(ifstream &ifs) {
    string line;
    while (getline(ifs, line)) {
        istringstream iss(line);
        string source_city, connect_city;
        Vertex *source_vert, *connect_vert;
        iss >> source_city >> connect_city;
        for (int i = 0; i < num_vertices; i++) {
            if (vertices[i].name == source_city) {
                source_vert = &vertices[i];
            }
            if (vertices[i].name == connect_city) {
                connect_vert = &vertices[i];
            }
        }
        source_vert->neighbors.push_back(connect_vert);
    }
}

// Function listVertices
// Parameters: none
// Returns: bool
// Does: prints out the name of each vertex in the graph
void Graph::listVertices() {
    for (int i = 0; i < num_vertices; i++) {
        cout << vertices[i].name << endl;
    }
}

// Function findDistance
// Parameters: two strings for city names
// Returns: double
// Does: calculates the distance between two provided cities
double Graph::findDistance(string city1, string city2) {
    // bool one_exists = false, two_exists = false;
    int index_one = findCityIndex(city1);
    int index_two = findCityIndex(city2);
    // if either doesn't exist
    if (index_one == -1 or index_two == -1) {
        return -1.00;
    }
    // return the distance
    return vertices[index_one].location.distance_to(vertices[index_two].location);
}

// Function calcCordinates
// Parameters: int degrees, int minutes
// Returns: double
// Does: Helper function that calculates latitude and longitude
//       correctly accounting for negative degree values
double Graph::calcCordinates(int deg, int min) {
    if (deg < 1) {
        return (double)deg - (double)min/60;
    }
    else {
        return (double)deg + (double)min/60;
    }
}

// Function findPaths
// Parameters: string city1, string city2, int num_paths
// Returns: void
// Does: Checks that the inputs are valid vertices then calls the search
//       function. Prints the paths found
bool Graph::findPaths(string city1, string city2, int num_paths) {
    int city_ind1 = findCityIndex(city1);
    int city_ind2 = findCityIndex(city2);
    // check validity
    if (city_ind1 == -1 or city_ind2 == -1) {
        cout << "ERROR: unknown city" << endl;
        return false;
    }
    // initial aux data structures
    vector<vector<int>> all_paths;
    vector<int> path;
    // call recursive search function
    searchForPaths(num_paths, city_ind1, city_ind2, all_paths, path);
    // print the paths found from the vector of paths
    if (all_paths.empty()) {
        cout << "ERROR: no-path-possible" << endl;
        return false;
    }
    for (int i = 0; i < num_paths; i++) {
        int num_existing_paths = all_paths.size();
        if (i < num_existing_paths) {
            cout << "PATH " << i + 1 << " :: 0 " << city1 << " ";
            vertices[city_ind1].location.print();
            int this_path_size = all_paths[i].size();
            for (int j = 1; j < this_path_size; j++) {
                cout << " ";
                string prev = vertices[all_paths[i].at(j-1)].name;
                string curr = vertices[all_paths[i].at(j)].name;
                int distance = findDistance(prev, curr);
                cout << distance << " " << curr << " ";
                vertices[all_paths[i].at(j)].location.print();
            }
            cout << endl;
        }
    }
    return true;
}

// Function searchForPaths
// Parameters: int degrees, int minutes
// Returns: double
// Does: Helper function that calculates latitude and longitude
//       correctly accounting for negative degree values
int Graph::searchForPaths(int paths_left, int city_ind1, int city_ind2,
        vector<vector<int>> &all_paths, vector<int> &this_path) {
    // push this city back into the current path
    this_path.push_back(city_ind1);
    // if we've found city
    if (city_ind1 == city_ind2) {
        all_paths.push_back(this_path);
        paths_left--;
        return paths_left;
    }
    // if there are paths left to find, recurse on its neighbors
    if (paths_left > 0) {
        int num_neighbors = vertices[city_ind1].neighbors.size();
        for (int i = 0; i < num_neighbors; i++) {
        int neighbor_ind = findCityIndex(vertices[city_ind1].neighbors[i]->name);
            if (!checkPath(this_path, neighbor_ind)) {
                paths_left = searchForPaths(paths_left, neighbor_ind,
                                 city_ind2, all_paths, this_path);
                // if we're here we didn't find a path - pop off last city
                this_path.pop_back();
            }
        }
    }
    return paths_left;
}

// Function findCityIndex
// Parameters: string city
// Returns: int
// Does: traverses through the vector of cities and locates current one
int Graph::findCityIndex(string city) {
    for (int i = 0; i < num_vertices; i++) {
        if (city == vertices[i].name) {
            return i;
        }
    }
    return -1;
}

// Function checkPath
// Parameters: vector of ints, int city index
// Returns: true
// Does: returns true if the provided city is already in the path, false
//       otherwise
bool Graph::checkPath(vector<int> path, int city_ind) {
    int path_size = path.size();
    for (int i = 0; i < path_size; i++) {
        if (city_ind == path[i]) {
            return true;
        }
    }
    return false;
}

// Function printEdges
// Parameters: none
// Returns: void
// Does: prints each vertex's neighbors
void Graph::printEdges() {
    for (int i = 0; i < num_vertices; i++) {
        cout << "Vertex " << vertices[i].name << "'s neighbors are: ";
        int neighbors = vertices[i].neighbors.size();
        for (int j = 0; j < neighbors; j++) {
            cout << vertices[i].neighbors[j]->name << " ";
        }
        cout << endl;
    }
}
