#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a,c=0,d=0,n;
    printf("�����뷶Χ");
    scanf_s("%d", &n);
    srand((unsigned)time(NULL));
    a = rand() % n;
    int b;
    printf("guess what the number is(0-9)?\n");
    while (c <= 1)
    {
        scanf_s("%d", &b);
        if (b == a)
        {
            d++;
            printf("congratulations!\n����%d��",d);
            break;
        }
        else
        {
            if (a < b)
            {
                printf("�´���\n");
                d++;
            }
            else
            {
                printf("��С��\n");
                d++;
            }
        }
    }
}
