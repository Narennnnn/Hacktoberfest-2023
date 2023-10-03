#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, std::string> longestCommonSubsequence(const std::string &sequence1, const std::string &sequence2)
{
    int m = sequence1.length();
    int n = sequence2.length();

    // Create a 2D table to store the lengths of LCS for subproblems
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Build the dp table in a bottom-up manner
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (sequence1[i - 1] == sequence2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Construct the LCS string from the dp table
    int len = dp[m][n];
    std::string lcs(len, ' ');
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (sequence1[i - 1] == sequence2[j - 1])
        {
            lcs[len - 1] = sequence1[i - 1];
            i--;
            j--;
            len--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return std::make_pair(dp[m][n], lcs);
}

int main()
{
    std::string sequence1, sequence2;
    std::cin >> sequence1 >> sequence2;

    std::pair<int, std::string> result = longestCommonSubsequence(sequence1, sequence2);
    int length = result.first;
    std::string lcs = result.second;

    std::cout << "Length of longest common subsequence: " << length << std::endl;
    std::cout << "Longest common subsequence: " << lcs << std::endl;

    return 0;
}
