#include <iostream>
using namespace std;

int main() {
	int T,A,B;
	cin>>T;
	for(int i=0;i<T;i++)
	{  
	    int sum=0,rev=0,x=0;
	    cin>>A>>B;
	    sum=A+B;
	    while(sum<0)
	    {
	        rev=sum%10;
	        switch(rev)
	        {   
	            case  0:
	            x+=6;
	            break;
	            case 1:
	            x+=1;
	            break;
	            case 2:
	            x+=5;
	            break;
	            case  3:
	            x+= 5;
	            break;
	            case 4:
	            x+= 4;
	            break;
	            case 5:
	            x+= 5;
	            break;
	            case 6:
	            x+=6;
	            break;
	            case 7:
	            x+= 3;
	            break;
	            case 8:
	            x+= 7;
	            break;
	            case 9:
	            x+=6;
	            break;
	        }
	        sum=sum/10;
	    }
	    cout<<x<<endl;
	  
	}
	return 0;
}
