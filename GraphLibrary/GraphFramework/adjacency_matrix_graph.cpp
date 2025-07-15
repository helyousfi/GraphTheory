#include "pch.h"
#include "adjacency_matrix_graph.hpp"

using namespace GraphLibrary;
// Constructor to initialize the graph with n vertices
AdjacencyMatrixGraph::AdjacencyMatrixGraph(int n, bool isDirected) 
    : numVertices(n), directed(isDirected){
    // Initialize the adjacency matrix with all zeros (no edges initially)
    matrix = new int*[n]; // Allocates an array of n pointers to int (rows of the matrix).
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        // Initialize all elements to zero
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = 0;
        }
    }
}

AdjacencyMatrixGraph::~AdjacencyMatrixGraph()
{
    // Free memory for each row
    for (int i = 0; i < numVertices; ++i) {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    // Free memory for the array of pointers
    delete[] matrix;
    matrix = nullptr;
}

// Function to add an edge from vertex u to vertex v with weight w (for weighted graphs)
void AdjacencyMatrixGraph::addEdge(int u, int v, int w) {
    // Assuming vertices are 0-indexed
    if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
        matrix[u][v] = w;
        // if the graph is undirected
        if (!directed)
        {
            matrix[v][u] = w;
        }
    } else {
        std::cout << "Error: Invalid vertices " << u << " or " << v << std::endl;
    }
}

// Function to remove an edge from vertex u to vertex v
void AdjacencyMatrixGraph::removeEdge(int u, int v) {
    if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
        matrix[u][v] = 0;
        // if the graph is undirected
        matrix[v][u] = 0;
    } else {
        std::cout << "Error: Invalid vertices " << u << " or " << v << std::endl;
    }
}

// Function to check if there is an edge from vertex u to vertex v
bool AdjacencyMatrixGraph::hasEdge(int u, int v) const {
    if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
        return matrix[u][v] != 0;
    } else {
        std::cout << "Error: Invalid vertices " << u << " or " << v << std::endl;
        return false;
    }
}

// Function to print the adjacency matrix (for debugging purposes)
void AdjacencyMatrixGraph::printMatrix() const {
    std::cout << "Adjacency Matrix:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Getter for the number of vertices
int AdjacencyMatrixGraph::getNumVertices() const {
    return numVertices;
}

// Getter for edge weight
int AdjacencyMatrixGraph::getEdgeWeight(int u, int v) const {
    return matrix[u][v];
}

// Getter for the adjacency matrix
int** AdjacencyMatrixGraph::getMatrix() const {
    return matrix;
}

// Getter for the neighbor
int* AdjacencyMatrixGraph::getNeighbors(int vertex) const {
    return matrix[vertex];
}

// Function to multiply the matrix by -1
void AdjacencyMatrixGraph::multiplyByMinusOne() {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (matrix[i][j] != 0) // Only if there is an edge
                matrix[i][j] = -matrix[i][j];
        }
    }
}

// Get all edges in the graph
std::vector<std::pair<int, int>> AdjacencyMatrixGraph::getEdges() const {
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (matrix[i][j] != 0) {
                edges.emplace_back(i, j);
            }
        }
    }
    return edges;
}