#include<stdio.h>
int main()
{
    int len(int x);
    int z, x, c = 0, i = 0, d = 100, w = 0;
    int n[5] = { 0,0,0,0,0 };
    printf("������һ��5λ�����ڵ���\n");
    scanf_s("%d", &x);
    z = len(x);//��ȡ��λ��
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
        }//��¼ÿλ����ֵ
        switch (z)
        {
        case 1:c = n[0]; break;
        case 2:c = n[0] * 10 + n[1]; break;
        case 3:c = n[0] * 100 + n[1] * 10 + n[2]; break;
        case 4:c = n[0] * 1000 + n[1] * 100 + n[2] * 10 + n[3]; break;
        default:c = n[0] * 10000 + n[1] * 1000 + n[2] * 100 + n[3] * 10 + n[4]; break;
        }//�����ֵ��򲢼�¼
        printf("һ����%dλ��\n", z);
        while (w <= z - 1)
        {
            printf("%d\n", n[w]);
            w++;
        }
        printf("%d", c);
    }
    else
    {
        printf("����λ����������5λ����������");
    }
    return 0;
}
int len(int x)//��ȡ���ֳ���
{
    int i = x, c = 1;
    while (i >= 10)
    {
        i = i / 10;
        c++;
    }
    return(c);
}
