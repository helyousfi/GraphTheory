#ifndef GRAPH_PLOTTER_HPP
#define GRAPH_PLOTTER_HPP
#ifndef EXCLUDE_THIS_FILE
#include "../GraphFramework/adjacency_matrix_graph.hpp"
using namespace GraphLibrary;

class GraphPlotter {
public:
    // Function to plot an adjacency matrix graph
    static void visualizeGraph(const std::vector<std::pair<int, int>>& edges);
};
#else
#endif
#endif // GRAPH_PLOTTER_HPP
