#include <iostream>
#include "Graph.hpp"

namespace ariel
{

    Graph::Graph()
    {
        // Constructor
    }

    Graph::~Graph()
    {
        // Destructor
    }

    void Graph::loadGraph(const std::vector<std::vector<int>> &adjacencyMatrix)
    {
        // Load the graph from the adjacency matrix
        for (unsigned int i = 0; i < adjacencyMatrix.size(); i++)
        {
            if (adjacencyMatrix.size() != adjacencyMatrix[i].size())
            {
                throw std::invalid_argument("Not square");
            }
            for (unsigned int j = 0; j < adjacencyMatrix.size(); j++)
            {
                if (j == i && adjacencyMatrix[i][j] != 0)
                {
                    throw std::invalid_argument("Invalid values");
                }
            }
        }
        this->adjacencyMatrix = adjacencyMatrix;
    }

    void Graph::printGraph() const
    {
        // Print the graph (for debugging purposes)
        std::cout << "Graph with " << adjacencyMatrix.size() << " vertices and " << getNumEdges() << " edges." << std::endl;
        for (unsigned int i = 0; i < (unsigned int)getNumVertices(); i++)
        {
            std::cout << i;
            for (unsigned int j = 0; j < (unsigned int)getNumVertices(); j++)
            {
                if ((i != j) && (adjacencyMatrix[i][j] != 0))
                {
                    std::cout << " -> " << j;
                }
            }
            std::cout << std::endl;
        }
    }

    int Graph::getNumVertices() const
    {
        // Get the number of vertices in the graph
        return adjacencyMatrix.size();
    }

    int Graph::getNumEdges() const
    {
        // Get the number of edges in the graph
        int count = 0;
        for (unsigned int i = 0; i < adjacencyMatrix.size(); ++i)
        {
            for (unsigned int j = 0; j < adjacencyMatrix[i].size(); ++j)
            {
                if (adjacencyMatrix[i][j] != 0)
                {
                    count++;
                }
            }
        }
        return count;
    }

    bool Graph::containsEdge(unsigned int u, unsigned int v) const
    {
        return adjacencyMatrix[u][v] != 0;
    }

    int *Graph::getNeighbors(unsigned int u, int &size) const
    {
        int neighborsCount = 0;
        for (unsigned int i = 0; i < adjacencyMatrix.size(); i++)
        {
            if (containsEdge(u, i))
            {
                neighborsCount++;
            }
        }

        int *neighbors = new int[neighborsCount];
        neighborsCount = 0;
        for (unsigned int i = 0; i < adjacencyMatrix.size(); i++)
        {
            if (containsEdge(u, i))
            {
                neighbors[neighborsCount] = (int)i;
                neighborsCount++;
            }
        }
        size = neighborsCount;
        return neighbors;
    }

    int Graph::getWeight(unsigned int u, unsigned int v) const
    {
        return adjacencyMatrix[u][v];
    }

} // namespace ariel
