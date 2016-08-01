#ifndef UARK_CSCE_EDGE_SET_HEADER
#define UARK_CSCE_EDGE_SET_HEADER

#include <random>
#include <vector>
#include <unordered_set>
#include <map>
#include <list>
#include "math.h"
#include <iostream>
#include "edge.hpp"
#include "vertex.hpp"
#include "polynomial.hpp"

namespace csce {
	class edge_set {
	public:
        edge_set();
        edge_set(const edge_set& edges);
		std::unordered_set<edge, edge_hash> edges;
		edge_set &add(const edge& edge);
        edge_set &remove(const edge& edge);
		bool contains(const edge& edge) const;
		edge_set difference(const edge_set& set) const;
        edge_set get_random_subset();
		edge_set union_set(const edge_set& set) const;
        std::unordered_set<vertex, vertex_hash> get_verticies() const;

		edge_set &add(std::size_t vertex_u);
		edge_set &add(std::size_t vertex_u, std::size_t vertex_v);
        bool contains(std::size_t vertex_u) const;
        bool contains(std::size_t vertex_u, std::size_t vertex_v) const;
        std::size_t degree(std::size_t vertex);
        std::vector<std::pair<std::size_t, std::size_t>>::iterator edges_begin();
        std::vector<std::pair<std::size_t, std::size_t>>::iterator edges_end();
        bool is_sub_set(edge_set& set);
		edge_set &remove(std::size_t vertex_u);
		edge_set &remove(std::size_t vertex_u, std::size_t vertex_v);
        std::size_t size_edges() const;
        std::size_t size_verticies() const;
        std::vector<std::size_t>::iterator verticies_begin();
        std::vector<std::size_t>::iterator verticies_end();
        
	private:
        std::map<std::size_t, std::list<std::size_t>> adjacency_list;
        int getRandomNumber() const;
        void remove_edge(std::size_t vertex_u, std::size_t vertex_v);
	};
}

#endif /* UARK_CSCE_EDGE_SET_HEADER */
