#ifndef UARK_CSCE_VERTEX_HEADER
#define UARK_CSCE_VERTEX_HEADER

#include <unordered_set>

namespace csce {
	class vertex {
	public:
		int id;
        int degree;
		vertex(int id);
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
