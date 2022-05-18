#include<stdio.h>
int main()
{
    int a, b;
    a = 1, b = 5;
    while (a <= 10000)
    {
        a = a + 1;
        b = a;
        while (b != 2)
        {
            b = b - 1;
            if (a % b == 0)
                continue;
            else
                if (b == 3)
                    printf(" %d", a);
        }
    }
    printf("%d", b);
}
