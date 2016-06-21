#include "catch.hpp"
#include "edge_set.hpp"
#include "edge.hpp"

using namespace csce;

SCENARIO("Determining set membership") {

	GIVEN("A set of edges { 1-2, 2-3, 3-4 }") {
		edge_set edgeset;
		
		edgeset.edges.insert(edge(csce::vertex(1), vertex(2)));
		edgeset.edges.insert(edge(csce::vertex(3), vertex(4)));
		edgeset.edges.insert(edge(csce::vertex(2), vertex(3)));		

		WHEN("asked if edge 1-2 is a member of the set") {
			bool isMember = edgeset.contains(edge(vertex(1), vertex(2)));

			THEN("the edge should be in the set") {
				REQUIRE(isMember == true);
			}
		}

		WHEN("asked if edge 2-1 is a member of the set") {
			bool isMember = edgeset.contains(edge(vertex(2), vertex(1)));

			THEN("the edge should be in the set") {
				REQUIRE(isMember == true);
			}
		}

		WHEN("asked if edge 3-1 is a member of the set") {
			bool isMember = edgeset.contains(edge(vertex(3), vertex(1)));

			THEN("the edge should not be in the set") {
				REQUIRE(isMember == false);
			}
		}

		WHEN("asked if edge 3-2 is a member of the set") {
			bool isMember = edgeset.contains(edge(vertex(3), vertex(2)));

			THEN("the edge should be in the set") {
				REQUIRE(isMember == true);
			}
		}

		WHEN("asked if edge 4-3 is a member of the set") {
			bool isMember = edgeset.contains(edge(vertex(4), vertex(3)));

			THEN("the edge should be in the set") {
				REQUIRE(isMember == true);
			}
		}

		WHEN("asked if edge 3-4 is a member of the set") {
			bool isMember = edgeset.contains(edge(vertex(3), vertex(4)));

			THEN("the edge should be in the set") {
				REQUIRE(isMember == true);
			}
		}

		WHEN("asked if edge 4-1 is a member of the set") {
			bool isMember = edgeset.contains(edge(vertex(4), vertex(1)));

			THEN("the edge should not be in the set") {
				REQUIRE(isMember == false);
			}
		}
	}
}