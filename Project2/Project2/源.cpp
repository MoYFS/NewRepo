#include<stdio.h>

int main()
{
    int n, b, c, d, e;
    b = 3;
    c = 5;
    scanf_s("%d", &n);
    d = n % b;
    e = n % c;
    if ((d == 0) && (e == 0))
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
