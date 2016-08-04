#include "edge.hpp"

using namespace csce;
using namespace std;

Edge::Edge(size_t uId, size_t vId) : _u(Vertex(uId)), _v(Vertex(vId)) { }

Edge::Edge(Vertex u, Vertex v) : _u(u), _v(v) { }

Vertex Edge::getU() const {
    return this->_u;
}

Vertex Edge::getV() const {
    return this->_v;
}

string Edge::str() const {
    auto first = _u.getId() < _v.getId() ? _u.getId() : _v.getId();
    auto second = first == _u.getId() ? _v.getId() : _u.getId();
    ostringstream oss;
    oss << first << "-" << second;
    return oss.str();
}
