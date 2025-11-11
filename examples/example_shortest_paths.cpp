#include "adjacency_matrix_graph.hpp"
#include "shortest_path_algorithms.hpp"

int main() {
    GraphLibrary::AdjacencyMatrixGraph g(5, false);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printMatrix();
    
    auto djkstra = GraphLibrary::ShortestPathAlgorithms::dijkstra(g, 0);
    return 0;
}
