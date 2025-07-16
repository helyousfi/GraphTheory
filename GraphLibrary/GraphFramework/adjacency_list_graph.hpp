#pragma once
#ifndef GRAPH_DEFENITION_ADJACENCY_LIST
#define GRAPH_DEFENITION_ADJACENCY_LIST

#ifndef EXCLUDE_THIS_FILE

#include <iostream>
#include "graph.hpp"

// Debug macro
#ifdef _DEBUG
#define DEBUG_LOG(msg) std::cout << "DEBUG: " << msg << std::endl;
#else
#define DEBUG_LOG(msg)
#endif

// Define DLL export/import macro
#ifdef GRAPH_LIBRARY_EXPORTS
#define GRAPH_LIBRARY_API __declspec(dllexport)
#else
#define GRAPH_LIBRARY_API __declspec(dllimport)
#endif

namespace GraphLibrary {
    // Adjacency List representation of a graph
    class GRAPH_LIBRARY_API AdjacencyListGraph : public Graph {
    private:
        // Structure to represent a node in the adjacency list
        struct Node {
            int dest;      // Destination vertex of the edge
            int weight;    // Weight of the edge (if weighted)
            Node* next;    // Pointer to the next node in the list
        };

        // Array of pointers to Nodes, one pointer for each vertex
        Node** adjList;
        int numVertices;    // Number of vertices in the graph
        bool directed;      // Indicates if the graph is directed

    public:
        // Constructor to initialize the graph with n vertices
        AdjacencyListGraph(int n, bool isDirected);

        // Destructor to free dynamically allocated memory
        ~AdjacencyListGraph();

        // Function to add an edge from vertex u to vertex v with weight w (for weighted graphs)
        void addEdge(int u, int v, int w = DEFAULT_WEIGHT);

        // Function to remove an edge from vertex u to vertex v
        void removeEdge(int u, int v);

        // Function to check if there is an edge from vertex u to vertex v
        bool hasEdge(int u, int v) const;

        // Function to print the graph
        void printMatrix() const;

        // Getter for the number of vertices
        int getNumVertices() const;

        // Getter for the edge weight
        int getEdgeWeight(int node1, int node2) const;

        // Getter for the adjacency matrix
        int** getMatrix() const;

        // Getter for the neighbor
        int* getNeighbors(int vertex) const;

        // Function to multiply the matrix by -1 : useful for SSSP_DAG longest path
        void multiplyByMinusOne();

        // Get All Edges
        std::vector<std::pair<int, int>> getEdges() const;
    };
};
#else
#endif
#endif // GRAPH_DEFENITION_ADJACENCY_LIST
