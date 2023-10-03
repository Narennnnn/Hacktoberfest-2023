#include <iostream>
#include <vector>

#define INF 99999

void floydWarshall(const std::vector<std::vector<int>> &graph, int V)
{
    std::vector<std::vector<int>> dist(graph);

    // Applying Floyd-Warshall algorithm
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    std::cout << "Shortest distance matrix:" << std::endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
            {
                std::cout << "INF\t";
            }
            else
            {
                std::cout << dist[i][j] << "\t";
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    int V;
    std::cin >> V;

    // Input the graph as an adjacency matrix
    std::vector<std::vector<int>> graph(V, std::vector<int>(V));
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            std::cin >> graph[i][j];
        }
    }

    // Call the Floyd-Warshall function
    floydWarshall(graph, V);

    return 0;
}
