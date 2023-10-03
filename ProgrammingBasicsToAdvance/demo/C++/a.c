#include<stdio.h>
void main()
{
    int a[]={13,15,15,54,35};
    int *j,*k;
    j=a;
    k=a+4;
    j=j*1;
    printf("%d  %d",*j,*k);
    
}
