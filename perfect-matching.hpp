#ifndef UARK_CSCE_PERFECT_MATCHING
#define UARK_CSCE_PERFECT_MATCHING

#include <vector>
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

		vector<Edge> findPerectMatching(Graph graph) const;
		
	private:
        vector<Edge> findMatching() const;
        bool isPerfectMatching(const Graph& possibleMatching) const;
		bool isSparse() const;
        vector<Edge> getRedundantEdges();
        vector<Edge> getMatches() const;
        size_t getRank(const vector<Edge>& s) const;

        Graph getRandomSubset();
        int getRandomNumber() const;
	};
}

#endif /* UARK_CSCE_PERFECT_MATCHING */
