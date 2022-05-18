#include<stdio.h>
int main()
{
    int max, n;
    int a[10]={0};
    for (n = 0; n <= 9; n++)
    {
        scanf_s("%d",&a[n]);
    }
    max = 0;
    for (n = 0; n <= 9; n++)
    {
        if (max >= a[n])
        {
        }
        else
        {
            max = a[n];
        }
    }
    printf("%d",max );
}
