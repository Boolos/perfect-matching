#ifndef UARK_CSCE_EDGE_HEADER
#define UARK_CSCE_EDGE_HEADER

#include "vertex.hpp"

namespace csce {
	class edge {
	public:
		vertex u;
		vertex v;
		edge(csce::vertex _u, csce::vertex _v);
		
	private:
		
	};
}

#endif /* UARK_CSCE_EDGE_HEADER */
