#ifndef UARK_CSCE_VERTEX_HEADER
#define UARK_CSCE_VERTEX_HEADER

#include <vector>
#include <unordered_set>

namespace csce {
	class vertex {
	public:
		int id;
		vertex(int id);
        std::vector<vertex> neighbors;
        void add_neighbor(const vertex& neighbor);
        void remove_neighbor(const vertex& neighbor);
        int degree() const; 
        void destroy();

		bool operator ==(const vertex& other) const {
			return id == other.id;
		}
		
		bool operator <(const vertex& other) const {
			return id < other.id;
		}
	private:
	};

    struct vertex_hash {
        std::size_t operator()(const vertex& pt) const {
            return std::hash<int>()(pt.id);
        }
    };		
}

#endif /* UARK_CSCE_VERTEX_HEADER */
