#include<stdio.h>
int main()
{
    int len(int x);
    int z, x, c = 0, i = 0, d = 100, w = 0;
    int n[5] = { 0,0,0,0,0 };
    printf("请输入一个5位数以内的数\n");
    scanf_s("%d", &x);
    z = len(x);//获取几位数
    if (z <= 5)
    {
        while (i <= (z - 1))
        {
            if (i == 0)
            {
                n[0] = x % 10;
                i++;
            }
            else
            {
                n[i] = (x % d - n[i - 1] * d / 100) / (d / 10);
                d = d * 10;
                i++;
            }
        }//记录每位数的值
        switch (z)
        {
        case 1:c = n[0]; break;
        case 2:c = n[0] * 10 + n[1]; break;
        case 3:c = n[0] * 100 + n[1] * 10 + n[2]; break;
        case 4:c = n[0] * 1000 + n[1] * 100 + n[2] * 10 + n[3]; break;
        default:c = n[0] * 10000 + n[1] * 1000 + n[2] * 100 + n[3] * 10 + n[4]; break;
        }//将数字倒序并记录
        printf("一共有%d位数\n", z);
        while (w <= z - 1)
        {
            printf("%d\n", n[w]);
            w++;
        }
        printf("%d", c);
    }
    else
    {
        printf("超出位数，请输入5位数及以内数");
    }
    return 0;
}
int len(int x)//获取数字长度
{
    int i = x, c = 1;
    while (i >= 10)
    {
        i = i / 10;
        c++;
    }
    return(c);
}
