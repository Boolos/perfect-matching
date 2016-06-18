#ifndef UARK_CSCE_EDGE_SET_HEADER
#define UARK_CSCE_EDGE_SET_HEADER

#include <vector>
#include <unordered_set>
#include "edge.hpp"

namespace csce {
	class edge_set {
	public:
		int rank();
		csce::edge_set union_set(const csce::edge_set& other) const;
		csce::edge_set difference(const csce::edge_set& other) const;
		std::unordered_set<csce::edge, csce::edge_hash> edges;
		bool contains(const csce::edge& edge) const;
		
	private:
		
	};
}

#endif /* UARK_CSCE_EDGE_SET_HEADER */
