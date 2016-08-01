#include "catch.hpp"
#include "edge_set.hpp"
#include "edge.hpp"

using namespace csce;

/*
SCENARIO("Constructing an edge set") {
    edge_set set;

    GIVEN("An empty edge set and an edge") {

        WHEN("the edge is added to the set") {
            set.add(1, 2);

            THEN("the edge is a member of the set") {
                REQUIRE(set.contains(1, 2) == true);
                REQUIRE(set.size_edges() == 1);
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
*/


SCENARIO("Random subsets") {
    GIVEN("A set and a subset") {
        edge_set set;
        set.add(1,2).add(2,3).add(4,5);
        edge_set sub_set;
        sub_set.add(2,3);

        WHEN("checking for a sub set") {
            bool is_sub_set = set.is_sub_set(sub_set);

            THEN("it is a sub set") {
                REQUIRE(is_sub_set == true);
            }
        }
    }

    GIVEN("A set of edges") {
        edge_set edges;
        edges.add(1,4).add(1,6).add(2,4).add(2,5)
             .add(3,4).add(3,5).add(3,6);

        WHEN("a random subset is requested") {
            edge_set subset = edges.get_random_subset();

            THEN("the resulting set is a proper subset") {
                REQUIRE(edges.is_sub_set(subset) == true);
            }
        }
    }
} 

SCENARIO("Manipulating edges and verticies") {
    GIVEN("5 verticies {1,2,3,4,5}, and two edges {2-3, 4-5}") {
        edge_set set;
        set.add(1).add(2,3).add(4,5);

        WHEN("a duplicate vertex is added") {
            set.add(3);

            THEN("there are 5 verticies") {
                REQUIRE(set.size_verticies() == 5);
            }

            THEN("there are 2 edges") {
                REQUIRE(set.size_edges() == 2);
            }

            THEN("vetex 1 has degree of 0") {
                REQUIRE(set.degree(1) == 0);
            }

            THEN("vetex 2 has degree of 1") {
                REQUIRE(set.degree(2) == 1);
            }
            
            THEN("vetex 3 has degree of 1") {
                REQUIRE(set.degree(3) == 1);
            }
            
            THEN("vetex 4 has degree of 0") {
                REQUIRE(set.degree(4) == 1);
            }

            THEN("vetex 5 has degree of 0") {
                REQUIRE(set.degree(5) == 1);
            }
        }

        WHEN("a duplicate edge is added") {
            set.add(2,3);

            THEN("there are 5 verticies") {
                REQUIRE(set.size_verticies() == 5);
            }

            THEN("there are 2 edges") {
                REQUIRE(set.size_edges() == 2);
            }

            THEN("vetex 1 has degree of 0") {
                REQUIRE(set.degree(1) == 0);
            }

            THEN("vetex 2 has degree of 1") {
                REQUIRE(set.degree(2) == 1);
            }
            
            THEN("vetex 3 has degree of 1") {
                REQUIRE(set.degree(3) == 1);
            }
            
            THEN("vetex 4 has degree of 0") {
                REQUIRE(set.degree(4) == 1);
            }

            THEN("vetex 5 has degree of 0") {
                REQUIRE(set.degree(5) == 1);
            }
        }

        WHEN("a non existant vertex is removed") {
            set.remove(10);
            
            THEN("there are 5 verticies") {
                REQUIRE(set.size_verticies() == 5);
            }

            THEN("there are 2 edges") {
                REQUIRE(set.size_edges() == 2);
            }

            THEN("vetex 1 has degree of 0") {
                REQUIRE(set.degree(1) == 0);
            }

            THEN("vetex 2 has degree of 1") {
                REQUIRE(set.degree(2) == 1);
            }
            
            THEN("vetex 3 has degree of 1") {
                REQUIRE(set.degree(3) == 1);
            }
            
            THEN("vetex 4 has degree of 0") {
                REQUIRE(set.degree(4) == 1);
            }

            THEN("vetex 5 has degree of 0") {
                REQUIRE(set.degree(5) == 1);
            }
        }

        WHEN("a non existant edge is removed") {
            set.remove(9,10);

            THEN("there are 5 verticies") {
                REQUIRE(set.size_verticies() == 5);
            }

            THEN("there are 2 edges") {
                REQUIRE(set.size_edges() == 2);
            }

            THEN("vetex 1 has degree of 0") {
                REQUIRE(set.degree(1) == 0);
            }

            THEN("vetex 2 has degree of 1") {
                REQUIRE(set.degree(2) == 1);
            }
            
            THEN("vetex 3 has degree of 1") {
                REQUIRE(set.degree(3) == 1);
            }
            
            THEN("vetex 4 has degree of 0") {
                REQUIRE(set.degree(4) == 1);
            }

            THEN("vetex 5 has degree of 0") {
                REQUIRE(set.degree(5) == 1);
            }
        }

        WHEN("the verticies are added") {
            THEN("there are 5 verticies") {
                REQUIRE(set.size_verticies() == 5);
            }

            THEN("there are 2 edges") {
                REQUIRE(set.size_edges() == 2);
            }

            THEN("vetex 1 has degree of 0") {
                REQUIRE(set.degree(1) == 0);
            }

            THEN("vetex 2 has degree of 1") {
                REQUIRE(set.degree(2) == 1);
            }
            
            THEN("vetex 3 has degree of 1") {
                REQUIRE(set.degree(3) == 1);
            }
            
            THEN("vetex 4 has degree of 0") {
                REQUIRE(set.degree(4) == 1);
            }

            THEN("vetex 5 has degree of 0") {
                REQUIRE(set.degree(5) == 1);
            }
        }
        
        WHEN("vertex 1 is removed") {
            set.remove(1);

            THEN("there are 4 verticies") {
                REQUIRE(set.size_verticies() == 4);
            }
            
            THEN("vertex 1 is not in the set") {
                REQUIRE(set.contains(1) == false);
            }
            
            THEN("vertex 2 is in the set") {
                REQUIRE(set.contains(2) == true);
            }

            THEN("vertex 3 is in the set") {
                REQUIRE(set.contains(3) == true);
            }
            
            THEN("vertex 4 is in the set") {
                REQUIRE(set.contains(4) == true);
            }

            THEN("vertex 5 is in the set") {
                REQUIRE(set.contains(5) == true);
            }
        }
    }
    GIVEN("An edge 1 - 2 and an empty set") {
        edge_set edges;

        WHEN("the edge is added") {
            edges.add(1,2);

            THEN("there is one edge in the set") {
                REQUIRE(edges.size_edges() == 1);
            }

            THEN("this are 2 verticies") {
                REQUIRE(edges.size_verticies() == 2);
            }

            THEN("the set has 1-2") {
                REQUIRE(edges.contains(1,2) == true);
            }

            THEN("1 has one neighbor") {
                REQUIRE(edges.degree(1) == 1);
            }
            
            THEN("2 has one neighbor") {
                REQUIRE(edges.degree(2) == 1);
            }
        }
    }

    GIVEN("An edge set with 1-2 and 2-3") {
        edge_set edges;
        edges.add(1,2).add(2,3);

        WHEN("the edges are added") {
            THEN("there are two edges in the set") {
                REQUIRE(edges.size_edges() == 2);
            }

            THEN("this are 3 verticies") {
                REQUIRE(edges.size_verticies() == 3);
            }
            
            THEN("the set has 1-2") {
                REQUIRE(edges.contains(1,2) == true);
            }

            THEN("the set has 2-3") {
                REQUIRE(edges.contains(2,3) == true);
            }

            THEN("the set has 2-1") {
                REQUIRE(edges.contains(2,1) == true);
            }

            THEN("the set has 3-2") {
                REQUIRE(edges.contains(3,2) == true);
            }

            THEN("1 has one neighbor") {
                REQUIRE(edges.degree(1) == 1);
            }

            THEN("2 has one neighbor") {
                REQUIRE(edges.degree(2) == 2);
            }
            
            THEN("3 has one neighbor") {
                REQUIRE(edges.degree(3) == 1);
            }
        }

        WHEN("2-3 is removed") {
           edges.remove(2,3);

            THEN("there is only one edge in the set") {
                REQUIRE(edges.size_edges() == 1);
            }

            THEN("there are 3 verticies") {
                REQUIRE(edges.size_verticies() == 3);
            }
            
            THEN("the set has 1-2") {
                REQUIRE(edges.contains(1,2) == true);
            }

            THEN("the set does not have 2-3") {
                REQUIRE(edges.contains(2,3) == false);
            }

            THEN("1 has one neighbor") {
                REQUIRE(edges.degree(1) == 1);
            }

            THEN("2 has one neighbor") {
                REQUIRE(edges.degree(2) == 1);
            }
            
            THEN("3 has no neighbors") {
                REQUIRE(edges.degree(3) == 0);
            }
        } 
    }
}
