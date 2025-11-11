#include <iostream>
#include "../GraphFramework/graph.hpp"
#include "../GraphFramework/adjacency_matrix_graph.hpp"
#include "../GraphFramework/traversal_algorithms.hpp"
#include "../GraphFramework/bridges.hpp"
#include "../GraphFramework/articulation_points.hpp"

using namespace GraphLibrary;
int main()
{
    AdjacencyMatrixGraph* graph = new AdjacencyMatrixGraph(6, false);
    graph->addEdge(0, 1);
    graph->addEdge(1, 2);
    graph->addEdge(2, 3);
    graph->addEdge(2, 4);
    graph->addEdge(1, 4);
    graph->addEdge(3, 5);
    graph->addEdge(3, 4);
    graph->printMatrix();

    auto vector = TraversalAlgorithms::BFS(*graph, 0);
    for (auto a : vector)
    {
        std::cout << a << std::endl;
    }

    BridgesFinder bridgeFinder(graph);
    std::vector<std::pair<int, int>> bridges = bridgeFinder.findBridges();
    for (auto bridge : bridges)
    {
        std::cout << bridge.first << " " << 
            bridge.second << std::endl;
    }

    ArticulationPointFinder articulationPointFinder(graph);
    std::vector <int> artPoints = articulationPointFinder.findArticulationPoints();
    for (auto artPt : artPoints)
    {
        std::cout << artPt << std::endl;
    }

    return 0;
}