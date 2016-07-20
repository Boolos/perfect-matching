#include "edge.hpp"
#include <iostream>

using namespace csce;

edge::edge(const vertex& _u, const vertex& _v) : u(_u), v(_v) { }

bool edge::is_incident_with_degree(int degree) const {
    //std::cout << this->u.degree() << " - " << this->v.degree() << std::endl;
    return degree == this->u.degree() || degree == this->v.degree();
}