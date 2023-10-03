#include <iostream>
#include <vector>

using namespace std;

int minMaxPlanks(int n, int k, vector<int> &colors)
{
    int maxPlanks = 0;
    int currPlanks = 0;
    int maxConsecutive = 0;

    for (int i = 1; i <= k; i++)
    {
        currPlanks = 0;

        for (int j = 0; j < n; j++)
        {
            if (colors[j] == i)
            {
                currPlanks++;
            }
            else
            {
                maxPlanks = max(maxPlanks, currPlanks);
                currPlanks = 0;
            }
        }

        maxPlanks = max(maxPlanks, currPlanks);
        maxConsecutive = max(maxConsecutive, maxPlanks);
    }

    if (k == 1)
    {
        return 1;
    }

    return min(maxConsecutive, 2);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> colors(n);
        for (int i = 0; i < n; i++)
        {
            cin >> colors[i];
        }

        int result = minMaxPlanks(n, k, colors);
        cout << result << endl;
    }

    return 0;
}
