#ifndef UARK_CSCE_VERTEX_HEADER
#define UARK_CSCE_VERTEX_HEADER

#include <list>
#include <string>
#include <sstream>

using namespace std;

namespace csce {
	class Vertex {
	public:
        Vertex* parent;
        string color;

		Vertex(size_t id);
        
        Vertex &addNeighbor(size_t id);
        Vertex &addNeighbor(const Vertex& vertex);
        size_t getDegree() const; 
        size_t getId() const;
        list<Vertex> getNeighbors() const;
        bool hasNeighbor(size_t id) const;
        bool hasNeighbor(const Vertex& vertex) const;
        Vertex &removeNeighbor(size_t id);
        Vertex &removeNeighbor(const Vertex& vertex);
        string str() const;

		bool operator ==(const Vertex& other) const {
			return this->_id == other.getId();
		}
		
		bool operator <(const Vertex& other) const {
			return this->_id < other.getId();
		}

		bool operator >(const Vertex& other) const {
			return this->_id > other.getId();
		}
	private:
		size_t _id;
        list<Vertex> _neighbors;
	};
}

#endif /* UARK_CSCE_VERTEX_HEADER */
