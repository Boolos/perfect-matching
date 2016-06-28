#include "edge_set.hpp"

using namespace csce;
using namespace std;

edge_set::edge_set() { }

edge_set::edge_set(const edge_set& initialEdges) {
    for_each(initialEdges.edges.begin(), initialEdges.edges.end(), [&] (const edge& e) {
        this->add(e);
    });
}

edge_set &edge_set::add(const edge& edge) {
    edges.insert(edge);
	return *this;
}

bool edge_set::contains(const edge& edge) const {
	return edges.find(edge) != edges.end();
}

edge_set edge_set::difference(const edge_set& other) const {
    edge_set result;

    for_each(edges.begin(), edges.end(), [&] (const edge& e) {
        if (!other.contains(e)) {
            result.add(e);
        }
    });

    return result;
}

edge_set edge_set::get_random_subset() const {
    int random_edges_count = getRandomNumber();

    edge_set subset;
    auto start = edges.begin();
    auto end = next(edges.begin(), random_edges_count);
    for_each(start, end, [&] (const edge& e) {
        subset.add(e);
    });
    
    return subset;
}

int edge_set::getRandomNumber() const {
    int min_edges = 1;
    int max_edges = int(floor(5.0/6 * edges.size()));

    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(min_edges, max_edges);

    return distribution(generator);
}

edge_set edge_set::union_set(const edge_set& other) const {
    edge_set result = edge_set(*this);

    for_each(other.edges.begin(), other.edges.end(), [&] (const edge& e) {
        if (!result.contains(e)) {
            result.add(e);
        }
    });

    return result;
}

unordered_set<vertex, vertex_hash> edge_set::get_verticies() const {
    unordered_set<vertex, vertex_hash> verticies;

    for_each(edges.begin(), edges.end(), [&] (const edge& e) {
        verticies.insert(e.u);
        verticies.insert(e.v);
    });

    return verticies;
}