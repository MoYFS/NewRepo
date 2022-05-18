#include <stdio.h>
int main()
{
    char a = 'sd', b = 'ws';
    b = a;
    a = b;
    printf("a=%d b=%d\n", a, b);
    return 0;
}
