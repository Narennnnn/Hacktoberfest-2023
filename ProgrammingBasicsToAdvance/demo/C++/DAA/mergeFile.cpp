#include <iostream>
#include <vector>
#include <algorithm>

int mergeFiles(std::vector<int> &files)
{
    std::sort(files.begin(), files.end()); // Sort the files in ascending order

    int totalCost = 0;

    while (files.size() > 1)
    {
        int mergedFileSize = files[0] + files[1];
        totalCost += mergedFileSize;

        files.erase(files.begin(), files.begin() + 2); // Remove the first two files

        // Insert the merged file size in the appropriate position to maintain sorted order
        auto it = std::upper_bound(files.begin(), files.end(), mergedFileSize);
        files.insert(it, mergedFileSize);
    }

    return totalCost;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> files(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> files[i];
    }

    int minComputationCost = mergeFiles(files);
    std::cout << "Minimum computation cost: " << minComputationCost << std::endl;

    return 0;
}
