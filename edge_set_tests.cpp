#include "catch.hpp"
#include "edge_set.hpp"
#include "edge.hpp"

using namespace csce;

SCENARIO("Constructing an edge set") {
    edge_set set;

    GIVEN("An empty edge set and an edge") {
        vertex u = vertex(1);
        vertex v = vertex(2);
        edge e = edge(u, v);

        WHEN("the edge is added to the set") {
            set.add(e);

            THEN("the edge is a member of the set") {
                REQUIRE(set.contains(e) == true);
                REQUIRE(set.edges.size() == 1);
            }
        }
    }

    GIVEN("An empty edge set and several edges") {
        edge e1 = edge(vertex(1), vertex(2));
        edge e2 = edge(vertex(2), vertex(3));
        edge e3 = edge(vertex(3), vertex(4));
        edge e4 = edge(vertex(1), vertex(4));

        WHEN("the edges are added to the set") {
            set.add(e1)
               .add(e2)
               .add(e3)
               .add(e4);

            THEN("the edges are members of the set") {
                REQUIRE(set.contains(e1) == true);
                REQUIRE(set.contains(e2) == true);
                REQUIRE(set.contains(e3) == true);
                REQUIRE(set.contains(e4) == true);
                REQUIRE(set.edges.size() == 4);
            }
        }
    }
}

SCENARIO("Set difference") {
    edge_set set1;
    edge_set set2;
    edge edge1 = edge(1,2);
    edge edge2 = edge(2,3);
    edge edge3 = edge(3,4);

    GIVEN("Two edge sets with edges in common") {
        set1.add(edge1).add(edge2);
        set2.add(edge2).add(edge3);

        WHEN("computing set1 less set2") {
            edge_set result = set1.difference(set2);

            THEN("the result is the correct set difference") {
                REQUIRE(result.contains(edge1) == true);
                REQUIRE(result.contains(edge2) == false);
                REQUIRE(result.edges.size() == 1);
            }
        }

        WHEN("computing set2 less set1") {
            edge_set result = set2.difference(set1);

            THEN("the result is the correct set difference") {
                REQUIRE(result.contains(edge3) == true);
                REQUIRE(result.contains(edge2) == false);
                REQUIRE(result.edges.size() == 1);
            }
        }
    }
}

SCENARIO("Set union") {
    edge_set set1;
    edge_set set2;
    edge edge1 = edge(1,2);
    edge edge2 = edge(2,3);
    edge edge3 = edge(3,4);

    GIVEN("Two edge sets with edges in common") {
        set1.add(edge1).add(edge2);
        set2.add(edge2).add(edge3);

        WHEN("computing set1 union set2") {
            edge_set result = set1.union_set(set2);

            THEN("the result is the union of both sets") {
                REQUIRE(result.contains(edge1) == true);
                REQUIRE(result.contains(edge2) == true);
                REQUIRE(result.contains(edge3) == true);
                REQUIRE(result.edges.size() == 3);
            }
        }
    }
}

SCENARIO("Determining set membership") {

	GIVEN("A set of edges { 1-2, 2-3, 3-4 }") {
		edge_set set;
		
		set.add(edge(vertex(1), vertex(2)));
		set.add(edge(vertex(3), vertex(4)));
		set.add(edge(vertex(2), vertex(3)));		

		WHEN("asked if edge 1-2 is a member of the set") {
			bool isMember = set.contains(edge(vertex(1), vertex(2)));

			THEN("the edge should be in the set") {
				REQUIRE(isMember == true);
			}
		}

		WHEN("asked if edge 2-1 is a member of the set") {
			bool isMember = set.contains(edge(vertex(2), vertex(1)));

			THEN("the edge should be in the set") {
				REQUIRE(isMember == true);
			}
		}

		WHEN("asked if edge 3-1 is a member of the set") {
			bool isMember = set.contains(edge(vertex(3), vertex(1)));

			THEN("the edge should not be in the set") {
				REQUIRE(isMember == false);
			}
		}

		WHEN("asked if edge 3-2 is a member of the set") {
			bool isMember = set.contains(edge(vertex(3), vertex(2)));

			THEN("the edge should be in the set") {
				REQUIRE(isMember == true);
			}
		}

		WHEN("asked if edge 4-3 is a member of the set") {
			bool isMember = set.contains(edge(vertex(4), vertex(3)));

			THEN("the edge should be in the set") {
				REQUIRE(isMember == true);
			}
		}

		WHEN("asked if edge 3-4 is a member of the set") {
			bool isMember = set.contains(edge(vertex(3), vertex(4)));

			THEN("the edge should be in the set") {
				REQUIRE(isMember == true);
			}
		}

		WHEN("asked if edge 4-1 is a member of the set") {
			bool isMember = set.contains(edge(vertex(4), vertex(1)));

			THEN("the edge should not be in the set") {
				REQUIRE(isMember == false);
			}
		}
	}
}

SCENARIO("Random subsets") {
    GIVEN("A set of edges") {
        edge ad = edge(vertex(1), vertex(4));
        edge af = edge(vertex(1), vertex(6));
        edge bd = edge(vertex(2), vertex(4));
        edge be = edge(vertex(2), vertex(5));
        edge cd = edge(vertex(3), vertex(4));
        edge ce = edge(vertex(3), vertex(5));
        edge cf = edge(vertex(3), vertex(6));

        edge_set set;
        set.add(ad)
           .add(af)
           .add(bd)
           .add(be)
           .add(cd)
           .add(ce)
           .add(cf);

        WHEN("a random subset is requested") {
            edge_set subset = set.get_random_subset();

            THEN("the resulting set is a proper subset") {
                bool isSubset = true;
                for_each(subset.edges.begin(), subset.edges.end(), [&] (const edge& e) {
                    isSubset = isSubset && set.contains(e);
                });

                REQUIRE(isSubset == true);
                REQUIRE(set.edges.size() != subset.edges.size());
                REQUIRE(subset.edges.size() != 0);
            }
        }
    }
} 