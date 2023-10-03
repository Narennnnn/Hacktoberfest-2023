// CALL BY REFERENCE

#include<iostream>
using namespace std;
int sum(int &,int &);
int main(){
    int a=10,b=100;
    int s=sum(a,b);
    cout<<"The sum is "<<endl<<s;
    return 0;
}
   int sum(int &x,int &y)
{
    return x+y;
}