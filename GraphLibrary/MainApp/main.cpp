#include <iostream>
#include "../GraphFramework/graph.hpp"
#include "../GraphFramework/adjacency_matrix_graph.hpp"
#include "../GraphFramework/traversal_algorithms.hpp"

using namespace GraphLibrary;
int main()
{
    AdjacencyMatrixGraph* graph = new AdjacencyMatrixGraph(6, true);
    graph->addEdge(0, 1);
    graph->addEdge(1, 2);
    graph->addEdge(2, 3);
    graph->addEdge(2, 4);
    graph->addEdge(1, 4);
    graph->addEdge(3, 5);
    graph->addEdge(3, 4);
    graph->printMatrix();

    TraversalAlgorithms::DFS(*graph, 0);

#ifdef DEBUG
    
#endif // DEBUG


    return 0;
}