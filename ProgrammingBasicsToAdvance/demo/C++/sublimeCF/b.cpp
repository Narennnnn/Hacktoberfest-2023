#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    //for reading input from input.txt
    freopen("input.txt","r",stdin);
    //for writing output on output.txt
    freopen("output.txt","w",stdout);
    #endif
    int a, b, c;

    cin >> a >> b >> c;
    string s;
    cin >> s;
    cout << a + b + c << "\n";
    cout << s;
    return 0;
}
