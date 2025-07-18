//  Tarjan’s Algorithm for finding bridges.
#include "pch.h" 
#include "graph.hpp" 
#include "bridges.hpp" 
#include <iostream> 
#include <queue> 
#include <stack> 
#include <algorithm>

#undef min

namespace GraphLibrary { 
	BridgesFinder::BridgesFinder(Graph* g) : graph(g), numVertices(g->getNumVertices()), idCounter(0) 
	{ 
		ids = std::vector<int>(numVertices, 0); 
		lows = std::vector<int>(numVertices, 0); 
		visited = std::vector<bool>(numVertices, false); 
	} 

	/// <summary>
	/// A bridge is an edge that, if removed, increases the number of connected components
	/// in the graph. This function updates the `bridges` vector with all such edges.
	/// </summary>
	/// <returns></returns>
	std::vector<std::pair<int, int>> BridgesFinder::findBridges() 
	{ 
		std::vector<std::pair<int, int>> bridges; 
		for (int i = 0; i < numVertices; i++) 
		{ 
			if (!visited[i]) 
			{ 
				DFSUtil(i, -1, bridges); 
			} 
		} 
		return bridges; 
	} 
	
	/// <summary>
	/// Performs a depth-first search (DFS) traversal to find all bridges (critical edges)
	/// in an undirected graph using Tarjan's algorithm.
	/// </summary>
	/// <param name="node">The current node being visited in the DFS traversal.</param>
	/// <param name="parent">The parent node of the current node in the DFS tree.</param>
	/// <param name="bridges">
	/// A reference to a vector that accumulates all bridges found in the graph.
	/// Each bridge is represented as a pair of integers (u, v), where (u, v) is a critical edge.
	/// </param>
	void BridgesFinder::DFSUtil(int node,			// Current node
		int parent,									// Parent node
		std::vector<std::pair<int, int>>& bridges)	// return value, bridges
	{ 
		visited[node] = true; 
		ids[node] = lows[node] = ++idCounter; 
		auto matrix = graph->getMatrix(); 
		for (int neighbor = 0; neighbor < numVertices; ++neighbor) 
		{ 
			if (matrix[node][neighbor] != 0) 
			{ 
				if (neighbor == parent) 
					continue; 
				if (!visited[neighbor]) 
				{ 
					DFSUtil(neighbor, node, bridges); 
					
					// Update low-link value 
					lows[node] = std::min(lows[node], lows[neighbor]); 
					
					// Bridge condition 
					if (lows[neighbor] > ids[node]) 
					{ 
						bridges.push_back({ node, neighbor }); 
					} 
				} 
				else { 
					// Update low-link on back edge
					lows[node] = std::min(lows[node], ids[neighbor]); 
				} 
			} 
		} 
	} 
}