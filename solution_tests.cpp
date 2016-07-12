#include "catch.hpp"
#include "edge_set.hpp"
#include "edge.hpp"
#include "vertex.hpp"
#include "solution.hpp"
#include <string>

using namespace csce;

/*
SCENARIO("Perfect matching validation") {

	GIVEN("A graph") {
		edge_set g;
		std::string f = "./problems/graph.txt";

		GIVEN("and a set of edges that are a perfect matching in said graph") {
			edge_set edgeset;
			edgeset.add(edge(vertex(0), vertex(6)));
			edgeset.add(edge(vertex(1), vertex(7)));
			edgeset.add(edge(vertex(2), vertex(5)));
			edgeset.add(edge(vertex(3), vertex(8)));
			edgeset.add(edge(vertex(4), vertex(9)));
			edgeset.add(edge(vertex(0), vertex(6)));
			edgeset.add(edge(vertex(1), vertex(7)));

			solution graphProblem(g, f);

			WHEN("checked") {
				bool isSolution = graphProblem.isSolution(edgeset);
				
				THEN("it is at least one of the perfect matches for the graph") {
					REQUIRE(isSolution == true);
				}
			}

		}

		GIVEN("and a set of edges that are not a perfect matching in said graph") {
			edge_set edgeset;
			edgeset.add(edge(vertex(1), vertex(2)));
			edgeset.add(edge(vertex(3), vertex(4)));
			edgeset.add(edge(vertex(2), vertex(3)));

			solution graphProblem(g, f);

			WHEN("checked") {
				bool isSolution = graphProblem.isSolution(edgeset);
				
				THEN("it is not a perfect matching for the graph") {
					REQUIRE(isSolution == false);
				}
			}
		}
	}
}
*/