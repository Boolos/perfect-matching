#ifndef UARK_CSCE_GRAPH_HEADER
#define UARK_CSCE_GRAPH_HEADER

#include <vector>
#include <unordered_set>
#include "math.h"
#include "edge_set.hpp"
#include "matrix.hpp"
#include "vertex.hpp"
#include "polynomial.hpp"
#include <iostream>

namespace csce {
	class graph {
	public:
        graph();
		graph(const edge_set& set);

        edge_set edges;
        std::unordered_set<vertex, vertex_hash> verticies;
        std::unordered_map<int, vertex> vs;

		edge_set find_perfect_matching() const;
        void remove_edges(const edge_set& edges_to_remove);
        void remove_verticies(const std::unordered_set<vertex, vertex_hash>& verticies_to_remove);
		
	private:
        edge_set find_matching() const;
        bool is_perfect_matching(const edge_set& possible_matching) const;
		bool is_sparse() const;
        bool has_edges() const;
        edge_set get_redundant() const;
        edge_set get_matches() const;
        int get_rank(const edge_set& s ) const;
	};
}

#endif /* UARK_CSCE_GRAPH_HEADER */
