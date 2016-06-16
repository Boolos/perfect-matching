#include <iostream>
#include <vector>

#include "edge_set.hpp"
#include "edge.hpp"
#include "matrix.hpp"
#include "graph.hpp"
#include "vertex.hpp"

int main(int argc, const char * argv[]) {
	std::vector<csce::vertex> vertices;
	for(int x=0; x<5; x++){
		csce::vertex vertex(x);
		vertices.push_back(vertex);
	}
	
	std::vector<csce::edge> edges;
	for(std::size_t x=0; x<vertices.size(); x++){
		for(std::size_t y=x+1; y<vertices.size(); y++){
			csce::edge edge(static_cast<int>(x), static_cast<int>(y));
			edges.push_back(edge);
		}
	}
	
	//TODO: need to create a graph object and then run the perfect_matching method on that object.
	
	return 0;
}
