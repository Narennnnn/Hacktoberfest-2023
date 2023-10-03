#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

void printDistinctCharacters(const std::vector<char> &arr)
{
    std::unordered_map<char, int> frequencyMap;

    // Count the frequency of each character
    for (char c : arr)
    {
        frequencyMap[c]++;
    }

    std::vector<char> distinctCharacters;

    // Get the distinct characters in alphabetical order
    for (const auto &pair : frequencyMap)
    {
        distinctCharacters.push_back(pair.first);
    }
    std::sort(distinctCharacters.begin(), distinctCharacters.end());

    // Print the distinct characters and their frequencies
    for (char c : distinctCharacters)
    {
        std::cout << c << ": " << frequencyMap[c] << std::endl;
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<char> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    printDistinctCharacters(arr);

    return 0;
}
