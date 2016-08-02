#ifndef UARK_CSCE_GRAPH_HEADER
#define UARK_CSCE_GRAPH_HEADER

#include <vector>
#include <stdexcept>
#include <unordered_set>
#include <iostream>
#include "vertex.hpp"
#include "edge.hpp"

using namespace std;

namespace csce {
	class Graph {
	public:
        Graph();

		Graph &add(size_t id);
		Graph &add(const Vertex& vertex);
		Graph &add(size_t uId, size_t vId);
		Graph &add(const Vertex& u, const Vertex& v);
		Graph &add(const Edge& edge);

        bool contains(size_t id) const;
        bool contains(const Vertex& vertex) const;
        bool contains(size_t uId, size_t vId) const;
		bool contains(const Vertex& u, const Vertex& v) const;
        bool contains(const Edge& edge) const;

        Graph difference(const Graph& other) const;

        Edge getEdge(size_t uId, size_t vId) const;
        Edge getEdge(const Vertex& u, const Vertex& v) const;
        Edge getEdge(const Edge& edge) const;
        size_t getEdgeCount() const;
        vector<Edge> getEdges() const;
        vector<Edge> getEdges(size_t id) const;
        vector<Edge> getEdges(const Vertex& incident) const;

        Vertex getVertex(size_t id) const;
        Vertex getVertex(const Vertex& vertex) const;
        size_t getVertexCount() const;
        vector<Vertex> getVerticies() const;
        
        bool isSubGraph(const Graph& graph) const;

		Graph &remove(size_t id);
		Graph &remove(const Vertex& vertex);
		Graph &remove(size_t uId, size_t vId);
		Graph &remove(const Vertex& u, const Vertex& v);
		Graph &remove(const Edge& edge);

        Graph unionSet(const Graph& other) const;

		bool operator ==(const Graph& other) const {
            if (this->getVertexCount() != other.getVertexCount()) {
                return false;
            }
            if (this->getEdgeCount() != other.getEdgeCount()) {
                return false;
            }

            // dumb search (implement sorted comparison later)
            for (auto vertex = _verticies.begin(); vertex != _verticies.end(); vertex++) {
                if (!other.contains(*vertex)) {
                    return false;
                }
            }
            
            auto edges = this->getEdges();
            for (auto edge = edges.begin(); edge != edges.end(); edge++) {
                if (!other.contains(*edge)) {
                    return false;
                }
            }

            return true;
		}
        
	private:
        vector<Vertex> _verticies;
        vector<Vertex>::iterator _findVertex(const Vertex& vertex);
        vector<Vertex>::const_iterator _findVertex(const Vertex& vertex) const;
	};
}

#endif /* UARK_CSCE_GRAPH_HEADER */
