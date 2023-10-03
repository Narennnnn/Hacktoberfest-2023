#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int countInfectedCells(vector<vector<int>> &matrix, int m, int n)
{
    vector<vector<int>> infectedMatrix(matrix); // Create a copy of the matrix
    queue<pair<int, int>> q;

    // Find initial positive cells and add them to the queue
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                q.push(make_pair(i, j));
            }
        }
    }

    int days = 0;
    int infectedCount = q.size();
    while (!q.empty())
    {
        int size = q.size();
        for (int k = 0; k < size; k++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vector<pair<int, int>> neighbors{{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
            for (auto neighbor : neighbors)
            {
                int nx = neighbor.first;
                int ny = neighbor.second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && infectedMatrix[nx][ny] == 0)
                {
                    infectedMatrix[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                    infectedCount++;
                }
            }
        }
        days++;
    }

    return infectedCount;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int infectedCount = countInfectedCells(matrix, m, n);
    int days = infectedCount / 2; // Each day, the infection spreads to neighboring cells

    cout << infectedCount << " " << days << endl;

    return 0;
}
