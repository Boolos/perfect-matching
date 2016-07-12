#include "vertex.hpp"

using namespace csce;

vertex::vertex(int _id) : id(_id) { }

void vertex::add_neighbor(const vertex& neighbor) {
    this->neighbors.push_back(neighbor);
}

int vertex::degree() const {
    return this->neighbors.size();
}

