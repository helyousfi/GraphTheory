#include "pch.h"
#ifdef EXCLUDE_THIS_FILE
// Function to find shortest paths from the source to all vertices
#include<vector>
#include<map>
#include<iostream>
#include <limits>
#include "graph.hpp"
#include "graphAlgorithms.hpp"

/// @brief Finds shortest path in a DAG
/// @param graph 
/// @param source 
/// @return 
std::vector<int> shortestPath(AdjacencyMatrixGraph& graph, int source) {
    std::vector<int> sorted = TopologicalSort(graph);
    
    // Number of vertices in the graph
    int V = graph.getNumVertices();

    // Initialize distances to all vertices as infinite except for the source
    std::vector<int> distance(V, std::numeric_limits<int>::max());
    distance[source] = 0;

    for(int u : sorted)
    {
        int* neighbors = graph.getMatrix()[u];
        // Update distances of all adjacent vertices
        for (int v = 0; v < V; v++) {
            if (neighbors[v] && neighbors[v] + distance[u] < distance[v] ) {
                distance[v] = neighbors[v] + distance[u];
            }
        }
    }
    return distance;
}

/// @brief Longest path finder in a DAG
/// @param graph 
/// @param source 
/// @return 
std::vector<int> longestPath(AdjacencyMatrixGraph& graph, int source)
{
    AdjacencyMatrixGraph invGraph = graph;
    invGraph.multiplyByMinusOne();
    std::vector<int> distance = shortestPath(invGraph, source);
    for (int &d : distance) {
        if (d != std::numeric_limits<int>::max())
            d = -d;
    }
    return distance;
}
#else
#endif