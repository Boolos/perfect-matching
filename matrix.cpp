#include "matrix.hpp"

csce::matrix::matrix() { }

csce::matrix::matrix(const csce::Graph& e, const csce::Graph& s) {
	this->mat.clear();
	int max = std::numeric_limits<int>::min();
	for(auto& it : e.getEdges()){
		max = std::max(max, (int)it.getU().getId());
		max = std::max(max, (int)it.getV().getId());
	}

    auto eLessS = e.difference(s);
    auto eVerticies = e.getVerticies();

    // Requires that bipartite graph starts at 0 and contains no gaps
    auto n = e.getVertexCount() / 2;
    for (int u = 0; u < n; u++) {
		std::vector<csce::polynomial> row;
        for (int v = n; v < n * 2; v++) {
            csce::Edge cur(u, v);
            //std::cout << cur.str() << ": ";
            if(s.contains(cur)){ //if {u, v} is in S
                csce::polynomial p;
                p.terms[{{'x', 1}, {'y', 1}}] = 1.0L;
                row.push_back(p);
                
                //std::cout << p.str() << " | ";

            } else if(eLessS.contains(cur)){ //if {u, v} is in E - S
                csce::polynomial p;
                p.terms[{{'x', 1}}] = 1.0L;
                row.push_back(p);

                //std::cout << p.str() << "  | ";

            } else { //if {u, v} is not in E
                auto p = csce::polynomial::value_of(0.0L);
                row.push_back(p);
                
                //std::cout << "0" << "  | ";
            }
        }
        mat.push_back(row);
        //std::cout << std::endl;
    }
}

csce::polynomial csce::matrix::determinant() {
	return this->determinant(this->mat);
}

csce::polynomial csce::matrix::determinant(const std::vector< std::vector< csce::polynomial > >& matrix) const {
	int n = static_cast<int>(matrix.size()); //size of matrix (n x n)
	
	if(n == 0){
		return csce::polynomial::value_of(0.0L);
	}if(n == 1){
		return matrix[0][0];
	} else if(n == 2){
		return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
	}
	
	csce::polynomial det;
	
	for(int x=0; x<n; x++){
		if(x % 2 == 0){
			det = det + matrix[0][x] * csce::matrix::determinant(csce::matrix::submatrix(matrix, x));
		} else{
			det = det - matrix[0][x] * csce::matrix::determinant(csce::matrix::submatrix(matrix, x));
		}
	}

	return det;
}

std::vector< std::vector<csce::polynomial> > csce::matrix::submatrix(const std::vector< std::vector<csce::polynomial> >& matrix, int col) const {
	std::vector< std::vector<csce::polynomial> > result;
	for(std::size_t r=1; r<matrix.size(); r++){
		std::vector<csce::polynomial> row;
		for(std::size_t c=0; c<matrix[r].size(); c++){
			if(c != col){
				row.push_back(matrix[r][c]);
			}
		}
		if(!row.empty()){
			result.push_back(row);
		}
	}
	return result;
}

void csce::matrix::replace_indeterminates(int edge_count) {
    // for each term, if x, replace with random number;
    //std::cout << "Replacing indeterminates..." << std::endl;
    for (int row = 0; row < this->mat.size(); row++) {
        for (int col = 0; col < this->mat[row].size(); col++) {
            auto p = this->mat[row][col].replace('x', this->get_random_number(edge_count));
            this->mat[row][col] = p;
            //std::cout << this->mat[row][col].str() << " | ";
        }
        //std::cout << std::endl;
    }

}

long double csce::matrix::get_random_number(int edge_count) const {
    long double min = 1.0L;
    long double max = std::pow((long double)edge_count, 4.0L);
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}
