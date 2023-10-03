#include<bits/stdc++.h>

using namespace std;

int main()
 {
 	#ifndef ONLINE_JUDGE
 	//for getting input from input.txt
 	freopen("input.txt","r",stdin);
 	//for writing output on output.txt
 	freopen("output.txt","w",stdout);
 	#endif
    int n,ans=0;
    cin>>n;
    while(n--)
    {
        int a,b,c; 
        cin>>a>>b>>c;
        if(a+b+c>1)
            ans++;
    }
    cout<<ans<<endl;
 }