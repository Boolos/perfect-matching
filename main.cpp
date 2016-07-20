#include <iostream>
#include <vector>
#include "vertex.hpp"
#include "edge.hpp"
#include "edge_set.hpp"
#include "graph.hpp"

using namespace csce;
using namespace std;

int main(int argc, const char * argv[]) {
	/*
    vertex a(1);
    vertex b(2);
    vertex c(3);
    vertex d(4);

    a.add_neighbor(c);
    c.add_neighbor(a);

    b.add_neighbor(d);
    d.add_neighbor(b);

    a.add_neighbor(d);
    d.add_neighbor(a);
    
    b.add_neighbor(c);
    c.add_neighbor(b);
    
    edge ac = edge(a, c);
    edge bd = edge(b, d);
    edge ad = edge(a, d);
    edge bc = edge(b, c);

    edge_set edges;
    edges.add(ac).add(bd).add(ad).add(bc);

    graph non_sparse_graph = graph(edges);

    auto perfect_matching = non_sparse_graph.find_perfect_matching();

	std::vector<csce::vertex> vertices;
	for(int x=0; x<5; x++){
	csce::vertex vertex(x);
	vertices.push_back(vertex);
	}

	//edges for a complete, undirected graph, with 5 vertices (based on the size of the vertices vector)
	std::vector<csce::edge> edges;
	for(std::size_t x=0; x<vertices.size(); x++){
	for(std::size_t y=x+1; y<vertices.size(); y++){
	csce::edge edge(static_cast<int>(x), static_cast<int>(y));
	edges.push_back(edge);
	}
	}
	*/

	//TODO: need to create a graph object and then run the perfect_matching method on that object.

	return 0;
}
