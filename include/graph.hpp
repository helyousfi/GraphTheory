// include/graph/graph.h
#ifndef GRAPHX_INCLUDE_GRAPH_H_
#define GRAPHX_INCLUDE_GRAPH_H_

#include <vector>
#include <optional>
#include <stdexcept>
#include <string>
#include <iostream>


inline constexpr int kDefaultWeight = 1;

// Debug macro
#ifdef _DEBUG
#define DEBUG_LOG(msg) std::cout << "DEBUG: " << msg << std::endl;
#else
#define DEBUG_LOG(msg)
#endif

namespace graphx {
	template <typename VertexType, typename WeightType = int>
    class Graph {
        public: 
            virtual ~Graph() = default;
			
			// Core operations
			virtual void add_vertex(const VertexType& vertex) = 0;
			virtual bool remove_vertex(const VertexType& vertex) = 0;
            virtual void add_edge(const VertexType& u, const VertexType& v, WeightType weight = kDefaultWeight) = 0;
            virtual bool remove_edge(const VertexType& u, const VertexType& v) = 0;
            
            // Queries
            virtual bool has_vertex(const VertexType& vertex) const = 0;
            virtual bool has_edge(const VertexType& u, const VertexType& v) const = 0;
			
			// Accessors
            virtual std::vector<VertexType> neighbors(const VertexType& vertex) const = 0;
            virtual std::vector<VertexType> vertices() const = 0;
            virtual std::vector<std::pair<VertexType, VertexType>> edges() const = 0;
            virtual std::optional<WeightType> get_edge_weight(const VertexType& u, const VertexType& v) const = 0;
            virtual int degree(const VertexType& vertex) const = 0;
			virtual int in_degree(const VertexType& vertex) const = 0;
			virtual int out_degree(const VertexType& vertex) const = 0;
			
            // Stats
            virtual size_t vertex_count() const = 0;
            virtual size_t edge_count() const = 0;
            virtual bool is_directed() const = 0;
			virtual bool is_weighted() const = 0;
			
			// Utilities
            virtual void multiply_by_minus_one() = 0;
            virtual void clear() = 0;
			virtual void print(std::ostream& os = std::cout) const = 0;
			virtual bool save_to_file(const std::string& filename) const = 0;
			virtual bool load_from_file(const std::string& filename) = 0;
    };
}
#endif // GRAPHX_INCLUDE_GRAPH_H_
