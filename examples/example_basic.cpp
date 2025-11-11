#include <iostream>
#include "adjacency_matrix_graph.hpp"

using namespace graphx;

int main() {
    // Create a directed graph
    AdjacencyMatrixGraph<int, int> graph(0, true);

    // Add some vertices
    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_vertex(3);

    // Check vertices
    std::cout << "Graph has vertex 2? " 
              << (graph.has_vertex(2) ? "Yes" : "No") << std::endl;
    std::cout << "Graph has vertex 4? " 
              << (graph.has_vertex(4) ? "Yes" : "No") << std::endl;

    // Add edges (currently empty implementation, will do nothing)
    graph.add_edge(1, 2, 10);
    graph.add_edge(2, 3, 5);

    // Print vertex count
    std::cout << "Number of vertices: " << graph.vertex_count() << std::endl;
    std::cout << "Number of edges: " << graph.edge_count() << std::endl;

    // Remove a vertex (currently stub)
    graph.remove_vertex(2);

    // Print vertex count again
    std::cout << "Number of vertices after removal: " << graph.vertex_count() << std::endl;

    return 0;
}
