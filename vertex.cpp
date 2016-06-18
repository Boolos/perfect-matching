#include "vertex.hpp"

csce::vertex::vertex(int _id) : id(_id) {}

template<>
struct std::hash<csce::vertex> {
	std::size_t operator()(const csce::vertex& pt) const {
		return std::hash<int>()(pt.id);
	}
};