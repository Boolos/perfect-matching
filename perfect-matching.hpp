#ifndef UARK_CSCE_PERFECT_MATCHING
#define UARK_CSCE_PERFECT_MATCHING

#include <vector>
#include <random>
#include "math.h"
#include "matrix.hpp"
#include "polynomial.hpp"
#include "graph.hpp"
#include "edge.hpp"
#include <iostream>

namespace csce {
	class PerfectMatching {
	public:
        PerfectMatching();
        PerfectMatching(Graph& graph);

		Graph findPerfectMatching(const Graph& graph) const;
        Graph findMatching(Graph graph) const;
		bool isSparse(const Graph& graph) const;
        bool isPerfectMatching(const Graph& graph, const Graph& possibleMatching) const;
        Graph getRedundantEdges(const Graph& graph) const;
        Graph getObviousMatches(const Graph& graph) const;
        int getRank(const Graph& e, const Graph& s) const;
        Graph getRandomSubset(const Graph& graph) const;
        size_t getRandomNumber(const Graph& graph) const;


		
	private:
        Graph _graph;
	};
}

#endif /* UARK_CSCE_PERFECT_MATCHING */
