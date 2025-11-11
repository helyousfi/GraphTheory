#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <string>
#include "adjacency_matrix_graph.hpp"
#include "shortest_path_algorithms.hpp"
// #include "debug.hpp"

namespace GraphLibrary
{
    std::vector<int> ShortestPathAlgorithms::bellmanFord(const Graph& graph, int source) {
        int V = graph.getNumVertices();
        int** adjMatrix = graph.getMatrix();
        std::vector<int> distance(V, INT_MAX);
        distance[source] = 0;

        // Relax edges V-1 times
        for (int i = 0; i < V - 1; ++i) {
            for (int u = 0; u < V; ++u) {
                for (int v = 0; v < V; ++v) {
                    if (adjMatrix[u][v] != 0 && 
                        distance[u] != INT_MAX && 
                        distance[u] + adjMatrix[u][v] < distance[v]) 
                    {
                        distance[v] = distance[u] + adjMatrix[u][v];
#ifdef DEBUG
                        debugContainer("adjMatrix[" 
                            + std::to_string(u) + "]"
                            + "[" + std::to_string(v) + "]", distance);
                        debugContainer("distance[" + std::to_string(v) + "]", distance);
#endif // DEBUG
                    }
                }
            }
        }

        // Check for negative-weight cycles
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                if (adjMatrix[u][v] != 0 
                    && distance[u] != INT_MAX 
                    && distance[u] + adjMatrix[u][v] < distance[v]) {
                    std::cout << 
                        "Graph contains a negative-weight cycle" << std::endl;
                    return std::vector<int>();
                }
            }
        }

        return distance;
    }


    std::vector<int> ShortestPathAlgorithms::dijkstra(const Graph& graph, int source) {
        // Number of vertices in the graph
        int V = graph.getNumVertices();

        // Get the adjacency matrix of the graph
        int** adjMatrix = graph.getMatrix();

        // Initialize the distance vector with the maximum possible value (infinity) for all vertices
        // and set the distance to the source vertex to 0
        std::vector<int> distance(V, INT_MAX);
        distance[source] = 0;

        // Priority queue (implemented as a set of pairs) to store vertices and their distances
        // The pair contains the distance and the vertex
        std::set<std::pair<int, int>> pq;
        pq.insert({ 0, source });

        // Process the priority queue until it's empty
        while (!pq.empty()) {
            // Extract the vertex with the minimum distance from the source
            int u = pq.begin()->second;
            pq.erase(pq.begin());

            // Traverse all adjacent vertices of the extracted vertex u
            for (int v = 0; v < V; ++v) {
                // If there is an edge from u to v
                if (adjMatrix[u][v] != INT_MAX) {
                    // Perform the relaxation step
                    if (distance[u] + adjMatrix[u][v] < distance[v]) {
                        // Update the distance of vertex v
                        pq.erase({ distance[v], v }); // Remove the old distance if it exists
                        distance[v] = distance[u] + adjMatrix[u][v];
                        pq.insert({ distance[v], v }); // Insert the new distance
                    }
                }
            }
        }

        // Print the shortest distances from the source to all other vertices
        std::cout << "Vertex\tDistance from Source" << std::endl;
        for (int i = 0; i < V; ++i) {
            std::cout << i << "\t" << (distance[i] == INT_MAX ? "INF" : std::to_string(distance[i])) << std::endl;
        }
        return distance;
    }

    std::vector<std::vector<int>> ShortestPathAlgorithms::floydWarshal(
        const Graph& graph) {
        // Number of vertices in the graph
        int V = graph.getNumVertices();
        // Get the adjacency matrix of the graph
        int** adjMatrix = graph.getMatrix();

        // Initialize & fill the dist matrix
        std::vector<std::vector<int>> dist(V, std::vector<int>(V));

        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (i == j) {
                    dist[i][j] = 0;
                }
                else if (adjMatrix[i][j] != 0) {
                    dist[i][j] = adjMatrix[i][j];
                }
                else {
                    dist[i][j] = INT_MAX;
                }
            }
        }

        // The core of the Floyd-Warshall algorithm
        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        return dist;
    }
}
