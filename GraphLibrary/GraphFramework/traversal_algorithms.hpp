#ifndef TRAVERSAL_ALGORITHMS_H
#define TRAVERSAL_ALGORITHMS_H

#include "adjacency_matrix_graph.hpp"
#include <vector>
#include <iostream>
#include <queue>
#include <stack>

// Define DLL export/import macro
#ifdef GRAPH_LIBRARY_EXPORTS
#define GRAPH_LIBRARY_API __declspec(dllexport)
#else
#define GRAPH_LIBRARY_API __declspec(dllimport)
#endif

namespace GraphLibrary {
    class GRAPH_LIBRARY_API TraversalAlgorithms {
    public:
        // Perform Breadth-First Search (BFS) starting from the given vertex
        static std::vector<int> BFS(const Graph& graph, int startVertex);

        // Perform Depth-First Search (DFS) starting from the given vertex
        static std::vector<int> DFS(const Graph& graph, int startVertex);

    private:
        // Helper function for DFS traversal
        static void DFSUtil(const Graph& graph, 
            int vertex, 
            std::vector<bool>& visited,
            std::vector<int> visitedOrder);
    };
};

#endif // TRAVERSAL_ALGORITHMS_H
