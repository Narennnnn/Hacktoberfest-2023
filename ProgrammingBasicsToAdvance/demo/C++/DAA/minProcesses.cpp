#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the minimum number of processors needed
bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.second < p2.second;
}

int findMinProcessors(int n, vector<pair<int, int>> &processes)
{
    // sort(processes.begin(), processes.end(), [](const pair<int, int> &p1, const pair<int, int> &p2)
    //      { return p1.second < p2.second; });
    sort(processes.begin(), processes.end(), comp);
    int minProcessors = 0;
    int currEndTime = -1;

    for (int i = 0; i < n; ++i)
    {
        if (processes[i].first >= currEndTime)
        {
            minProcessors++;
            currEndTime = processes[i].second;
        }
    }

    return minProcessors;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> processes(n);
        for (int i = 0; i < n; ++i)
        {
            int s, e;
            cin >> s >> e;
            processes[i] = make_pair(s, e);
        }

        int minProcessors = findMinProcessors(n, processes);
        cout << minProcessors << endl;
    }

    return 0;
}
/* we can optimize the code further by using an efficient approach known as the "Interval Scheduling" algorithm.
This algorithm is based on the greedy approach and has a time complexity of O(n log n), where n is the number
of processes.


In this optimized code, we sort the processes based on their end times. Then, we iterate through the sorted processes
and greedily select the non-overlapping processes. We increment the minimum number of processors whenever we encounter
 a process whose start time is greater than or equal to the current end time.
This way, we only need to keep track of the current end time and count the number of non-overlapping processes.*/