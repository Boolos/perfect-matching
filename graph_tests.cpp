#include "catch.hpp"
#include "graph.hpp"
#include "edge_set.hpp"

using namespace csce;
using namespace std;

SCENARIO("Constructing a graph") {
    GIVEN("A set of edges") {
        vertex a = vertex(1);
        vertex b = vertex(2);
        vertex c = vertex(3);
        vertex d = vertex(4);
        vertex e = vertex(5);
        vertex f = vertex(6);

        edge ad = edge(a, d);
        edge af = edge(a, f);
        edge bd = edge(b, d);
        edge be = edge(b, e);
        edge cd = edge(c, d);
        edge ce = edge(c, e);
        edge cf = edge(c, f);

        edge_set set;
        set.add(ad)
           .add(af)
           .add(bd)
           .add(be)
           .add(cd)
           .add(ce)
           .add(cf);
        
        WHEN("the graph is constructed with the edges") {
            graph g = graph(set);

            THEN("all edges and vertices are in the graph") {
                REQUIRE(g.edges.edges.size() == 7);
                REQUIRE(g.verticies.size() == 6);
                REQUIRE(g.verticies.find(a)->degree == 2);
            }
        }
    } 
}

SCENARIO("Removing bits of a graph") {
    GIVEN("A non empty graph") {
        vertex a = vertex(1);
        vertex b = vertex(2);
        vertex c = vertex(3);
        vertex d = vertex(4);
        vertex e = vertex(5);
        vertex f = vertex(6);

        edge ad = edge(a, d);
        edge af = edge(a, f);
        edge bd = edge(b, d);
        edge be = edge(b, e);
        edge cd = edge(c, d);
        edge ce = edge(c, e);
        edge cf = edge(c, f);

        edge_set initial_edges;
        initial_edges
            .add(ad)
            .add(af)
            .add(bd)
            .add(be)
            .add(cd)
            .add(ce)
            .add(cf);
                     
        edge_set edges_to_remove;
        edges_to_remove
            .add(ad)
            .add(bd)
            .add(cf);

        unordered_set<vertex, vertex_hash> verticies_to_remove;
        verticies_to_remove.insert(vertex(1));
        verticies_to_remove.insert(vertex(6));
           
        graph g = graph(initial_edges);
        
        WHEN("edges are removed from the graph") {
            g.remove_edges(edges_to_remove);

            THEN("the edges are removed (but not the verticies)") {
                REQUIRE(g.edges.edges.size() == 4);
                REQUIRE(g.verticies.size() == 6);
            }
        }

        WHEN("verticies are removed from the graph") {
            g.remove_verticies(verticies_to_remove);

            THEN("the appropriate edges are verticies are removed") {
                REQUIRE(g.edges.edges.size() == 4);
                REQUIRE(g.verticies.size() == 4);
            }
        }
    } 
}

/*
SCENARIO("Perfect matching") {
    GIVEN("A sparse graph") {
        edge ab = edge(vertex(1), vertex(2));
        edge cd = edge(vertex(3), vertex(4));

        edge_set edges;
        edges.add(ab).add(cd);

        graph sparse_graph = graph(edges);

        WHEN("finding a perfect matching") {
            graph perfect_matching = sparse_graph.find_perfect_matching();

            THEN("the resulting set of edges are a peferct matching") {
                REQUIRE(perfect_matching.edges.contains(ab));
                REQUIRE(perfect_matching.edges.contains(cd));
                REQUIRE(perfect_matching.edges.edges.size() == 2);
            }
        }
    }
}
*/