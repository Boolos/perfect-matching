#include "edge_set.hpp"

bool csce::edge_set::contains(const csce::edge& edge) const {
	return edges.find(edge) != edges.end();
}

