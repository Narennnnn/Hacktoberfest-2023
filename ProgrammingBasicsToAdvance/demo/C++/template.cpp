#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
    
template<class T>
class AddElements
{
    private:
    T a;
    //T b;
    public:
    AddElements(T a);
    T add(T b);
    T concatenate(T b);
    
};
//#define  concatenate add
template<class T>
AddElements<T>::AddElements(T a)
    {
        this->a=a;
    }
    template<class T>
    T AddElements<T>::add(T b)
    {
        return a+b;
    }
    template<class T>
    T AddElements<T>::concatenate(T b)
    {
        return a.append(b);
       //return a+b;
    }
    
int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
