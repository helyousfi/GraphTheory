#ifdef EXCLUDE_THIS_FILE
// Edge List representation of a graph
class EdgeListGraph {
private:
    // Structure to represent an edge in the edge list
    struct Edge {
        int u;       // Source vertex of the edge
        int v;       // Destination vertex of the edge
        int weight;  // Weight of the edge (if weighted)
    };

    std::vector<Edge> edges;   // Vector to store all edges in the graph
    int numVertices;           // Number of vertices in the graph

public:
    // Constructor to initialize the graph with n vertices
    EdgeListGraph(int n);

    // Function to add an edge from vertex u to vertex v with weight w (for weighted graphs)
    void addEdge(int u, int v, int w);

    // Function to add an edge from vertex u to vertex v (for unweighted graphs)
    void addEdge(int u, int v);

    // Function to remove an edge from vertex u to vertex v
    void removeEdge(int u, int v);

    // Function to check if there is an edge from vertex u to vertex v
    bool hasEdge(int u, int v);
};
#else
#endif