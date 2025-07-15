#include "pch.h"  // Include the precompiled header file
#include "debug.hpp"
#include <iostream>
#include "../GraphFramework/adjacency_matrix_graph.hpp"
using namespace GraphLibrary;

void debugGraph(const AdjacencyMatrixGraph* graph) {
    if (!graph) {
        std::cout << "Graph is null!" << std::endl;
        return;
    }

    std::cout << "Debugging Graph:" << std::endl;

    // Print the number of vertices
    std::cout << "Number of vertices: " << graph->getNumVertices() << std::endl;

    // Print the adjacency matrix
    std::cout << "Adjacency Matrix:" << std::endl;
    graph->printMatrix();

    // Print edge weights and additional details if needed
    std::cout << "Edge weights:" << std::endl;
    for (int i = 0; i < graph->getNumVertices(); ++i) {
        for (int j = 0; j < graph->getNumVertices(); ++j) {
            int weight = graph->getEdgeWeight(i, j);
            if (weight != 0) {  // Assuming 0 means no edge
                std::cout << "Edge from " << i << " to " << j << " with weight " << weight << std::endl;
            }
        }
    }
}

// Function to debug a 1D vector of ints
void debugContainer(const std::string& text, const std::vector<int>& vec) {
    std::cout << text << std::endl;
    std::cout << "Vector contents: ";
    for (const int& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Function to debug a 2D array (int**)
void debugContainer(const std::string& text, int** array, int rows, int cols) {
    std::cout << text << std::endl;
    std::cout << "2D array contents:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}