#include "pch.h"
#include "traversal_algorithms.hpp"

namespace GraphLibrary
{
    // BFS implementation
    std::vector<int> TraversalAlgorithms::BFS(
        const Graph& graph,
        int startVertex)
    {
        std::vector<int> visitedOrder;
        int numVertices = graph.getNumVertices();
        
        if (startVertex < 0 || startVertex >= numVertices)
            return visitedOrder; 

        std::vector<bool> visited(numVertices, false);
        std::queue<int> queue;

        // Mark the start vertex as visited and enqueue it
        visited[startVertex] = true;
        queue.push(startVertex);

        while (!queue.empty()) {
            // Dequeue a vertex from the queue
            int vertex = queue.front();
            queue.pop();

            visitedOrder.push_back(vertex);
#ifdef DEBUG
            std::cout << vertex << " ";
#endif
            // Get the adjacency matrix
            int** matrix = graph.getMatrix();

            // Check all adjacent vertices
            for (int i = 0; i < numVertices; ++i) {
                if (matrix[vertex][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    queue.push(i);
                }
            }
        }
        return visitedOrder;
    }

    // DFS implementation
    std::vector<int> TraversalAlgorithms::DFS(
        const Graph& graph,
        int startVertex) {
        std::vector<int> visitedOrder;
        int numVertices = graph.getNumVertices();
        std::vector<bool> visited(numVertices, false);
    
        // Call the utility function for DFS
        DFSUtil(graph, startVertex, visited, visitedOrder);
        return visitedOrder;
    }

    // Utility function for DFS
    void TraversalAlgorithms::DFSUtil(
        const Graph& graph,
        int vertex, 
        std::vector<bool>& visited,
        std::vector<int> visitedOrder) {
        // Mark the current vertex as visited and print it
        visited[vertex] = true;
        std::cout << vertex << " ";

        // Get the adjacency matrix
        int** matrix = graph.getMatrix();
        int numVertices = graph.getNumVertices();

        // Check all adjacent vertices
        visitedOrder.push_back(vertex);
        for (int i = 0; i < numVertices; ++i) {
            if (matrix[vertex][i] != 0 && !visited[i]) {
                DFSUtil(graph, i, visited, visitedOrder);
            }
        }
    }

}