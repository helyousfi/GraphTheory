#include "pch.h"
#include "traversal_algorithms.hpp"

namespace GraphLibrary
{
    // BFS implementation
    void TraversalAlgorithms::BFS(
        const AdjacencyMatrixGraph& graph, 
        int startVertex)
    {
        int numVertices = graph.getNumVertices();
        std::vector<bool> visited(numVertices, false);
        std::queue<int> queue;

        // Mark the start vertex as visited and enqueue it
        visited[startVertex] = true;
        queue.push(startVertex);

        while (!queue.empty()) {
            // Dequeue a vertex from the queue
            int vertex = queue.front();
            std::cout << vertex << " ";
            queue.pop();

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
        std::cout << std::endl;
    }

    // DFS implementation
    void TraversalAlgorithms::DFS(const AdjacencyMatrixGraph& graph, int startVertex) {
        int numVertices = graph.getNumVertices();
        std::vector<bool> visited(numVertices, false);
    
        // Call the utility function for DFS
        DFSUtil(graph, startVertex, visited);
    }

    // Utility function for DFS
    void TraversalAlgorithms::DFSUtil(const AdjacencyMatrixGraph& graph, int vertex, std::vector<bool>& visited) {
        // Mark the current vertex as visited and print it
        visited[vertex] = true;
        std::cout << vertex << " ";

        // Get the adjacency matrix
        int** matrix = graph.getMatrix();
        int numVertices = graph.getNumVertices();

        // Check all adjacent vertices
        for (int i = 0; i < numVertices; ++i) {
            if (matrix[vertex][i] != 0 && !visited[i]) {
                DFSUtil(graph, i, visited);
            }
        }
    }

}