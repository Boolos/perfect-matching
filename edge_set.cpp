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

edge_set &edge_set::remove(const edge& edge) {
    auto it = edges.find(edge);
    if (it != edges.end()) {
        edges.erase(*it);
    }
    return *this;
}

bool edge_set::contains(const edge& edge) const {
	return edges.find(edge) != edges.end();
}

edge_set edge_set::difference(const edge_set& other) const {
    edge_set result;

    for_each(this->edges.begin(), this->edges.end(), [&] (const edge& e) {
        if (!other.contains(e)) {
            result.add(e);
        }
    });
    
    return result;
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










int edge_set::getRandomNumber() const {
    int min_edges = 1;
    int max_edges = int(floor(5.0/6 * this->size_edges()));

    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(min_edges, max_edges);

    return distribution(generator);
}

edge_set edge_set::get_random_subset() {
    int random_edges_count = getRandomNumber();

    edge_set subset;
    auto start = this->edges_begin();
    auto end = next(start, random_edges_count);
    for_each(start, end, [&] (const pair<size_t, size_t>& e) {
        subset.add(e.first, e.second);
    });
    
    /*
    for (auto it = subset.edges_begin(); it != subset.edges_end(); it++) {
        cout << it->first << " - " << it->second << endl;
    }
    */
    
    return subset;
}

vector<pair<size_t, size_t>>::iterator edge_set::edges_begin() {
    vector<pair<size_t, size_t>> edges;
    std::map<size_t, list<size_t>> copy;
    
    auto begin = this->adjacency_list.begin();
    auto end = this->adjacency_list.end();
    for (auto it = begin; it != end; it++) {
        list<size_t> adjs;
        for (auto jt = it->second.begin(); jt != it->second.end(); jt++) {
            adjs.push_back(*jt);
        }
        copy[it->first] = adjs;
    }

    for (auto it = copy.begin(); it != copy.end(); it++) {
        for (auto jt = it->second.begin(); jt != it->second.end(); jt++) {
            pair<size_t, size_t> edge;
            edge.first = it->first;
            edge.second = *jt;
            edges.push_back(edge);
            this->remove(*jt, it->first);
        }
    }

    return edges.begin();
}

vector<pair<size_t, size_t>>::iterator edge_set::edges_end() {
    vector<pair<size_t, size_t>> edges;
    std::map<size_t, list<size_t>> copy;
    
    auto begin = this->adjacency_list.begin();
    auto end = this->adjacency_list.end();
    for (auto it = begin; it != end; it++) {
        list<size_t> adjs;
        for (auto jt = it->second.begin(); jt != it->second.end(); jt++) {
            adjs.push_back(*jt);
        }
        copy[it->first] = adjs;
    }

    for (auto it = copy.begin(); it != copy.end(); it++) {
        for (auto jt = it->second.begin(); jt != it->second.end(); jt++) {
            pair<size_t, size_t> edge = { it->first, *jt };
            edges.push_back(edge);
            this->remove(*jt, it->first);
        }
    }

    return edges.end();
}

vector<size_t>::iterator edge_set::verticies_begin() {
    vector<size_t> verticies;
    auto begin = this->adjacency_list.begin();
    auto end = this->adjacency_list.end();
    for (auto it = begin; it != end; it++) {
        verticies.push_back(it->first);
    }
    return verticies.begin();
}

vector<size_t>::iterator edge_set::verticies_end() {
    vector<size_t> verticies;
    auto begin = this->adjacency_list.begin();
    auto end = this->adjacency_list.end();
    for (auto it = begin; it != end; it++) {
        verticies.push_back(it->first);
    }
    return verticies.end();
}

bool edge_set::is_sub_set(edge_set& set) {
    cout << this->size_edges() << " == " << set.size_edges() << endl;
    for (auto it = set.edges_begin(); it != set.edges_end(); it++) {
        cout << it->first << " | " << it->second << endl;
        if (!this->contains(it->first, it->second)) {
            return false;
        }
    }
    
    return true;
}

edge_set &edge_set::add(size_t vertex_u) {
    this->adjacency_list[vertex_u];
    return *this;
}

edge_set &edge_set::add(size_t vertex_u, size_t vertex_v) {
    if (this->contains(vertex_u, vertex_v)) {
        return *this;
    }

    this->adjacency_list[vertex_u].push_back(vertex_v);
    this->adjacency_list[vertex_v].push_back(vertex_u);
    return *this;
}

edge_set &edge_set::remove(size_t vertex_u) {
    auto it = this->adjacency_list.find(vertex_u);
    if (it == this->adjacency_list.end()) {
        return *this;
    }

    for (auto jt = it->second.begin(); jt != it->second.end(); jt++) {
        this->remove_edge(*jt, vertex_u);
    }

    this->adjacency_list.erase(vertex_u);
    
    return *this;
}

edge_set &edge_set::remove(size_t vertex_u, size_t vertex_v) {
    this->remove_edge(vertex_u, vertex_v);
    this->remove_edge(vertex_v, vertex_u);
    return *this;
}

void edge_set::remove_edge(size_t vertex_u, size_t vertex_v) {
    auto it = this->adjacency_list.find(vertex_u);
    if (it == this->adjacency_list.end()) {
        return;
    }

    it->second.remove(vertex_v);
}

bool edge_set::contains(size_t vertex_u) const {
    auto it = this->adjacency_list.find(vertex_u);
    return it != this->adjacency_list.end();
}

bool edge_set::contains(size_t vertex_u, size_t vertex_v) const {
    auto it = this->adjacency_list.find(vertex_u);
    if (it == this->adjacency_list.end()) {
        return false;
    }

    for (auto jt = it->second.begin(); jt != it->second.end(); jt++) {
        if (*jt == vertex_v) {
            return true;
        } 
    }

    return false;
}

size_t edge_set::size_edges() const {
    size_t count = 0;
    for (auto it = this->adjacency_list.begin(); it != this->adjacency_list.end(); it++) {
        count += it->second.size();
    }
    return count / 2;
}

size_t edge_set::size_verticies() const {
    return this->adjacency_list.size();
}

size_t edge_set::degree(size_t vertex) {
    return this->adjacency_list[vertex].size();
}
