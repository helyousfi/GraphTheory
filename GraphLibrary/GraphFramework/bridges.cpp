#include "pch.h"
#include "graph.hpp"
#include "bridges.hpp"
#include <iostream>
#include <queue>
#include <stack>

namespace GraphLibrary
{
    BridgesFinder::BridgesFinder(Graph *g) : graph(g), 
        numVertices(g->getNumVertices()), idCounter(0)
    {
        ids = std::vector<int> (numVertices, 0);
        lows = std::vector<int>(numVertices, 0);
        visited = std::vector<bool>(numVertices, false);
    }
    std::vector<std::pair<int, int>> BridgesFinder::findBridges(){
        std::vector<std::pair<int, int>> bridges;
        for (int i = 0; i < numVertices; i++){
            if (!visited[i]){
                DFSUtil(i, -1, bridges);
            }
        }
        return bridges;
    }
    void BridgesFinder::DFSUtil(int node,
        int parent,
        std::vector<std::pair<int, int>>& bridges)
    {
        visited[node] = true;
        ids[node] = lows[node] = ++idCounter;
        auto matrix = graph->getMatrix();
        for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
            if (matrix[node][neighbor] != 0) {
                if (neighbor == parent)
                    continue;
                if(!visited[neighbor])
                {
                    DFSUtil(neighbor, node, bridges);
                    // lows[node] = std::min(lows[node], lows[neighbor]);
                    if (ids[node] < ids[neighbor])
                    {
                        bridges.push_back({ node, neighbor });
                    }
                    // else
                        // lows[neighbor] = std::min(lows[node], lows[neighbor]);
                }
            }
        }
    }
}