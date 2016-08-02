#include "catch.hpp"
#include "graph.hpp"

using namespace csce;
using namespace std;

SCENARIO("Mutating graphs") {
    GIVEN("An empty graph") {
        Graph graph;

        THEN("it has no edges") {
            REQUIRE(graph.getEdgeCount() == 0);
        }

        THEN("it has no verticies") {
            REQUIRE(graph.getVertexCount() == 0);
        }

        WHEN("adding a vertex") {
            graph.add(0);

            THEN("the vertex is in the graph") {
                REQUIRE(graph.contains(0) == true);
            }

            THEN("the graph has 1 vertex") {
                REQUIRE(graph.getVertexCount() == 1);
            }

            THEN("the graph has no edges") {
                REQUIRE(graph.getEdgeCount() == 0);
            }
        }

        WHEN("adding an edge") {
            graph.add(0, 1);

            THEN("the edge is in the graph") {
                REQUIRE(graph.contains(0, 1) == true);
            }

            THEN("the graph has 1 edge") {
                REQUIRE(graph.getEdgeCount() == 1);
            }

            THEN("the graph has 2 verticies") {
                REQUIRE(graph.getVertexCount() == 2);
            }
        }

        WHEN("removing an edge that does not exist") {
            graph.remove(8,9);

            THEN("the graph is still empty") {
                REQUIRE(graph.getEdgeCount() == 0);
                REQUIRE(graph.getVertexCount() == 0);
            }
        }

        WHEN("removing a vertex that does not exist") {
            graph.remove(9);

            THEN("the graph is still empty") {
                REQUIRE(graph.getEdgeCount() == 0);
                REQUIRE(graph.getVertexCount() == 0);
            }
        }
    }

    GIVEN("A graph with an edge") {
        Graph graph;
        graph.add(0,1);

        WHEN("adding the same edge") {
            graph.add(0,1);
            graph.add(1,0);

            THEN("the graph still only has one edge") {
                REQUIRE(graph.getEdgeCount() == 1);
            }

            THEN("the contains the undirected edge") {
                REQUIRE(graph.contains(0,1));
                REQUIRE(graph.contains(1,0));
            }
        }

        WHEN("adding a connecting edge") {
            graph.add(1,2);

            THEN("the graph has 2 edges") {
                REQUIRE(graph.getEdgeCount() == 2);
            }

            THEN("the graph has 3 verticies") {
                REQUIRE(graph.getVertexCount() == 3);
            }
        }

        WHEN("adding a previously entered vertex") {
            graph.add(0);

            THEN("the graph still only has 2 verticies") {
                REQUIRE(graph.getVertexCount() == 2);
            }
        }

        WHEN("removing an edge that does not exist") {
            graph.remove(8,9);

            THEN("the graph is the same") {
                REQUIRE(graph.getEdgeCount() == 1);
                REQUIRE(graph.getVertexCount() == 2);
            }
        }

        WHEN("removing a vertex that does not exist") {
            graph.remove(9);

            THEN("the graph is the same") {
                REQUIRE(graph.getEdgeCount() == 1);
                REQUIRE(graph.getVertexCount() == 2);
            }
        }

        WHEN("removing the edge") {
            graph.remove(0,1);

            THEN("the edge is no longer in the graph") {
                REQUIRE(graph.getEdgeCount() == 0);
            }
        }

        WHEN("removing a vertex") {
            graph.remove(0);

            THEN("the edge is no longer in the graph") {
                REQUIRE(graph.getEdgeCount() == 0);
            }

            THEN("the other vertex is still in the graph") {
                REQUIRE(graph.contains(1));
                REQUIRE(graph.getVertexCount() == 1);
            }
        }
    }
}

SCENARIO("Inspecting a graph") {
    GIVEN("Two exactly the same graphs") {
        Graph left;
        Graph right;

        left.add(0,1).add(1,2).add(2,3).add(3,4);
        right.add(0,1).add(1,2).add(2,3).add(3,4);

        WHEN("checked for equality") {
            bool isEqual = left == right;

            THEN("the graphs are equal") {
                REQUIRE(isEqual);
            }
        }

        WHEN("checked if right is a subgraph of left") {
            bool isSubGraph = left.isSubGraph(right);

            THEN("right is a subgraph of left") {
                REQUIRE(isSubGraph);
            }
        }
        
        WHEN("checked if left is a subgraph of right") {
            bool isSubGraph = right.isSubGraph(left);

            THEN("left is a subgraph of right") {
                REQUIRE(isSubGraph);
            }
        }
    }

    GIVEN("A graph and its propert sub graph") {
        Graph graph;
        Graph subGraph;

        graph.add(0,1).add(1,2).add(2,3).add(3,4);
        subGraph.add(0,1).add(1,2);

        WHEN("checked for equality") {
            bool isEqual = graph == subGraph;

            THEN("the graphs are not equal") {
                REQUIRE(!isEqual);
            }
        }

        WHEN("checked if the subgraph is in fact a subgraph") {
            bool isSubGraph = graph.isSubGraph(subGraph);

            THEN("it indeed is a subgraph") {
                REQUIRE(isSubGraph);
            }
        }
        
        WHEN("checked if the graph is a subgraph of the subgraph") {
            bool isSubGraph = subGraph.isSubGraph(graph);

            THEN("it is not a subgraph") {
                REQUIRE(!isSubGraph);
            }
        }
    }
    
    GIVEN("Two different graphs with the same number of edges and verticies") {
        Graph left;
        Graph right;

        left.add(0,1).add(1,2).add(2,3).add(3,4);
        right.add(9,8).add(8,7).add(7,6).add(6,5);

        WHEN("checked for equality") {
            bool isEqual = left == right;

            THEN("the graphs are not equal") {
                REQUIRE(!isEqual);
            }
        }

        WHEN("checked if right is a sub graph of left") {
            bool isSubGraph = left.isSubGraph(right);

            THEN("it is not") {
                REQUIRE(!isSubGraph);
            }
        }
        
        WHEN("checked if left is a sub graph of right") {
            bool isSubGraph = right.isSubGraph(left);

            THEN("it is not") {
                REQUIRE(!isSubGraph);
            }
        }
    }

    GIVEN("A graph with multiple edges incident to a single vertex") {
        Graph graph;
        graph.add(0,1).add(0,2).add(0,3).add(1,2).add(3,4);

        WHEN("querying for all edges incident to 0") {
            auto edges = graph.getEdges(0);

            THEN("there are 3 edges returned") {
                REQUIRE(edges.size() == 3);
            }
        }
    }
}