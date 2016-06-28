#include "edge.hpp"

using namespace csce;

edge::edge(vertex _u, vertex _v) : u(_u), v(_v) { }

bool edge::is_incident_with_degree(int degree) const {
    return this->u.degree == degree || this->v.degree == degree;
}