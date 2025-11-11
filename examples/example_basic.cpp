#include <iostream>
#include <string>
#include "adjacency_matrix_graph.hpp"

using namespace graphx;

class City{
	public:
		City(std::string name_p) : name(name_p) {}
		std::string name;
		
		// Equality operator
		bool operator==(const City& other) const {
        	return name == other.name;
    	}
};

namespace std {
    template <>
    struct hash<City> {
        std::size_t operator()(const City& city) const noexcept {
            return std::hash<std::string>{}(city.name);
        }
    };
}

int main() {
    // Create a directed graph
    AdjacencyMatrixGraph<City, int> graph(0, true);
	
	City paris("paris");
	City london("london");
	City zurich("zurich");
	City rabat("rabat");
	
    // Add some vertices
    graph.add_vertex(paris);
    graph.add_vertex(london);
    graph.add_vertex(zurich);
	
	graph.add_edge(paris, london, 500);
    // Check vertices
    std::cout << "Graph has vertex rabat? " 
              << (graph.has_vertex(rabat) ? "Yes" : "No") << std::endl;
    std::cout << "Graph has vertex zurich? " 
              << (graph.has_vertex(london) ? "Yes" : "No") << std::endl;

    // Add edges (currently empty implementation, will do nothing)
    graph.add_edge(zurich, london, 10);
    graph.add_edge(london, paris, 5);

    // Print vertex count
    std::cout << "Number of vertices: " << graph.vertex_count() << std::endl;
    std::cout << "Number of edges: " << graph.edge_count() << std::endl;

    // Remove a vertex (currently stub)
    graph.remove_vertex(paris);

    // Print vertex count again
    std::cout << "Number of vertices after removal: " << graph.vertex_count() << std::endl;

    return 0;
}
