#include "matrix.hpp"

csce::matrix::matrix(csce::edge_set e, csce::edge_set s) {
	this->mat.clear();
	int max = std::numeric_limits<int>::min();
	for(auto& it : e.edges){
		max = std::max(max, it.u.id);
		max = std::max(max, it.v.id);
	}
	
	for(int u=0; u<max; u++){
		std::vector<csce::polynomial> row;
		for(int v=0; v<max; v++){
			csce::edge cur(u+1, v+1);
			if(s.contains(cur)){ //if {u, v} is in S
				csce::polynomial p;
				p.terms[{{'x', 1}, {'y', 1}}] = 1.0L;
				row.push_back(p);
			} else if(e.contains(cur)){ //if {u, v} is in E - S
				csce::polynomial p;
				p.terms[{{'x', 1}}] = 1.0L;
				row.push_back(p);
			} else { //if {u, v} is not in E
				row.push_back(csce::polynomial::value_of(0.0L));
			}
		}
		mat.push_back(row);
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