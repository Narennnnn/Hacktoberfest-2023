#include <iostream>
#include <vector>

struct Item
{
    int weight;
    int value;
};

std::pair<int, std::vector<int>> knapsack(const std::vector<int> &weights, const std::vector<int> &values, int capacity)
{
    int n = weights.size();

    // Create a 2D table to store the maximum value that can be achieved for subproblems
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));

    // Build the dp table in a bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            // If the current item's weight is less than or equal to the capacity, we have two choices:
            // 1. Include the item and add its value to the maximum value achieved by considering the remaining capacity
            // 2. Exclude the item and consider the maximum value achieved without it
            if (weights[i - 1] <= j)
            {
                dp[i][j] = std::max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int maxValue = dp[n][capacity];

    // Backtrack to find the list of selected items
    std::vector<int> selectedItems;
    int i = n, j = capacity;
    while (i > 0 && j > 0)
    {
        // If the current item was included in the optimal solution, add its index to the list
        if (dp[i][j] != dp[i - 1][j])
        {
            selectedItems.push_back(i - 1);
            j -= weights[i - 1];
        }
        i--;
    }

    return std::make_pair(maxValue, selectedItems);
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> weights(n);
    std::vector<int> values(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> values[i];
    }

    int capacity;
    std::cin >> capacity;

    std::pair<int, std::vector<int>> result = knapsack(weights, values, capacity);
    int maxValue = result.first;
    std::vector<int> selectedItems = result.second;

    std::cout << "Maximum value: " << maxValue << std::endl;
    std::cout << "Selected items: " << std::endl;
    for (int i = 0; i < selectedItems.size(); i++)
    {
        int index = selectedItems[i];
        std::cout << "Item " << index + 1 << ": Weight = " << weights[index] << ", Value = " << values[index] << std::endl;
    }

    return 0;
}
