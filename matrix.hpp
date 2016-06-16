#ifndef UARK_CSCE_MATRIX_HEADER
#define UARK_CSCE_MATRIX_HEADER

#include <vector>
#include "edge_set.hpp"

namespace csce {
	class matrix {
	public:
		matrix(edge_set s, edge_set e);
		int determinant();
		
	private:
		std::vector< std::vector<int> > __data;
	};
}

#endif /* matrix_hpp */
