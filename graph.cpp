#include "graph.hpp"

using namespace csce;
using namespace std;

graph::graph() { }

graph::graph(const edge_set& set) {
    for_each(set.edges.begin(), set.edges.end(), [&] (const edge& e) {
        this->edges.add(e);
        this->verticies.insert(e.u);
        this->verticies.insert(e.v);
        this->vs.emplace(e.u.id, e.u);
        this->vs.emplace(e.v.id, e.v);
        //vs[e.u.id].degree++;
    });
}

graph graph::find_perfect_matching() const {
    edge_set matching;
    
    do {
        matching = this->find_matching();
    } while (!this->is_perfect_matching(matching));
    
	return graph(matching);
}

edge_set graph::find_matching() const {
    graph working_copy = graph(this->edges);
    edge_set matching;

    while (working_copy.has_edges()) {
       if (working_copy.is_sparse()) {
           edge_set matched_edges = working_copy.get_matches();
           matching = matching.union_set(matched_edges);
           working_copy.remove_verticies(matched_edges.get_verticies());
       } else {
           edge_set redundant = get_redundant();
           working_copy.remove_edges(redundant);
       }
    }

    return matching;
}

edge_set graph::get_matches() const {
    edge_set matches;

    for_each(this->edges.edges.begin(), this->edges.edges.end(), [&] (const edge& edge) {
        if (edge.is_incident_with_degree(1)) {
            matches.add(edge);
        }
    });

    return matches;
}

void graph::remove_edges(const edge_set& edges_to_remove) {
    this->edges = this->edges.difference(edges_to_remove);
}

void graph::remove_verticies(const unordered_set<vertex, vertex_hash>& verticies_to_remove) {
    edge_set edges_to_remove;

    for_each(verticies_to_remove.begin(), verticies_to_remove.end(), [&] (const vertex& vertex) {
        this->verticies.erase(vertex);

        for_each(this->edges.edges.begin(), this->edges.edges.end(), [&] (const edge& edge) {
            if (edge.u == vertex || edge.v == vertex) {
                edges_to_remove.edges.insert(edge);
            }
        });
    });

    this->edges = this->edges.difference(edges_to_remove);
}

bool graph::is_perfect_matching(const edge_set& possible_matching) const {
    return true;
}

bool graph::is_sparse() const {
    int sparse = floor(int(3.0 / 4 * this->verticies.size()));
	return this->edges.edges.size() < sparse;
}

bool graph::has_edges() const {
    return this->edges.edges.size() > 0;
}

edge_set graph::get_redundant() const {
    // get random subset S of E
    // foreach e in E - S, if Rank(S u e) == Rank(S) => add E to RE
    // return RE
}

int graph::get_rank(const edge_set& e, const edge_set& s) const {
    // build matrix over E and S
    // replace indeterminate
    // get max degree
}

matrix graph::replace_indeterminates(const matrix& poly_matrix) const {
    // generate random int in range of 1 to |IE|^4
    // compute det(matrix) => polynomial
}

int graph::get_max_degree(const polynomial& determinate) const {
    // iterate over polynomial getting max degree
}