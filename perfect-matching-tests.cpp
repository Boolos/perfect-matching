#include "catch.hpp"
#include "perfect-matching.hpp"
#include "graph.hpp"
#include <iostream>

using namespace csce;
using namespace std;

/*
SCENARIO("Getting rank") {
    GIVEN("A bipartite graph and subsets") {
        Graph e;
        e.add(0,2).add(0,3)
         .add(1,2).add(1,3);

        Graph s1; Graph s2; Graph s3;
        s1.add(0,3);
        s2.add(0,2).add(1,3);
        s3.add(0,2).add(1,2).add(0,3);

        PerfectMatching alg;

        WHEN("when getting a rank") {
            auto rank = alg.getRank(e, s1);

            THEN("the rank is 1") {
                REQUIRE(rank == 1);
            }
        }

        WHEN("when getting a rank") {
            auto rank = alg.getRank(e, s2);

            THEN("the rank is 2") {
                REQUIRE(rank == 2);
            }
        }
        
        WHEN("when getting a rank") {
            auto rank = alg.getRank(e, s3);

            THEN("the rank is 2") {
                REQUIRE(rank == 2);
            }
        }
    }
}

SCENARIO("Random number generator") {
    GIVEN("A graph with 6 edges") {
        Graph graph;
        graph.add(0,1).add(1,2).add(2,3).add(3,4).add(4,5).add(5,6);
        PerfectMatching alg;

        WHEN("requesting a random number") {
            auto num = alg.getRandomNumber(graph);

            THEN("the naumber is in the acceptable range") {
                REQUIRE(num >= 1);
                REQUIRE(num <= 5);
            }
        }
    }
}

SCENARIO("Random edges") {
    GIVEN("A graph with 6 edges") {
        Graph graph;
        graph.add(0,1).add(1,2).add(2,3).add(3,4).add(4,5).add(5,6);
        PerfectMatching alg;

        WHEN("when getting a subset") {
            auto subGraph = alg.getRandomSubset(graph);

            THEN("the naumber is in the acceptable range") {
                REQUIRE(subGraph.getEdgeCount() >= 1);
                REQUIRE(subGraph.getEdgeCount() <= 5);
            }
        }
    }
}

SCENARIO("Find obvious matches") {
    GIVEN("A graph with obvious matching edges and redundant edges") {
        Graph graph;
        graph.add(0,1).add(2,3).add(4,5).add(5,6).add(6,7).add(7,4);
        PerfectMatching alg;

        WHEN("when getting definite matches") {
            auto matches = alg.getObviousMatches(graph);

            THEN("there are the correct number of matching edges") {
                REQUIRE(matches.getEdgeCount() == 2);
            }

            THEN("0-1 is a match") {
                REQUIRE(matches.contains(0,1));
            }
            
            THEN("2-3 is a match") {
                REQUIRE(matches.contains(2,3));
            }
        }
    }
}

SCENARIO("Finding redundant edges") {
    GIVEN("A graph with obvious matching edges and redundant edges") {
        Graph e;
        e.add(0,2).add(0,3)
         .add(1,2).add(1,3);
        PerfectMatching alg;

        WHEN("when finding redundant edges") {
            auto redundant = alg.getRedundantEdges(e);

        }
    }
}

SCENARIO("Finding a matching (not necessarily a perfect matching)") {
    GIVEN("A sparse bipartite graph") {
        Graph graph;
        graph.add(0,2).add(1,2).add(3);
        PerfectMatching alg;

        WHEN("when finding redundant edges") {
            auto matching = alg.findMatching(graph);

            THEN("There are 3 matches") {
                REQUIRE(matching.getEdgeCount() == 2);
            }
        }
    }
    
    GIVEN("A non sparse bipartite graph") {
        Graph graph;
        graph.add(0,2).add(0,3).add(1,2).add(1,3);
        PerfectMatching alg;

        WHEN("when finding redundant edges") {
            auto matching = alg.findMatching(graph);

            THEN("There are 2 matches") {
                REQUIRE(matching.getEdgeCount() == 2);
            }
        }
    }
}

SCENARIO("Determining perfect matching") {
    GIVEN("A bipartite graph and a perfect matching") {
        Graph graph;
        Graph perfectMatching;
        graph.add(0,1).add(2,3).add(0,3);
        perfectMatching.add(0,1).add(2,3);
        PerfectMatching alg;

        WHEN("when tested") {
            bool isPerfectMatching = alg.isPerfectMatching(graph, perfectMatching);

            THEN("the matching is perfect") {
                REQUIRE(isPerfectMatching);
            }
        }
    }

    GIVEN("A bipartite graph and an imperfect matching") {
        Graph graph;
        Graph perfectMatching;
        graph.add(0,1).add(2,3).add(0,3);
        perfectMatching.add(0,1).add(2,3).add(0,3);
        PerfectMatching alg;

        WHEN("when tested") {
            bool isPerfectMatching = alg.isPerfectMatching(graph, perfectMatching);

            THEN("the matching is perfect") {
                REQUIRE(!isPerfectMatching);
            }
        }
    }
}
*/

SCENARIO("Find perfect matching") {
    GIVEN("A bipartite graph") {
        Graph bipartite;
        bipartite.add(0,4).add(0,5).add(0,6).add(0,7)
                 .add(1,4).add(1,5).add(1,6).add(1,7)
                 .add(2,4).add(2,5).add(2,6).add(2,7)
                 .add(3,4).add(3,5).add(3,6).add(3,7);
        /*
        Graph bipartite;
        bipartite.add(0,2).add(0,3)
                 .add(1,2).add(1,3);
        */

        PerfectMatching alg;
        
        WHEN("when finding the perfect matching") {
            auto perfectMatching = alg.findPerfectMatching(bipartite);

            THEN("it halts...") {
                //REQUIRE(perfectMatching.getEdgeCount() == 4);
            }
        }
    }
}
