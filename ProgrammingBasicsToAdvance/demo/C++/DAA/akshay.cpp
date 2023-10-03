#include <iostream>
#include <vector>
#include <set>
#include <limits> // Include the <limits> header for INT_MAX

const int INF = std::numeric_limits<int>::max(); // Use std::numeric_limits to get INT_MAX

void dijkstra(const std::vector<std::vector<int>> &graph, int source)
{
    int V = graph.size();

    std::vector<int> distance(V, INF);
    std::vector<int> path(V, -1);
    std::set<std::pair<int, int>> visitedSet;

    distance[source] = 0;
    visitedSet.insert(std::make_pair(0, source));

    while (!visitedSet.empty())
    {
        int u = visitedSet.begin()->second;
        visitedSet.erase(visitedSet.begin());

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && distance[u] != INF && distance[u] + graph[u][v] < distance[v])
            {
                visitedSet.erase(std::make_pair(distance[v], v));
                distance[v] = distance[u] + graph[u][v];
                path[v] = u;
                visitedSet.insert(std::make_pair(distance[v], v));
            }
        }
    }

    // Print shortest path and distance from each friend's location to Akshay's house
    for (int i = 0; i < V; i++)
    {
        if (i != source)
        {
            std::cout << i + 1;
            int curr = path[i];
            while (curr != -1)
            {
                std::cout << " " << curr + 1;
                curr = path[curr];
            }
            std::cout << " : " << distance[i] << std::endl;
        }
    }
}

int main()
{
    int V;
    std::cin >> V;

    std::vector<std::vector<int>> graph(V, std::vector<int>(V));
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            std::cin >> graph[i][j];
        }
    }

    int source;
    std::cin >> source;

    dijkstra(graph, source - 1);

    return 0;
}
