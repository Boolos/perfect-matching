#ifndef UARK_CSCE_EDGE_SET_HEADER
#define UARK_CSCE_EDGE_SET_HEADER

#include <vector>
#include "edge.hpp"

namespace csce {
	class edge_set {
	public:
		int rank();
		edge_set union_set(const edge_set& other) const;
		edge_set difference(const edge_set& other) const;
		edge_set(const std::vector<edge>& _edges);
		
	private:
		std::vector<edge> __edges;
	};
}

#endif /* UARK_CSCE_EDGE_SET_HEADER */
