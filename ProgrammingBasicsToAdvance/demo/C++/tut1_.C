#include<iostream>
using namespace std;
int sum=5000;
int main(){
    int num1,num2,sum;
    cout<<"Enter the value of num1:\n";            
    cin>>num1;  


    cout<<"Enter the value of num2:\n";            // << ; Insertion operator 
    cin>>num2;                                   // >> ;Extraction operator
    
    sum = num1+num2;

    cout<< " The local sum is "<< sum << endl;       // endl also gives new line
     cout<< "The global sum is "<< :: sum;         // :: is scope resolution operator in order to call global operator
    return 0;
}