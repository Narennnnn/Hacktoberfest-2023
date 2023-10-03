
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int a = 4, b = 56, c = 590;
    cout << "The value of a without setw is  " << a << endl;
    cout << "The value of b without setw is  " << b << endl;
    cout << "The value of c without setw is  " << c << endl;
    cout << "THe value of a is" << setw(4) << a<<endl;
    cout << "THe value of b is" << setw(4) << b<<endl;
    cout << "THe value of c is" << setw(4) << c<<endl;  // setw() function decides width factor
    return 0;
}
  