#include "pch.h"
#ifndef EXCLUDE_THIS_FILE
#include <iostream>
#include <vector>
#include <algorithm>
#include "topological_sort.hpp"
#include "adjacency_matrix_graph.hpp"

namespace GraphLibrary
{
    /**
     * Performs topological sorting on the given graph and returns the sorted order of vertices.
     *
     * @param graph The graph represented as a Graph object.
     * @return A vector of integers representing the topological order of the vertices.
     */
    std::vector<int> TopologicalSort::topologicalSort(const Graph& graph)
    {
        int N = graph.getNumVertices(); // Number of nodes
        std::vector<bool> visited(N, false);    // Initialize visited with false
        std::vector<int> ordering;   // Vector to store the topological order

        for (int node = 0; node < N; node++)
        {
            if (!visited[node])
            {
                DFSUtil(node, graph, visited, ordering);
            }
        }
        std::reverse(ordering.begin(), ordering.end());
        return ordering;
    }

    // Utility function for DFS
    void TopologicalSort::DFSUtil(int node,
        const Graph& graph,
        std::vector<bool>& visited,
        std::vector<int>& ordering)
    {
        visited[node] = true;
        ordering.push_back(node);

        int** matrix = graph.getMatrix();
        int numVertices = graph.getNumVertices();

        for (int i = 0; i < numVertices; ++i) {
            if (matrix[node][i] != 0 && !visited[i]) {
                DFSUtil(i, graph, visited, ordering);
            }
        }
    }
}

#else
#endif