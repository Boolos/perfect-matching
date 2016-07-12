#include "graph.hpp"

using namespace csce;
using namespace std;

graph::graph() { }

graph::graph(const edge_set& set) {
    for_each(set.edges.begin(), set.edges.end(), [&] (const edge& e) {
        this->edges.add(e);
        this->verticies.insert(e.u);
        this->verticies.insert(e.v);
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

edge_set graph::get_redundant() const {
    edge_set redundant;
    // get random subset S of E
    edge_set s = this->edges.get_random_subset();
    // foreach e in E - S, if Rank(S u e) == Rank(S) => add E to RE
    edge_set diff = this->edges.difference(s);
    for_each(diff.edges.begin(), diff.edges.end(), [&] (const edge& e) {
        edge_set temp;
        temp.add(e);
        if (this->get_rank(s.union_set(temp)) == this->get_rank(s)) {
            redundant.add(e);
        }
    });

    return redundant;
}

int graph::get_rank(const edge_set& s) const {
    // build matrix over E and S
    matrix b(this->edges, s);

    // replace indeterminate
    b.replace_indeterminates(this->edges.edges.size());

    // get max degree
    return b.determinant().degree();
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

bool graph::is_sparse() const {
    int sparse = floor(int(3.0 / 4 * this->verticies.size()));
	return this->edges.edges.size() < sparse;
}

bool graph::has_edges() const {
    return this->edges.edges.size() > 0;
}

bool graph::is_perfect_matching(const edge_set& possible_matching) const {
    int edges_in_matching_count = possible_matching.edges.size();
    int verticies_in_graph_count = this->verticies.size();
    int half_the_number_of_verticies = floor(int(verticies_in_graph_count / 2.0));
    return edges_in_matching_count <= half_the_number_of_verticies;
}
