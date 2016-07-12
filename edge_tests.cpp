#include "catch.hpp"
#include "edge.hpp"
#include "vertex.hpp"
#include <iostream>

using namespace csce;
using namespace std;

SCENARIO("Degree") {

    GIVEN("The two edges and three verticies") {
        vertex u(1);
        vertex v(2);
        vertex w(3);

        WHEN("two edges are constructed with one vertex in commo") {
            u.add_neighbor(v);
            v.add_neighbor(u);
            v.add_neighbor(w);
            w.add_neighbor(v);
            edge e = edge(u, v);
            edge f = edge(v, w);

            THEN("the vertex in common has a degree of 2") {
                REQUIRE(v.degree() == 2);
            }

            THEN("the vertexes not in common have degrees of 1") {
                REQUIRE(u.degree() == 1);
                REQUIRE(w.degree() == 1);
            }

            THEN("the edges are incident with a vertext that has a degree of 1") {
                REQUIRE(e.is_incident_with_degree(1) == true);
                REQUIRE(f.is_incident_with_degree(1) == true);
            }

            THEN("the edges are incident with a vertext that has a degree of 2") {
                REQUIRE(e.is_incident_with_degree(2) == true);
                REQUIRE(f.is_incident_with_degree(2) == true);
            }
            
            THEN("the edges are not incident with a vertext that has a degree of 3") {
                REQUIRE(e.is_incident_with_degree(3) == false);
                REQUIRE(f.is_incident_with_degree(3) == false);
            }
        }
    }

}