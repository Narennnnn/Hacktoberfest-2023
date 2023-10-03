#include <iostream>
using namespace std;

int main() {
	int T,N,X,P;
	cin>>T;
	// N->Questions X-> Correct hai P->minimum marks req to get passed
	for(int i=0;i<T;i++)
	{
	    cin>>N>>X>>P;
	    int res=(3*X)+(-1*abs(N-X));
	    if(res>P || res==P || P!=0)
	    cout<<"PASS"<<endl;
	    else
	    cout<<"FAIL"<<endl;
	}
	
	
	return 0;
}
