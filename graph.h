// =============================
// Include Guard
#ifndef __GRAPH_H_INCLUDED__
#define __GRAPH_H_INCLUDED__

// =============================
// Forward Declared Dependencies
class Edge;

// =============================
// Included Dependenceies
#include "edge-set.h"

// =============================
// Class definition
class Graph
{
public:
    Graph* addEdge(const Edge&);
    Graph* findPerfectMatching();
    EdgeSet* getEdges();
};
#endif