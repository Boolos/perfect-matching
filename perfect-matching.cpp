#include "perfect-matching.hpp"

using namespace csce;
using namespace std;

PerfectMatching::PerfectMatching() {}

/*
vector<Edge> PerfectMatching::findPerfectMatching(Graph graph) const {
    vector<Edge> matching;
    
    do {
        cout << "======== Finding Perfect Matching ========" << endl;
        matching = this->findMatching();
    } while (!this->isPerfectMatching(matching));
    
	return matching;
}


edge_set graph::findMatching() const {
    graph working_copy = graph(this->edges);
    edge_set matching;
    int cap = 0;

    while (cap++ < 10 && working_copy.has_edges()) {
        cout << "Working copy has " << working_copy.edges.edges.size() << " edges and " << working_copy.verticies.size() << " verticies" << endl;
        for (auto it = working_copy.verticies.begin(); it != working_copy.verticies.end(); it++) {
            cout << "Vertex: " << it->id << " has " << it->degree() << " neighbors" << endl;
        }
        if (working_copy.is_sparse()) {
            cout << "Working copy is sparse" << endl;
            edge_set matched_edges = working_copy.get_matches();
            cout << matched_edges.edges.size() << " matching edges found in working copy" << endl;
            matching = matching.union_set(matched_edges);
            cout << "Current matching has " << matching.edges.size() << " edges" << endl;
            cout << "Working copy had " << working_copy.edges.edges.size() << " edges ";
            working_copy.remove_verticies(matched_edges.get_verticies());
            cout << "and now has " << working_copy.edges.edges.size() << " edges and " << working_copy.verticies.size() << " verticies" << endl;
        } else {
            cout << "Working copy is not sparse" << endl;
            edge_set redundant = working_copy.get_redundant();
            cout << "Found " << redundant.edges.size() << " redundant edges." << endl;
            working_copy.remove_edges(redundant);
            cout << "Working copy now has " << working_copy.edges.edges.size() << " edges in it." << endl;
        }
        cout << "-----------------------" << endl;
    }

    return matching;
}

edge_set graph::get_redundant() {
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
        // TODO START HERE: it looks like the vertex removal isn't working
        if (edge.is_incident_with_degree(1)) {
            matches.add(edge);
        }
    });

    return matches;
}

void graph::remove_edges(const edge_set& edges_to_remove) {
    vector<edge> etr;
    for (auto it = edges_to_remove.edges.begin(); it != edges_to_remove.edges.end(); it++) {
        auto re = this->edges.edges.find(*it);
        if (re != this->edges.edges.end()) {
            etr.push_back(*re);
        }
    }
    this->edges = this->edges.difference(edges_to_remove);
    cout << etr.size() << endl;
    for (int i = 0; i < etr.size(); i++) {
        this->edges.edges.erase(etr[i]);
        cout << etr[i].u.degree() << " / " << etr[i].v.degree() << endl;
        etr[i].u.remove_neighbor(etr[i].v);
        etr[i].v.remove_neighbor(etr[i].u);
        cout << etr[i].u.degree() << " / " << etr[i].v.degree() << endl;
        this->edges.edges.insert(etr[i]);
    }

    
}

void graph::remove_verticies(const unordered_set<vertex, vertex_hash>& verticies_to_remove) {
    edge_set edges_to_remove;
    vector<vertex> v_to_remove;

    for_each(verticies_to_remove.begin(), verticies_to_remove.end(), [&] (const vertex& vertex) {
        v_to_remove.push_back(vertex);

        for_each(this->edges.edges.begin(), this->edges.edges.end(), [&] (const edge& edge) {
            if (edge.u.id == vertex.id || edge.v.id == vertex.id) {
                edges_to_remove.add(edge);
            }
        });
    });

    
    for (int i = 0; i < v_to_remove.size(); i++) {
        v_to_remove[i].destroy();
        this->verticies.erase(v_to_remove[i]);
        this->verticies.insert(v_to_remove[i]);
    } 
    //this->verticies.erase(vertex);


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


// From edge set

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
    
    //for (auto it = subset.edges_begin(); it != subset.edges_end(); it++) {
    //    cout << it->first << " - " << it->second << endl;
    //}
    
    return subset;
}


*/