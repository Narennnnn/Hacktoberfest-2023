#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, x, y;
        cin >> n >> m >> k >> x >> y;
        bool escape = true;
        for (int i = 0; i < k; i++)
        {
            int xi, yi;
            cin >> xi >> yi;
            int dx = abs(x - xi);
            int dy = abs(y - yi);
            if ((dx + dy) % 2 == 0)
            {
                escape = false;
            }
        }
        if (escape)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}