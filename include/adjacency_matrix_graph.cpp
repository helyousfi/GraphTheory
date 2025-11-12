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
	index_to_vertex_.push_back(vertex);
	
    for (auto& row : matrix_)
        row.push_back(std::nullopt);

    matrix_.push_back(std::vector<std::optional<WeightType>>(new_index + 1, std::nullopt));
}

// Remove vertex
template <typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::remove_vertex(const VertexType& vertex)
{
	auto it = vertex_indices_.find(vertex);
    if (it == vertex_indices_.end())
        return false; 
    size_t idx = it->second;
    vertex_indices_.erase(it);
    matrix_.erase(matrix_.begin() + idx);
    for (auto& row : matrix_) {
        row.erase(row.begin() + idx);
    }
    for (auto& [v, i] : vertex_indices_) {
        if (i > idx)
            --i;
    }
    index_to_vertex_.erase(index_to_vertex_.begin() + idx);
    return true;
}

// Add edge
template <typename VertexType, typename WeightType>
void AdjacencyMatrixGraph<VertexType, WeightType>::add_edge(const VertexType& u, const VertexType& v, WeightType weight)
{
	auto it_u = vertex_indices_.find(u);
	auto it_v = vertex_indices_.find(v);
	if (it_u == vertex_indices_.end() || it_v == vertex_indices_.end())
        return;
    size_t idx_u = it_u->second;   
    size_t idx_v = it_v->second;
    
    matrix_[idx_u][idx_v] = weight;
    
    if (!directed_) {
        matrix_[idx_v][idx_u] = weight;
    }
}

// Remove edge
template <typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::remove_edge(const VertexType& u, const VertexType& v)
{
	auto it_u = vertex_indices_.find(u);
	auto it_v = vertex_indices_.find(v);
	if (it_u == vertex_indices_.end() || it_v == vertex_indices_.end())
        return false;
    size_t idx_u = it_u->second; 
    size_t idx_v = it_v->second; 
    if(!matrix_[idx_u][idx_v].has_value()) {
    	return false;
    }
    matrix_[idx_u][idx_v] = std::nullopt;
    if (!directed_) {
        matrix_[idx_v][idx_u] = std::nullopt;
    }
    return true;
}

// Queries
template <typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::has_vertex(const VertexType& vertex) const
{
    return vertex_indices_.find(vertex) != vertex_indices_.end();
}

template <typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::has_edge(const VertexType& u, const VertexType& v) const
{
	auto it_u = vertex_indices_.find(u);
	auto it_v = vertex_indices_.find(v);
	if (it_u == vertex_indices_.end() || it_v == vertex_indices_.end())
        return false;
    size_t idx_u = it_u->second; 
    size_t idx_v = it_v->second; 
    if(!matrix_[idx_u][idx_v].has_value()) {
    	return false;
    }
    return true;
}

// Accessors
template <typename VertexType, typename WeightType>
std::vector<VertexType> AdjacencyMatrixGraph<VertexType, WeightType>::neighbors(const VertexType& vertex) const
{
    auto it = vertex_indices_.find(vertex);
    if (it == vertex_indices_.end())
        return {};

    size_t idx = it->second;
    std::vector<VertexType> result;

    for (const auto& [v, j] : vertex_indices_) {
        if (matrix_[idx][j].has_value())
            result.push_back(v);
    }

    return result;
}


template <typename VertexType, typename WeightType>
std::vector<VertexType> AdjacencyMatrixGraph<VertexType, WeightType>::vertices() const
{
	std::vector<VertexType> result;
	result.reserve(vertex_indices_.size()); // optimization: avoid reallocations
    for (const auto& [v, _] : vertex_indices_) {
    	result.push_back(v);
    }
    return result;
}

template <typename VertexType, typename WeightType>
std::vector<std::pair<VertexType, VertexType>> 
AdjacencyMatrixGraph<VertexType, WeightType>::edges() const
{
    std::vector<std::pair<VertexType, VertexType>> result;
    // Iterate over adjacency matrix
    for (size_t i = 0; i < matrix_.size(); ++i) {
        for (size_t j = 0; j < matrix_[i].size(); ++j) {
            if (matrix_[i][j].has_value()) { // edge exists
                result.emplace_back(index_to_vertex_[i], index_to_vertex_[j]);
            }
        }
    }
    return result;
}


template <typename VertexType, typename WeightType>
std::optional<WeightType> AdjacencyMatrixGraph<VertexType, WeightType>::get_edge_weight(const VertexType& u, const VertexType& v) const
{
	auto it_u = vertex_indices_.find(u);
	auto it_v = vertex_indices_.find(v);
	if (it_u == vertex_indices_.end() || it_v == vertex_indices_.end())
        return std::nullopt;
    size_t idx_u = it_u->second; 
    size_t idx_v = it_v->second; 
	if (idx_u >= matrix_.size() || idx_v >= matrix_[idx_u].size())
        return std::nullopt;
    return matrix_[idx_u][idx_v];
}

template <typename VertexType, typename WeightType>
int AdjacencyMatrixGraph<VertexType, WeightType>::degree(const VertexType& vertex) const
{
	if (vertex_indices_.find(vertex) == vertex_indices_.end())
        return 0;
	size_t count = out_degree(vertex) + in_degree(vertex);
	return directed_? static_cast<int>(count) : static_cast<int>(count/2);
}

template <typename VertexType, typename WeightType>
int AdjacencyMatrixGraph<VertexType, WeightType>::in_degree(const VertexType& vertex) const
{
	auto it_vertex = vertex_indices_.find(vertex);
	if(it_vertex == vertex_indices_.end())
		return 0;
	size_t idx_vertex = it_vertex->second; 
	size_t in_degree = 0;
	for (const auto& row : matrix_) {
		if(row[idx_vertex].has_value()) ++in_degree;		
	}
    return in_degree;
}

template <typename VertexType, typename WeightType>
int AdjacencyMatrixGraph<VertexType, WeightType>::out_degree(const VertexType& vertex) const
{
	auto it_vertex = vertex_indices_.find(vertex);
	if(it_vertex == vertex_indices_.end())
		return 0;
	size_t idx_vertex = it_vertex->second; 
	size_t out_degree = 0;
	for (const auto& edge : matrix_[idx_vertex]) {
		if(edge.has_value()) ++out_degree;		
	}
    return out_degree;
}

// Stats
template <typename VertexType, typename WeightType>
size_t AdjacencyMatrixGraph<VertexType, WeightType>::vertex_count() const
{
    return vertex_indices_.size();
}

template <typename VertexType, typename WeightType>
size_t AdjacencyMatrixGraph<VertexType, WeightType>::edge_count() const
{
    size_t count = 0;
    for (const auto& row : matrix_) {
        for (const auto& cell : row) {
            if (cell.has_value()) {
                ++count;
            }
        }
    }
    if (!directed_) {
        count /= 2;
    }

    return count;
}


template <typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::is_directed() const
{
    return directed_;
}

template <typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::is_weighted() const
{
    return !std::is_same_v<WeightType, bool> && !std::is_same_v<WeightType, void>;
}

// Utilities
template <typename VertexType, typename WeightType>
void AdjacencyMatrixGraph<VertexType, WeightType>::multiply_by_minus_one()
{
	static_assert(std::is_arithmetic_v<WeightType>, "multiply_by_minus_one() requires a numeric WeightType");
    for (auto& row : matrix_) {
        for (auto& cell : row) {
            if (cell.has_value()) {
                cell = -(*cell);
            }
        }
    }
}

template <typename VertexType, typename WeightType>
void AdjacencyMatrixGraph<VertexType, WeightType>::clear()
{
    vertex_indices_.clear();               
    matrix_.clear();                       
}


template <typename VertexType, typename WeightType>
void AdjacencyMatrixGraph<VertexType, WeightType>::print(std::ostream& os) const
{
	os << "Vertex Indices:\n";
	for (const auto& [vertex, index] : vertex_indices_)
	{
		os << vertex << ":" << index << "  ";
	}
    os << "\nAdjacency Matrix:\n";
    size_t idx_u = 0, idx_v = 0;
    for (const auto& row : matrix_) {
        for (const auto& cell : row) {
            if (cell.has_value())
                os << *cell << " ";
            else
                os << ". ";
        }
        os << "\n";
    }
}


template <typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::save_to_file(const std::string& filename) const
{
    std::ofstream out(filename);
    if (!out.is_open())
        return false;

    out << vertex_indices_.size() << " " << directed_ << "\n";

    for (const auto& row : matrix_) {
        for (const auto& cell : row) {
            if (cell)
                out << *cell << " ";
            else
                out << "null ";
        }
        out << "\n";
    }

    out.close();
    return true;
}

template <typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::load_from_file(const std::string& filename)
{
    std::ifstream in(filename);
    if (!in.is_open())
        return false;

    size_t n;
    in >> n >> directed_;

    clear(); 

    matrix_.resize(n, std::vector<std::optional<WeightType>>(n, std::nullopt));
    vertex_indices_.clear();
    for (size_t i = 0; i < n; ++i)
        vertex_indices_[VertexType{}] = i;

    std::string token;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            in >> token;
            if (token != "null")
                matrix_[i][j] = static_cast<WeightType>(std::stod(token));
        }
    }

    in.close();
    return true;
}


} // namespace graphx
