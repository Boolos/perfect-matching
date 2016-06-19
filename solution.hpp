#ifndef UARK_CSCE_SOLUTION_HEADER
#define UARK_CSCE_SOLUTION_HEADER

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "graph.hpp"

namespace csce {
	class solution {
	public:
		solution(edge_set &edgeset, std::string f); // reads the graph from file, returns edge_set object to be used in main
		bool isSolution(edge_set e); // checks if the passed in edge_set is in the solutionSet
	private:
		std::vector< std::vector<edge> > solutionSet; // collection of sets of perfect matchings
		// set of integers used in read
		int numberOfVertices;
		int numberOfEdges;
		int numberOfSolutions;
		int numberOfSolutionsForPerfectMatching;
	};
}


#endif /* UARK_CSCE_SOLUTION_HEADER */