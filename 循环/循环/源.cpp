#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main()
{
 int a[6] = { 0,0,0,0,0,0 }, i = 0, j = 0;
    srand((unsigned)time(NULL));   //�������
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
    printf("������=%d\n", a[0]);
    printf("Ҧѫ��=%d\n", a[1]);
    printf("����=%d\n", a[2]);
    printf("˧����=%d\n", a[3]);
    printf("�ƴ�=%d\n", a[4]);
    printf("�ż���=%d\n", a[5]);
    return 0;
}
//ְλ  �������� 1 2 3 �ݽ� 4 ppt 5 6
