#pragma once
#ifndef TOPOLOGICAL_SORT_ALGORITHM_
#define TOPOLOGICAL_SORT_ALGORITHM_

#include <vector>
#include <algorithm>
#include "adjacency_matrix_graph.hpp"

namespace GraphLibrary {
    class TopologicalSort {
        public:
            // Static method to perform topological sort on the given graph
            static std::vector<int> topologicalSort(const Graph& graph);

        private:
            // Utility function for DFS traversal
            static void DFSUtil(int node,
                const Graph& graph,
                std::vector<bool>& visited,
                std::vector<int>& visitedNodes);
    };
};
#endif // TOPOLOGICAL_SORT_ALGORITHM_
