#ifndef UARK_CSCE_MATRIX_HEADER
#define UARK_CSCE_MATRIX_HEADER

#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include "math.h"
#include "graph.hpp"
#include "edge.hpp"
#include "polynomial.hpp"
#include <iostream>

namespace csce {
	class matrix {
	public:
        matrix();
		matrix(const csce::Graph& e, const csce::Graph& s);
		csce::polynomial determinant();
		void replace_indeterminates(int edge_count);
		
	private:
		std::vector< std::vector<csce::polynomial> > mat;
		csce::polynomial determinant(const std::vector< std::vector<csce::polynomial> >& matrix) const;
		std::vector< std::vector<csce::polynomial> > submatrix(const std::vector< std::vector<csce::polynomial> >& matrix, int col) const;
        long double get_random_number(int edge_count) const;
	};
}

#endif /* UARK_CSCE_MATRIX_HEADER */
