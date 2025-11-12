#include <iostream>
#include <string>
#include "adjacency_matrix_graph.hpp"
#include "city.hpp"

using namespace graphx;

int main() {
    // Create a directed graph
    AdjacencyMatrixGraph<City, int> graph(0, false);
	
	City paris("paris");
	City london("london");
	City zurich("zurich");
	City rabat("rabat");
	
    // Add some vertices
    graph.add_vertex(paris);
    graph.add_vertex(london);
    graph.add_vertex(zurich);
	
	
    // Check vertices
    std::cout << "Graph has vertex rabat? " 
              << (graph.has_vertex(rabat) ? "Yes" : "No") << std::endl;
    std::cout << "Graph has vertex zurich? " 
              << (graph.has_vertex(london) ? "Yes" : "No") << std::endl;

    // Add edges (currently empty implementation, will do nothing)
    graph.add_edge(zurich, london, 10);
    graph.add_edge(london, paris, 5);
	graph.remove_edge(london, paris);
	graph.add_edge(paris, london, 500);
	
	std::cout << "Has edge paris-london: " << graph.has_edge(paris, london) << std::endl;
	std::cout << "Has edge paris-zurich: " << graph.has_edge(paris, zurich) << std::endl;
    // Print vertex count
    std::cout << "Number of vertices: " << graph.vertex_count() << std::endl;
    std::cout << "Number of edges: " << graph.edge_count() << std::endl;
	
    // Print vertex count again
    std::cout << "Number of vertices after removal: " << graph.vertex_count() << std::endl;
	
	graph.print();
    return 0;
}
