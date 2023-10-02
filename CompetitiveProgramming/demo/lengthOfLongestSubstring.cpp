#include <bits/stdc++.h>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> dp(n, 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int max_length = 1;
    for (int i = 0; i < n; ++i) {
        max_length = max(max_length, dp[i]);
    }

    return max_length;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int longest_length = lengthOfLIS(nums);
    cout << longest_length << endl;

    return 0;
}
