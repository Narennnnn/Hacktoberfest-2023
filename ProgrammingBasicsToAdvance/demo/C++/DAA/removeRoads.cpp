#include <iostream>
#include <vector>

using namespace std;

// Union-Find data structure for finding connected components
class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (x != parent[x])
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

// Function to calculate the minimum number of roads to destroy
int calculateMinRoads(int n, int p, const vector<pair<int, int>> &edges)
{
    UnionFind uf(n + 1);

    for (const auto &edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        uf.unite(u, v);
    }

    int connectedComponents = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (uf.find(i) == i)
        {
            connectedComponents++;
        }
    }

    int minRoads = p - (n - connectedComponents);
    return minRoads;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, p;
        cin >> n >> p;

        vector<pair<int, int>> edges(p);
        for (int i = 0; i < p; ++i)
        {
            int u, v;
            cin >> u >> v;
            edges[i] = make_pair(u, v);
        }

        int minRoads = calculateMinRoads(n, p, edges);
        cout << minRoads << endl;
    }

    return 0;
}
/*
   1
5 8
1 2
 1 5
 2 4
 2 3
 3 1
 4 3
 5 2
 5 1*/
/*4*/