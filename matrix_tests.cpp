#include "catch.hpp"
#include "edge_set.hpp"
#include "vertex.hpp"
#include "edge.hpp"
#include "matrix.hpp"
#include "polynomial.hpp"

using namespace csce;

SCENARIO("Finding the determinant of a matrix") {
	
	GIVEN("The sets of edges e and s") {
		edge_set e;
		e.edges.insert(edge(vertex(1), vertex(2)));
		e.edges.insert(edge(vertex(3), vertex(4)));
		e.edges.insert(edge(vertex(2), vertex(3)));

		edge_set s;
		s.edges.insert(edge(vertex(3), vertex(4)));
		s.edges.insert(edge(vertex(2), vertex(3)));

		matrix matrix(e, s);

		WHEN("the determinant is calculated") {
			polynomial determinant = matrix.determinant();

			THEN("the resulting polynomial is correct") {
				REQUIRE(determinant.str() == "(x^4)(y^2)");
			}
		}
	}
}