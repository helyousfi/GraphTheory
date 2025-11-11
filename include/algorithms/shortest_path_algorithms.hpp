#ifndef GRAPHX_INCLUDE_ALGORITHMS_SHORTEST_PATH_ALGORITHMS_H
#define GRAPHX_INCLUDE_ALGORITHMS_SHORTEST_PATH_ALGORITHMS_H

#include "graph.hpp"
#include <vector>

// Define DLL export/import macro
#ifdef GRAPH_LIBRARY_EXPORTS
#define GRAPH_LIBRARY_API __declspec(dllexport)
#else
#define GRAPH_LIBRARY_API __declspec(dllimport)
#endif

namespace GraphLibrary
{
    class ShortestPathAlgorithms {
    public:
        /**
         * Implements the Bellman-Ford algorithm to find the shortest paths from a source vertex to all other vertices
         * in a given weighted graph.
         * The graph is represented using an adjacency matrix.
         *
         * @param graph The graph represented as an AdjacencyMatrixGraph object.
         * @param source The starting vertex for the shortest path calculation.
         * @return A vector containing the shortest distance from the source to each vertex.
         */
        static std::vector<int> bellmanFord(const Graph& graph, int source);
        /**
         * Implements Dijkstra's algorithm to find the shortest paths from a source vertex to all other vertices in a given weighted graph.
         * The graph is represented using an adjacency matrix.
         *
         * @param graph The graph represented as an AdjacencyMatrixGraph object.
         * @param source The starting vertex for the shortest path calculation.
         */
        static std::vector<int> dijkstra(const Graph& graph, int source);
        /**
         * Implements the Floyd-Warshall algorithm to find the shortest paths between all pairs of vertices in a given weighted graph.
         * The graph is represented using an adjacency matrix.
         *
         * @param graph The graph represented as a Graph object.
         * @return A 2D vector representing the shortest distances between all pairs of vertices.
         */
        static std::vector<std::vector<int>> floydWarshal(const Graph& graph);
    };
}


#endif // GRAPHX_INCLUDE_ALGORITHMS_SHORTEST_PATH_ALGORITHMS_H
