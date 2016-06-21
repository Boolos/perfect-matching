#ifndef UARK_CSCE_GRAPH_HEADER
#define UARK_CSCE_GRAPH_HEADER

#include <vector>
#include "edge_set.hpp"
#include "matrix.hpp"
#include "vertex.hpp"

namespace csce {
	class graph {
	public:
		bool is_sparse() const;
		graph perfect_matching();
		edge_set edges() const;
		std::vector<vertex> vertices() const;
		
	private:
		edge_set __edges;
		std::vector<vertex> __vertices;
		matrix __matrix;
	};
}

#endif /* UARK_CSCE_GRAPH_HEADER */
