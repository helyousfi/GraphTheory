#ifndef DEBUG_FUNCTIONS_HPP
#define DEBUG_FUNCTIONS_HPP
#include "../GraphFramework/adjacency_matrix_graph.hpp"
using namespace GraphLibrary;
// Function to print debugging information about the graph
void debugGraph(const AdjacencyMatrixGraph* graph);
void debugContainer(const std::string& text, const std::vector<int>& vec);
void debugContainer(const std::string& text, int** array, int rows, int cols);
#endif // DEBUG_FUNCTIONS_HPP
