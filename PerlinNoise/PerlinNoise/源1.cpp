#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void PerlinNoise(int a[])//生成随机数
{
    srand((unsigned)time(NULL));
    int i;
    for (i = 0; i <= 25; i++)
    {
        a[i] = (rand()*5/ RAND_MAX);
    }
}
int xxcz(int a, int b, int x)
{
    int c;
    c = (a+b)/2;
    return (c);
}
void yicichazhi(int a[], int b[][2])
{
    int g[26];
    int i = 0, n = -2,m=0;
    for (i = 0; i <= 50; i++)
    {
        n =n+2;
       b[n][0] = a[i];
    }
    PerlinNoise(g);
    for (m = 0, n = -2; n <= 50; m++)
    {
        n = n + 2;
        b[m][1] = g[m];
    }
}
void ercichazhi(int b[][2])
{
    int i;
    for (i = 0; i <48 ; i=i+2)
    {
        b[i + 1][0] = xxcz(b[i][0], b[i + 2][0], i + 1);
    }
    for (i = 0; i < 48; i = i + 2)
    {
        b[i + 1][1] = xxcz(b[i][1], b[i + 2][1], i + 1);
    }
}
void zh(int a[][2], char b[][51])
{
    int i;
    for (i = 0; i <= 50; i++)
    {
        b[20 - a[i][0]][20-a[i][1]] = '*';
    }
}