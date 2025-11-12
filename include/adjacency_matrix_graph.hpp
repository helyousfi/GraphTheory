// adjacency_matrix_graph.hpp
// 
// Implementation of the AdjacencyMatrixGraph class, which represents a graph using an adjacency matrix.
// This class provides methods to add, remove, and check edges, as well as to manipulate and query the graph.
// 
// The AdjacencyMatrixGraph class includes:
// - A constructor to initialize the graph with a given number of vertices.
// - A destructor to properly release dynamically allocated memory.
// - Methods to add and remove edges, check for edge existence, and print the adjacency matrix.
// - Additional utility functions such as multiplying the matrix by -1 for specific algorithms.
//
// This implementation is part of a graph library designed to offer efficient graph operations and algorithms.
// Given the performance requirements, this library is implemented in C++ for better speed and efficiency compared to higher-level languages like Python.

#ifndef GRAPHX_INCLUDE_ADJACENCY_MATRIX_GRAPH_DEFENITION_H_
#define GRAPHX_INCLUDE_ADJACENCY_MATRIX_GRAPH_DEFENITION_H_

#include <vector>
#include <iostream>
#include <unordered_map>
#include "graph.hpp"

namespace graphx {
    template <typename VertexType, typename WeightType = int>
    class AdjacencyMatrixGraph : public Graph<VertexType, WeightType>
    {
    private:
    	std::unordered_map<VertexType, size_t> vertex_indices_; // Map vertex -> index
    	std::vector<VertexType> index_to_vertex_; // TODO
        std::vector<std::vector<std::optional<WeightType>>> matrix_; // Adjacency matrix
        bool directed_; // Indicates if the graph is directed

    public:
        AdjacencyMatrixGraph(size_t n, bool is_directed = false);
        ~AdjacencyMatrixGraph() override = default;
        
        // Core operations
    	void add_vertex(const VertexType& vertex) override;
    	bool remove_vertex(const VertexType& vertex) override;
	
    	void add_edge(const VertexType& u, const VertexType& v, WeightType weight = WeightType{}) override;
    	bool remove_edge(const VertexType& u, const VertexType& v) override;
	
    	// Queries
    	bool has_vertex(const VertexType& vertex) const override;
    	bool has_edge(const VertexType& u, const VertexType& v) const override;
	
    	// Accessors
    	std::vector<VertexType> neighbors(const VertexType& vertex) const override;
    	std::vector<VertexType> vertices() const override;
    	std::vector<std::pair<VertexType, VertexType>> edges() const override;
    	std::optional<WeightType> get_edge_weight(const VertexType& u, const VertexType& v) const override;
    	int degree(const VertexType& vertex) const override;
    	int in_degree(const VertexType& vertex) const override;
    	int out_degree(const VertexType& vertex) const override;
	
    	// Stats
    	size_t vertex_count() const override;
    	size_t edge_count() const override;
    	bool is_directed() const override;
    	bool is_weighted() const override;
	
    	// Utilities
    	void multiply_by_minus_one() override;
    	void clear() override;
    	void print(std::ostream& os = std::cout) const override;
    	bool save_to_file(const std::string& filename) const override;
    	bool load_from_file(const std::string& filename) override;
    };
};
#endif // GRAPHX_INCLUDE_ADJACENCY_MATRIX_GRAPH_DEFENITION_H_

#include "adjacency_matrix_graph.cpp"
