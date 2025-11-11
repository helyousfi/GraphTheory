namespace graphx {

// Constructor
template <typename VertexType, typename WeightType>
AdjacencyMatrixGraph<VertexType, WeightType>::AdjacencyMatrixGraph(size_t n, bool is_directed)
    : matrix_(n, std::vector<std::optional<WeightType>>(n, std::nullopt)),
      directed_(is_directed)
{
}

// Add vertex
template <typename VertexType, typename WeightType>
void AdjacencyMatrixGraph<VertexType, WeightType>::add_vertex(const VertexType& vertex)
{
    if (vertex_indices_.find(vertex) != vertex_indices_.end())
        return;

    size_t new_index = vertex_indices_.size();
    vertex_indices_[vertex] = new_index;

    for (auto& row : matrix_)
        row.push_back(std::nullopt);

    matrix_.push_back(std::vector<std::optional<WeightType>>(new_index + 1, std::nullopt));
}

// Remove vertex (TODO)
template <typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::remove_vertex(const VertexType& vertex)
{
    return false;
}

// Add edge (TODO)
template <typename VertexType, typename WeightType>
void AdjacencyMatrixGraph<VertexType, WeightType>::add_edge(const VertexType& u, const VertexType& v, WeightType weight)
{
}

// Remove edge (TODO)
template <typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::remove_edge(const VertexType& u, const VertexType& v)
{
    return false;
}

// Queries (TODO)
template <typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::has_vertex(const VertexType& vertex) const
{
    return vertex_indices_.find(vertex) != vertex_indices_.end();
}

template <typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::has_edge(const VertexType& u, const VertexType& v) const
{
    return false;
}

// Accessors (TODO)
template <typename VertexType, typename WeightType>
std::vector<VertexType> AdjacencyMatrixGraph<VertexType, WeightType>::neighbors(const VertexType& vertex) const
{
    return {};
}

template <typename VertexType, typename WeightType>
std::vector<VertexType> AdjacencyMatrixGraph<VertexType, WeightType>::vertices() const
{
    return {};
}

template <typename VertexType, typename WeightType>
std::vector<std::pair<VertexType, VertexType>> AdjacencyMatrixGraph<VertexType, WeightType>::edges() const
{
    return {};
}

template <typename VertexType, typename WeightType>
std::optional<WeightType> AdjacencyMatrixGraph<VertexType, WeightType>::get_edge_weight(const VertexType& u, const VertexType& v) const
{
    return std::nullopt;
}

template <typename VertexType, typename WeightType>
int AdjacencyMatrixGraph<VertexType, WeightType>::degree(const VertexType& vertex) const
{
    return 0;
}

template <typename VertexType, typename WeightType>
int AdjacencyMatrixGraph<VertexType, WeightType>::in_degree(const VertexType& vertex) const
{
    return 0;
}

template <typename VertexType, typename WeightType>
int AdjacencyMatrixGraph<VertexType, WeightType>::out_degree(const VertexType& vertex) const
{
    return 0;
}

// Stats (TODO)
template <typename VertexType, typename WeightType>
size_t AdjacencyMatrixGraph<VertexType, WeightType>::vertex_count() const
{
    return vertex_indices_.size();
}

template <typename VertexType, typename WeightType>
size_t AdjacencyMatrixGraph<VertexType, WeightType>::edge_count() const
{
    return 0;
}

template <typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::is_directed() const
{
    return directed_;
}

template <typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::is_weighted() const
{
    return true;
}

// Utilities (TODO)
template <typename VertexType, typename WeightType>
void AdjacencyMatrixGraph<VertexType, WeightType>::multiply_by_minus_one()
{
}

template <typename VertexType, typename WeightType>
void AdjacencyMatrixGraph<VertexType, WeightType>::clear()
{
}

template <typename VertexType, typename WeightType>
void AdjacencyMatrixGraph<VertexType, WeightType>::print(std::ostream& os) const
{
}

template <typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::save_to_file(const std::string& filename) const
{
    return false;
}

template <typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::load_from_file(const std::string& filename)
{
    return false;
}

} // namespace graphx
