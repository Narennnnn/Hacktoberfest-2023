#include<stdio.h>
void Main()
{
    int i;
    char t[10];
    printf("Enter String:\t");
    gets(t);
    for(i=0;t[i]!='\0';i++)
    {
        printf("%d",t[i]);
    }
}