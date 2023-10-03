#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int q;
    std::cin >> q;

    while (q--)
    {
        int n;
        std::cin >> n;

        std::vector<std::pair<int, int>> intervals(n);

        for (int j = 0; j < n; j++)
        {
            std::cin >> intervals[j].first >> intervals[j].second;
        }

        std::sort(intervals.begin(), intervals.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b)
                  { return a.second < b.second; });

        int count = 0;
        int prevEnd = -1;

        for (int j = 0; j < n; j++)
        {
            if (intervals[j].first > prevEnd)
            {
                count++;
                prevEnd = intervals[j].second;
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}
