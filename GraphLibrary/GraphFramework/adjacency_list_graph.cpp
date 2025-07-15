// NOT YET IMPLEMENTED
#include "pch.h"
#include "adjacency_list_graph.hpp"

using namespace GraphLibrary;
// Constructor to initialize the graph with n vertices
AdjacencyListGraph::AdjacencyListGraph(int n, bool isDirected)
    : numVertices(n), directed(isDirected) {
    // Initialize the adjacency matrix with all zeros (no edges initially)
    adjList = new Node* [n]; // Allocates an array of n pointers to int (rows of the matrix).
    for (int i = 0; i < n; ++i) {
        adjList[i] = new Node[n];
        // Initialize all elements to zero
        // ...
    }
}

AdjacencyListGraph::~AdjacencyListGraph()
{
    // Free memory for each row
    for (int i = 0; i < numVertices; ++i) {
        delete[] adjList[i];
        adjList[i] = nullptr;
    }
    // Free memory for the array of pointers
    delete[] adjList;
    adjList = nullptr;
}

// Function to add an edge from vertex u to vertex v with weight w (for weighted graphs)
void AdjacencyListGraph::addEdge(int u, int v, int w) {
    // Assuming vertices are 0-indexed
    if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {

    }
    else {
        std::cout << "Error: Invalid vertices " << u << " or " << v << std::endl;
    }
}

// Function to remove an edge from vertex u to vertex v
void AdjacencyListGraph::removeEdge(int u, int v) {

}

// Function to check if there is an edge from vertex u to vertex v
bool AdjacencyListGraph::hasEdge(int u, int v) const {
    return true;
}

// Function to print the adjacency matrix (for debugging purposes)
void AdjacencyListGraph::printMatrix() const {

}

// Getter for the number of vertices
int AdjacencyListGraph::getNumVertices() const {
    return numVertices;
}

// Getter for edge weight
int AdjacencyListGraph::getEdgeWeight(int u, int v) const {
    return 0;
}

// Getter for the adjacency matrix
int** AdjacencyListGraph::getMatrix() const {
    return NULL;
}

// Getter for the neighbor
int* AdjacencyListGraph::getNeighbors(int vertex) const {
    return NULL;
}

// Function to multiply the matrix by -1
void AdjacencyListGraph::multiplyByMinusOne() {

}

// Get all edges in the graph
std::vector<std::pair<int, int>> AdjacencyListGraph::getEdges() const {
    return std::vector<std::pair<int, int>>{};
}