#include <iostream>
#include <string>
using namespace std;

string makeGarlandBeautiful(string garland)
{
    int n = garland.length();
    int count_R = 0, count_G = 0;

    for (char c : garland)
    {
        if (c == 'R')
            count_R++;
        else
            count_G++;
    }

    if (count_R == 0 || count_G == 0)
        return "no";

    if (garland[0] != garland[n - 1])
        return "yes";

    if (count_R % 2 == 1 && count_G % 2 == 0)
        return "no";
    if (count_G % 2 == 1 && count_R % 2 == 0)
        return "no";

    return "yes";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string garland;
        cin >> garland;
        string result = makeGarlandBeautiful(garland);
        cout << result << endl;
    }

    return 0;
}
