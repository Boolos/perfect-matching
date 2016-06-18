#include <iostream>
#include <vector>

#include "edge_set.hpp"
#include "edge.hpp"
#include "matrix.hpp"
#include "graph.hpp"
#include "vertex.hpp"
#include "polynomial.hpp"

void test_polynomial(){
	csce::polynomial pa;
	std::unordered_map<char, int> pa_terms = {{'x', 3}, {'y', 3}};
	pa.terms[pa_terms] = 3.0L;
	
	pa_terms = {{'y', 3}};
	pa.terms[pa_terms] = 5.0L;
	
	std::cout << "a = " << pa.str() << std::endl;
	
	csce::polynomial pb;
	
	std::unordered_map<char, int> pb_terms = {{'x', 2}, {'y', 3}};
	pb.terms[pb_terms] = 4.0L;
	
	std::cout << "b = " << pb.str() << std::endl;
	
	
	csce::polynomial pc = pa + pb;
	
	std::cout << "--- (add)" << std::endl;
	std::cout << "c = " << pc.str() << std::endl;
	
	
	csce::polynomial pd = pa - pb;
	
	std::cout << "--- (subtract)" << std::endl;
	std::cout << "c = " << pd.str() << std::endl;
	
	
	csce::polynomial pe = pa * pb;
	
	std::cout << "--- (multiply)" << std::endl;
	std::cout << "c = " << pe.str() << std::endl;
}

void test_edge_set(){
	csce::edge_set edgeset;
	edgeset.edges.insert(csce::edge(csce::vertex(1), csce::vertex(2)));
	edgeset.edges.insert(csce::edge(csce::vertex(3), csce::vertex(4)));
	edgeset.edges.insert(csce::edge(csce::vertex(2), csce::vertex(3)));
	
	std::cout << "edgeset.contains(2, 1) is " << (edgeset.contains(csce::edge(csce::vertex(2), csce::vertex(1))) ? "correct" : "incorrect") << std::endl;
	std::cout << "edgeset.contains(3, 1) is " << (!edgeset.contains(csce::edge(csce::vertex(3), csce::vertex(1))) ? "correct" : "incorrect") << std::endl;
	std::cout << "edgeset.contains(3, 2) is " << (edgeset.contains(csce::edge(csce::vertex(3), csce::vertex(2))) ? "correct" : "incorrect") << std::endl;
	std::cout << "edgeset.contains(1, 2) is " << (edgeset.contains(csce::edge(csce::vertex(1), csce::vertex(2))) ? "correct" : "incorrect") << std::endl;
	std::cout << "edgeset.contains(4, 3) is " << (edgeset.contains(csce::edge(csce::vertex(4), csce::vertex(3))) ? "correct" : "incorrect") << std::endl;
	std::cout << "edgeset.contains(3, 4) is " << (edgeset.contains(csce::edge(csce::vertex(3), csce::vertex(4))) ? "correct" : "incorrect") << std::endl;
	std::cout << "edgeset.contains(4, 1) is " << (!edgeset.contains(csce::edge(csce::vertex(4), csce::vertex(1))) ? "correct" : "incorrect") << std::endl;
}

void test_matrix(){
	csce::edge_set e;
	e.edges.insert(csce::edge(csce::vertex(1), csce::vertex(2)));
	e.edges.insert(csce::edge(csce::vertex(3), csce::vertex(4)));
	e.edges.insert(csce::edge(csce::vertex(2), csce::vertex(3)));
	
	csce::edge_set s;
	s.edges.insert(csce::edge(csce::vertex(3), csce::vertex(4)));
	s.edges.insert(csce::edge(csce::vertex(2), csce::vertex(3)));
	
	csce::matrix matrix(e, s);
	csce::polynomial determinant = matrix.determinant();
	std::cout << determinant.str() << std::endl;
	
}

int main(int argc, const char * argv[]) {
	
	//std::unordered_map< std::unordered_map<char, int>, long double > terms;   //[ {x^5y^3, 3}, {x^2, -2} ]   =   3x^5y^3 - 2x^2
	
	
	/* Testing the polynomial class */
	std::cout << std::endl;
	std::cout << "Testing polynomial" << std::endl;
	test_polynomial();
	std::cout << "Done testing polynomial" << std::endl;
	std::cout << std::endl;
	/* End of polynomial test */
	
	/* Testing the edge_set class */
	std::cout << std::endl;
	std::cout << "Testing edge_set" << std::endl;
	test_edge_set();
	std::cout << "Done testing edge_set" << std::endl;
	std::cout << std::endl;
	/* End of edge_set test */
	
	/* Testing the edge_set class */
	std::cout << std::endl;
	std::cout << "Testing matrix" << std::endl;
	test_matrix();
	std::cout << "Done testing matrix" << std::endl;
	std::cout << std::endl;
	/* End of edge_set test */
	
	
	/*
	std::vector<csce::vertex> vertices;
	for(int x=0; x<5; x++){
		csce::vertex vertex(x);
		vertices.push_back(vertex);
	}
	
	//edges for a complete, undirected graph, with 5 vertices (based on the size of the vertices vector)
	std::vector<csce::edge> edges;
	for(std::size_t x=0; x<vertices.size(); x++){
		for(std::size_t y=x+1; y<vertices.size(); y++){
			csce::edge edge(static_cast<int>(x), static_cast<int>(y));
			edges.push_back(edge);
		}
	}
	*/
	
	//TODO: need to create a graph object and then run the perfect_matching method on that object.
	
	return 0;
}
