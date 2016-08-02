#include "vertex.hpp"

using namespace csce;
using namespace std;

Vertex::Vertex(size_t id) : _id(id) { }

Vertex &Vertex::addNeighbor(size_t id) {
    return this->addNeighbor(Vertex(id));
}

Vertex &Vertex::addNeighbor(const Vertex& vertex) {
    this->_neighbors.push_back(vertex);
    return *this;
}

size_t Vertex::getDegree() const {
    return this->_neighbors.size();
}

size_t Vertex::getId() const {
    return this->_id;
}

list<Vertex> Vertex::getNeighbors() const {
    return this->_neighbors;
}

bool Vertex::hasNeighbor(size_t id) const {
    return this->hasNeighbor(Vertex(id));
}

bool Vertex::hasNeighbor(const Vertex& vertex) const {
    auto neighbor = this->_neighbors.begin();
    for (neighbor; neighbor != this->_neighbors.end(); neighbor++) {
        if (*neighbor == vertex) {
            break;
        }
    }
    return neighbor != this->_neighbors.end();
} 

Vertex &Vertex::removeNeighbor(size_t id) {
    this->removeNeighbor(Vertex(id));
    return *this;
}

Vertex &Vertex::removeNeighbor(const Vertex& vertex) {
    this->_neighbors.remove(vertex);
    return *this;
}

string Vertex::str() const {
    ostringstream oss;
    oss << this->_id;
    return oss.str();
}
