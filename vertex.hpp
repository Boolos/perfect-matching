#ifndef UARK_CSCE_VERTEX_HEADER
#define UARK_CSCE_VERTEX_HEADER

#include <unordered_set>

namespace csce {
	class vertex {
	public:
		int id;
		vertex(int id);
		bool operator ==(const csce::vertex& other) const {
			return id == other.id;
		}
		
		bool operator <(const csce::vertex& other) const {
			return id < other.id;
		}
		
	private:
		
	};
}

#endif /* UARK_CSCE_VERTEX_HEADER */
