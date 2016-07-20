#include "vertex.hpp"

using namespace csce;

vertex::vertex(int _id) : id(_id) { }

void vertex::add_neighbor(const vertex& neighbor) {
    this->neighbors.push_back(neighbor);
}

void vertex::remove_neighbor(const vertex& neighbor) {
    int index = -1;
    for (int i = 0; i < this->neighbors.size(); i++) {
        if (this->neighbors[i].id == neighbor.id) {
            index = i;
            break;
        }
    }
    if (index >= 0) {
        this->neighbors.erase(this->neighbors.begin() + index);
    }
}

void vertex::destroy() {
    for (int i = 0; i < this->neighbors.size(); i++) {
        this->neighbors[i].remove_neighbor(*this);
    }
}

int vertex::degree() const {
    return this->neighbors.size();
}

