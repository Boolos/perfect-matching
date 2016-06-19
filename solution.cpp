#include "solution.hpp"

csce::solution::solution(edge_set &edgeset, std::string f) {
	std::ifstream infile(f.c_str());

	if (infile.is_open())
	{
		infile >> numberOfVertices;
		infile >> numberOfEdges;
		infile >> numberOfSolutions;

		int a, b;
		for (int i = 0; i < numberOfEdges; i++)
		{
			infile >> a >> b;
			edgeset.edges.insert(csce::edge(csce::vertex(a), csce::vertex(b)));
			// somehow populate the vertices vector of g? FIXME
		}
		for (int i = 0; i < numberOfSolutions; i++) {
			infile >> numberOfSolutionsForPerfectMatching;
			std::vector<csce::edge> row;
			for (int j = 0; j < numberOfSolutionsForPerfectMatching; j++) {
				infile >> a >> b;
				
				vertex u(a);
				vertex v(b);
				edge e(u, v);
				row.push_back(e);
			}
			solutionSet.push_back(row);
		}
		infile.close();
	}
}

bool csce::solution::isSolution(edge_set e) {
	for (int i = 0; i < numberOfSolutions; i++) {
		for (int j = 0; j < numberOfVertices / 2; j++) {
			if (!e.contains(solutionSet[i][j]))
				return false;
		}
	}
	return true;
}
