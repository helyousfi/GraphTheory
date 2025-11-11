// include/graph/graph.h
#ifndef GRAPHX_INCLUDE_GRAPH_H_
#define GRAPHX_INCLUDE_GRAPH_H_

#include <vector>
#include <stdexcept>

inline constexpr int kDefaultWeight = 1;

// Debug macro
#ifdef _DEBUG
#define DEBUG_LOG(msg) std::cout << "DEBUG: " << msg << std::endl;
#else
#define DEBUG_LOG(msg)
#endif

namespace graphx {
	template <typename NodeType>
    class Graph {
        public: 
            virtual ~Graph() = default;
			
			virtual void add_node(const NodeType& node) = 0;
			virtual bool remove_node(const NodeType& node) = 0;
            virtual void add_edge(const NodeType& node1, const NodeType& node2, int weight = DEFAULT_WEIGHT) = 0;
            virtual bool remove_edge(const NodeType& node1, const NodeType& node2) = 0;
            
            virtual bool has_node(const NodeType& node) = 0;
            virtual bool has_edge(const NodeType& node1, const NodeType& node2) const = 0;

            virtual std::vector<NodeType> get_neighbors(const NodeType& node) const = 0;
            virtual int get_edge_weight(const NodeType& node1, const NodeType& node2) const = 0;
            virtual std::vector<std::vector<int>> get_matrix() const = 0;
            virtual int get_num_vertices() const = 0;
            virtual void print_matrix() const = 0;
            virtual void multiply_by_minus_one() = 0;

            virtual std::vector<std::pair<int, int>> get_edges() const = 0;
            virtual int get_node_count() const = 0;
            virtual int get_edge_count() const = 0;
    };
}
#endif // GRAPHX_INCLUDE_GRAPH_H_
