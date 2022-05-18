#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main()
{
 int a[6] = { 0,0,0,0,0,0 }, i = 0, j = 0;
    srand((unsigned)time(NULL));   //随机播种
    for (; a[0 ]== 0;)
    {
        a[0]= rand() % 7;
    }
    for (i = 1; i < 6; j = 0, i++)
    {
        a[i] = rand() % 7;
        for (; j <i; )
        {
            if (a[i] == a[j]||a[i]==0)
            {
                a[i] = rand() % 7;
                j = 0;
            }
            else
            {
                j ++;
            }
        }
    }
    printf("黄世标=%d\n", a[0]);
    printf("姚勋文=%d\n", a[1]);
    printf("刘威=%d\n", a[2]);
    printf("帅世利=%d\n", a[3]);
    printf("黄达=%d\n", a[4]);
    printf("张家瑞=%d\n", a[5]);
    return 0;
}
//职位  查找资料 1 2 3 演讲 4 ppt 5 6
