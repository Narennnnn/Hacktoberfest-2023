#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    //for reading input from input.txt
    freopen("input.txt","r",stdin);
    //for writing output on output.txt
    freopen("output.txt","w",stdout);
    #endif

    int n, ans = 0;
    cin >> n;

    while(n--) {
        string s;
        cin >> s;
        if(s[1]=='+')
            ans++;
        else
            ans--;
    }

    cout << ans << endl;
    return 0;
}
