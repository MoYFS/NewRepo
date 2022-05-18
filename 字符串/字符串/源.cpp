#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int len(int x);
    int a = 1, d = 0;
    while (a <= 10000)
    {
        printf("%d", a);
        printf(" ");
        d = d + len(a);
        a++;
    }
    printf("\n%s%d%s","Ò»¹²", d,"Î»");
}
int len(int x)
{
    int i = x, c=1;
    while (i >= 10)
    {
        i = i / 10;
        c++;
    }
    return(c);
}