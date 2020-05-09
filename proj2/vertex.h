// put header here
// vertex.cpp

#include "Location.h"
#include <string>
#include <vector>

#ifndef VERTEX_H_
#define VERTEX_H_

using namespace std;

struct Vertex {
    string name;
    Location location;
    // bool visited = false;
    vector <Vertex*> neighbors;
};

#endif
