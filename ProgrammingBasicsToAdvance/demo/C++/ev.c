#include <stdio.h>
#incl


char reverseString(char* s, int sSize){
    int i,j,l;
    char tmp;
    l=strlen(s);
    for(i=0,j=sSize-1;i<l/2;i++,j--)
    {
        s[i]=tmp;
        s[i]=s[j];
        s[j]=tmp;
    }
    p

}

int main()
{   
    int n;
    printf("Enter limit:\t");
    scanf("%d",&n);
    char str[n];
    printf("Enter string:\t");
    gets(str);
    printf("The reverse of string is %s",reverseString(str,n));
    
    return 0;
}