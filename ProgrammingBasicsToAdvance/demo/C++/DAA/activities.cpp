#include <iostream>
#include <vector>
#include <algorithm>

struct Activity
{
    int start;
    int finish;
};

// Function to compare activities based on their finishing times
bool compareActivities(const Activity &a1, const Activity &a2)
{
    return a1.finish < a2.finish;
}

std::pair<int, std::vector<int>> selectActivities(const std::vector<int> &startTimes, const std::vector<int> &finishTimes)
{
    int n = startTimes.size();
    std::vector<Activity> activities(n);

    // Create activity objects and store them in a vector
    for (int i = 0; i < n; i++)
    {
        activities[i].start = startTimes[i];
        activities[i].finish = finishTimes[i];
    }

    // Sort activities based on finishing times
    std::sort(activities.begin(), activities.end(), compareActivities);

    std::vector<int> selectedActivities;
    int count = 0;
    int lastFinishTime = -1; // Initialize with a value that is less than any start time

    // Iterate through the sorted activities
    for (int i = 0; i < n; i++)
    {
        // If the activity's start time is greater than or equal to the previous activity's finish time, select it
        if (activities[i].start >= lastFinishTime)
        {
            selectedActivities.push_back(i);
            count++;
            lastFinishTime = activities[i].finish;
        }
    }

    return std::make_pair(count, selectedActivities);
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> startTimes(n);
    std::vector<int> finishTimes(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> startTimes[i];
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> finishTimes[i];
    }

    std::pair<int, std::vector<int>> result = selectActivities(startTimes, finishTimes);
    int count = result.first;
    std::vector<int> selectedActivities = result.second;

    std::cout << "Number of non-conflicting activities: " << count << std::endl;
    std::cout << "Selected activities: ";
    for (int i = 0; i < selectedActivities.size(); i++)
    {
        std::cout << selectedActivities[i] + 1 << " ";
    }
    std::cout << std::endl;

    return 0;
}
