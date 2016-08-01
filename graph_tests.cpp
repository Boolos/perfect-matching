#include "catch.hpp"
#include "graph.hpp"
#include "edge_set.hpp"
#include <iostream>

using namespace csce;
using namespace std;
/*
SCENARIO("Constructing a graph") {
    GIVEN("A set of edges") {
        vertex a(1);
        vertex b(2);
        vertex c(3);
        vertex d(4);
        vertex e(5);
        vertex f(6);

        edge ad(a, d);
        edge af(a, f);
        edge bd(b, d);
        edge be(b, e);
        edge cd(c, d);
        edge ce(c, e);
        edge cf(c, f);

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

        a.add_neighbor(d);
        d.add_neighbor(a);
        edge ad = edge(a, d);

        a.add_neighbor(f);
        f.add_neighbor(a);
        edge af = edge(a, f);

        b.add_neighbor(d);
        d.add_neighbor(b);
        edge bd = edge(b, d);

        b.add_neighbor(e);
        e.add_neighbor(b);
        edge be = edge(b, e);

        c.add_neighbor(d);
        d.add_neighbor(c);
        edge cd = edge(c, d);

        c.add_neighbor(e);
        e.add_neighbor(c);
        edge ce = edge(c, e);

        c.add_neighbor(f);
        f.add_neighbor(c);
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

SCENARIO("Perfect matching") {
    GIVEN("A sparse graph") {
        vertex a(1);
        vertex b(2);
        vertex c(3);
        vertex d(4);

        a.add_neighbor(b);
        b.add_neighbor(a);
        c.add_neighbor(d);
        d.add_neighbor(c);
        
        edge ab = edge(a, b);
        edge cd = edge(c, d);

        edge_set edges;
        edges.add(ab).add(cd);

        graph sparse_graph = graph(edges);

        WHEN("finding a perfect matching") {
            auto perfect_matching = sparse_graph.find_perfect_matching();

            THEN("the resulting set of edges are a peferct matching") {
                REQUIRE(perfect_matching.contains(ab));
                REQUIRE(perfect_matching.contains(cd));
                REQUIRE(perfect_matching.edges.size() == 2);
            }
        }
    }

    GIVEN("A non sparse bipartite graph") {
        vertex a(1);
        vertex b(2);
        vertex c(3);
        vertex d(4);

        a.add_neighbor(c);
        c.add_neighbor(a);

        b.add_neighbor(d);
        d.add_neighbor(b);

        a.add_neighbor(d);
        d.add_neighbor(a);
        
        b.add_neighbor(c);
        c.add_neighbor(b);
        
        edge ac = edge(a, c);
        edge bd = edge(b, d);
        edge ad = edge(a, d);
        edge bc = edge(b, c);

        edge_set edges;
        edges.add(ac).add(bd).add(ad).add(bc);

        graph non_sparse_graph = graph(edges);

        WHEN("finding a perfect matching") {
            auto perfect_matching = non_sparse_graph.find_perfect_matching();

            THEN("the resulting set of edges are a peferct matching") {
                REQUIRE(perfect_matching.edges.size() == 2);
            }
        }
    }
}
*/