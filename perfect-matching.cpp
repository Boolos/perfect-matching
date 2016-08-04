#include "perfect-matching.hpp"

using namespace csce;
using namespace std;

PerfectMatching::PerfectMatching() {}

PerfectMatching::PerfectMatching(Graph& graph): _graph(graph) {}

Graph PerfectMatching::findPerfectMatching(const Graph& graph) const {
    Graph matching;
    
    do {
        cout << "======== Finding Perfect Matching ========" << endl;
        matching = this->findMatching(graph);
    } while (!this->isPerfectMatching(graph, matching));
    
    auto edges = matching.getEdges();
    cout << "------------ Matches ------------" << endl;
    for (auto it = edges.begin(); it != edges.end(); it++) {
        cout << it->str() << endl;
    }

	return matching;
}

Graph PerfectMatching::findMatching(Graph graph) const {
    Graph matching;

    while (graph.getEdgeCount() > 0) {
        if (this->isSparse(graph)) {
            cout << "Graph is sparse" << endl;
            auto matchedEdges = this->getObviousMatches(graph);
            auto edges = matchedEdges.getEdges();
            for (auto it = edges.begin(); it != edges.end(); it++) {
                Edge e(it->getU().getId(), it->getV().getId());
                matching.add(e);
            }
            auto verticies = matchedEdges.getVerticies();
            cout << "Removing " << verticies.size() << " verticies..." << endl;
            for (auto vertex = verticies.begin(); vertex != verticies.end(); vertex++) {
                Vertex v(vertex->getId());
                cout << v.str() << endl;
                graph.remove(v);
            }

        } else {
            cout << "Graph is not sparse" << endl;
            Graph redundant = this->getRedundantEdges(graph);

            auto edges = redundant.getEdges();
            cout << "Removing " << edges.size() << " edges..." << endl;
            for (auto edge = edges.begin(); edge != edges.end(); edge++) {
                Edge e(edge->getU().getId(), edge->getV().getId());
                cout << e.str() << endl;
                graph.remove(*edge);
            }

        }
        cout << "-----------------------" << endl;
    }

    return matching;
}

bool PerfectMatching::isSparse(const Graph& graph) const {
    auto sparse = floor(int(3.0 / 4 * graph.getVertexCount()));
	return graph.getEdgeCount() < sparse;
}

bool PerfectMatching::isPerfectMatching(const Graph& graph, const Graph& possibleMatching) const {
    auto halfVerticiesCount = floor(int(graph.getVertexCount() / 2.0));
    return possibleMatching.getEdgeCount() <= halfVerticiesCount;
}

Graph PerfectMatching::getObviousMatches(const Graph& graph) const {
    Graph matches;
    auto edges = graph.getEdges();

    for_each(edges.begin(), edges.end(), [&] (const Edge& edge) {
        auto uDegree = graph.getDegree(edge.getU());
        auto vDegree = graph.getDegree(edge.getV());
        
        if (uDegree == 1 || vDegree == 1) {
            matches.add(edge);
        }
    });

    return matches;
}

Graph PerfectMatching::getRedundantEdges(const Graph& graph) const {
    //cout << "Getting redundant edges..." << endl;
    Graph redundant;
    // get random subset S of E
    auto subSet = this->getRandomSubset(graph);
    //Graph subSet;
    //subSet.add(0,2);
    //cout << "Random subset size of E: " << subSet.getEdgeCount() << endl;

    // foreach e in E - S, if Rank(S u e) == Rank(S) => add E to RE
    auto diff = graph.difference(subSet);
    auto edges = diff.getEdges();
    auto sRank = this->getRank(graph, subSet);
    for (auto ed = edges.begin(); ed != edges.end(); ed++) {
        Edge e(ed->getU().getId(), ed->getV().getId());
        //cout << "Adding " << e.str() << " to s (size: " << subSet.getEdgeCount() << ")" << endl;
        subSet.add(e);
        //cout << "s is now size: " << subSet.getEdgeCount() << endl;
        auto eRank = this->getRank(graph, subSet);
        //cout << "eRank: " << eRank << " vs " << "sRank: " << sRank << endl;
        if (eRank == sRank) {
            redundant.add(e);
            //cout << "*********" << e.str() << "*********" << endl;
        }
        subSet.remove(e);
        //cout << "-----------------------" << endl << endl;
    }


    return redundant;
}

int PerfectMatching::getRank(const Graph& e, const Graph& s) const {
    //cout << endl << "Edge: " << e.getEdgeCount() << " / Vertex: " << e.getVertexCount() << endl;
    // build matrix over E and S
    matrix b(e, s);
    auto det = b.determinant();

    // replace indeterminate
    b.replace_indeterminates(e.getEdgeCount());

    det = b.determinant();
    //std::cout << "Determinant after replace: " << det.str() << std::endl;
	
    // get max degree
    //std::cout << "Degree: " << det.degree() << std::endl;
    return det.degree();
}

Graph PerfectMatching::getRandomSubset(const Graph& graph) const {
    int randomEdgesCount = this->getRandomNumber(graph);

    Graph subset;
    auto edges = graph.getEdges();
    auto start = edges.begin();
    auto end = next(start, randomEdgesCount);
    for_each(start, end, [&] (const Edge& e) {
        subset.add(e);
    });
    
    return subset;
}

size_t PerfectMatching::getRandomNumber(const Graph& graph) const {
    int minEdges = 1;
    int maxEdges = int(floor(5.0/6 * graph.getEdgeCount()));

    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(minEdges, maxEdges);

    return distribution(generator);
}
