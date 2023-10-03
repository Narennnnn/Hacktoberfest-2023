#include <iostream>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    int maxLength = 0;
    int i = 0, j = 0;
    unordered_set<char> uniqueChars;

    while (i < n && j < n)
    {
        if (uniqueChars.find(s[j]) == uniqueChars.end())
        {
            // Character is unique, expand the window
            uniqueChars.insert(s[j++]);
            maxLength = max(maxLength, j - i);
        }
        else
        {
            // Character is repeating, shrink the window
            uniqueChars.erase(s[i++]);
        }
    }

    return maxLength;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int length = lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << length << endl;

    return 0;
}
