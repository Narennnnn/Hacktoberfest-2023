#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("avx", "avx2", "fma")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long double ld;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 _mt(seed);

struct hash_function
{
    size_t operator()(const pair<int, int> &p) const
    {
        return p.first ^ p.second;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        int c = 0;
        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            if (a - b > 0)
                c++;
        }
        cout << c << endl;
    }
    return 0;
}