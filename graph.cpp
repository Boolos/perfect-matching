#include "graph.hpp"

using namespace csce;
using namespace std;

Graph::Graph() { }

Graph &Graph::add(size_t id) {
    return this->add(Vertex(id));
}

Graph &Graph::add(const Vertex& vertex) {
    auto it = this->_findVertex(vertex);
    if (it != this->_verticies.end()) {
        return *this;
    }

    this->_verticies.push_back(vertex);
    return *this;
}

Graph &Graph::add(size_t uId, size_t vId) {
    return this->add(Vertex(uId), Vertex(vId));
}

Graph &Graph::add(const Vertex& u, const Vertex& v) {
    return this->add(Edge(u, v));
}

Graph &Graph::add(const Edge& edge) {
    if (this->contains(edge)) {
        return *this;
    }

    auto itU = this->_findVertex(edge.getU());
    if (itU != this->_verticies.end()) {
        itU->addNeighbor(edge.getV());
    } else {
        auto u = edge.getU();
        u.addNeighbor(edge.getV());
        this->_verticies.push_back(u);
    }

    auto itV = this->_findVertex(edge.getV());
    if (itV != this->_verticies.end()) {
        itV->addNeighbor(edge.getU());
    } else {
        auto v = edge.getV();
        v.addNeighbor(edge.getU());
        this->_verticies.push_back(v);
    }

    return *this;
}

bool Graph::contains(size_t id) const {
    return this->contains(Vertex(id));
}

bool Graph::contains(const Vertex& vertex) const {
    try {
        this->getVertex(vertex);
        return true;
    } catch (const logic_error& e) {
        return false;
    }
}

bool Graph::contains(size_t uId, size_t vId) const {
    return this->contains(Vertex(uId), Vertex(vId));
}

bool Graph::contains(const Vertex& u, const Vertex& v) const {
    return this->contains(Edge(u, v));
}

bool Graph::contains(const Edge& edge) const {
    try {
        this->getEdge(edge);
        return true;
    } catch (const logic_error& e) {
        return false;
    }
}

Graph Graph::difference(const Graph& other) const {
    Graph diff;

    auto thisVerticies = this->_verticies;
    auto otherVerticies = other.getVerticies();
    for (auto vertex = thisVerticies.begin(); vertex != thisVerticies.end(); vertex++) {
        if (other.contains(*vertex)) {
            continue;
        }

        diff.add(*vertex);
    }

    auto thisEdges = this->getEdges();
    auto otherEdges = other.getEdges();
    for (auto edge = thisEdges.begin(); edge != thisEdges.end(); edge++) {
        if (other.contains(*edge)) {
            continue;
        }

        diff.add(*edge);
    }
    
    return diff;
}

size_t Graph::getDegree(size_t id) const {
    return this->getDegree(Vertex(id));
}

size_t Graph::getDegree(const Vertex& vertex) const {
    auto it = this->_findVertex(vertex);
    if (it == this->_verticies.end()) {
        return -1;
    }
    return it->getDegree();
}

Edge Graph::getEdge(size_t uId, size_t vId) const {
    return this->getEdge(Vertex(uId), Vertex(vId));
}

Edge Graph::getEdge(const Vertex& u, const Vertex& v) const {
    return this->getEdge(Edge(u, v));
}

Edge Graph::getEdge(const Edge& edge) const {
    for (auto vertex = _verticies.begin(); vertex != _verticies.end(); vertex++) {
        auto neighbors = vertex->getNeighbors();
        for (auto neighbor = neighbors.begin(); neighbor != neighbors.end(); neighbor++) {
            Edge e(*vertex, *neighbor);

            if (edge == e) {
                return e;
            }
        }
    }
    throw logic_error("Edge does not exist");
}

size_t Graph::getEdgeCount() const {
    size_t count = 0;
    for (auto vertex = this->_verticies.begin(); vertex != this->_verticies.end(); vertex++) {
        count += vertex->getDegree();
    }
    return count / 2;

}

vector<Edge> Graph::getEdges() const {
    unordered_set<string> distinctEdges;
    vector<Edge> edges;

    for (auto vertex = _verticies.begin(); vertex != _verticies.end(); vertex++) {
        auto neighbors = vertex->getNeighbors();
        for (auto neighbor = neighbors.begin(); neighbor != neighbors.end(); neighbor++) {
            Edge e(*vertex, *neighbor);

            if (distinctEdges.count(e.str()) > 0) {
                continue;
            }

            distinctEdges.insert(e.str());
            edges.push_back(e);
        }
    }
    
    return edges;
}


vector<Edge> Graph::getEdges(size_t id) const {
    return this->getEdges(Vertex(id));
}

vector<Edge> Graph::getEdges(const Vertex& incident) const {
    vector<Edge> edges;

    auto vertex = this->_findVertex(incident);
    if (vertex == this->_verticies.end()) {
        return edges;
    }

    auto neighbors = vertex->getNeighbors();
    for (auto neighbor = neighbors.begin(); neighbor != neighbors.end(); neighbor++) {
        Edge e(vertex->getId(), neighbor->getId());
        edges.push_back(e);
    }
    
    return edges;
}

Vertex Graph::getVertex(size_t id) const {
    return this->getVertex(Vertex(id));
}

Vertex Graph::getVertex(const Vertex& vertex) const {
    auto v = this->_findVertex(vertex);
    
    if (v != this->_verticies.end()) {
        return *v;
    } else {
        throw logic_error("Vertex does not exist");
    }
}

size_t Graph::getVertexCount() const {
    return this->_verticies.size();
}

vector<Vertex> Graph::getVerticies() const {
    return this->_verticies;
}

bool Graph::isSubGraph(const Graph& graph) const {
    auto edges = graph.getEdges();
    for (auto edge = edges.begin(); edge != edges.end(); edge++) {
        if (!this->contains(*edge)) {
            return false;
        }
    }
    
    return true;
}

Graph Graph::join(const Graph& other) const {
    Graph joined;

    auto thisVerticies = this->_verticies;
    auto otherVerticies = other.getVerticies();
    for (auto vertex = thisVerticies.begin(); vertex != thisVerticies.end(); vertex++) {
        joined.add(*vertex);
    }
    for (auto vertex = otherVerticies.begin(); vertex != otherVerticies.end(); vertex++) {
        joined.add(*vertex);
    }

    auto thisEdges = this->getEdges();
    auto otherEdges = other.getEdges();
    for (auto edge = thisEdges.begin(); edge != thisEdges.end(); edge++) {
        joined.add(*edge);
    }
    for (auto edge = otherEdges.begin(); edge != otherEdges.end(); edge++) {
        joined.add(*edge);
    }
    
    return joined;
}

Graph &Graph::remove(size_t id) {
    return this->remove(Vertex(id));
}

Graph &Graph::remove(const Vertex& vertex) {
    auto v = this->_findVertex(vertex);
    if (v == this->_verticies.end()) {
        return *this;
    }

    auto neighbors = v->getNeighbors();
    for (auto neighbor = neighbors.begin(); neighbor != neighbors.end(); neighbor++) {
        v->removeNeighbor(*neighbor);
    }

    this->_verticies.erase(v);
    
    return *this;
}

Graph &Graph::remove(size_t uId, size_t vId) {
    return this->remove(Vertex(uId), Vertex(vId));
}

Graph &Graph::remove(const Vertex& u, const Vertex& v) {
    return this->remove(Edge(u, v));
}

Graph &Graph::remove(const Edge& edge) {
    auto u = this->_findVertex(edge.getU());
    if (u == this->_verticies.end()) {
        return *this;
    }
    u->removeNeighbor(edge.getV());

    auto v = this->_findVertex(edge.getV());
    if (v == this->_verticies.end()) {
        return *this;
    }
    v->removeNeighbor(edge.getU());
    
    return *this;
}

vector<Vertex>::iterator Graph::_findVertex(const Vertex& vertex) {
    for (auto it = this->_verticies.begin(); it != this->_verticies.end(); it++) {
        if (*it == vertex) {
            return it;
        }
    }
    return this->_verticies.end();
}

vector<Vertex>::const_iterator Graph::_findVertex(const Vertex& vertex) const {
    for (auto it = this->_verticies.cbegin(); it != this->_verticies.cend(); it++) {
        if (*it == vertex) {
            return it;
        }
    }
    return this->_verticies.cend();
}
