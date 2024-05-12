#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

namespace ariel
{

    class Graph
    {
    private:
        std::vector<std::vector<int>> adjacencyMatrix;

    public:
        Graph();
        ~Graph();

        // Load the graph from the adjacency matrix
        void loadGraph(const std::vector<std::vector<int>> &adjacencyMatrix);

        // Print the graph (for debugging purposes)
        void printGraph() const;

        // Get the number of vertices in the graph
        int getNumVertices() const;

        // Get the number of edges in the graph
        int getNumEdges() const;

        // Check if there is an edge from u to v
        bool containsEdge(unsigned int u, unsigned int v) const;

        // return array of neighbors
        int *getNeighbors(unsigned int u, int &size) const;

        // return the weight between u and v
        int getWeight(unsigned int u, unsigned int v) const;
    };

} // namespace ariel

#endif // GRAPH_HPP
