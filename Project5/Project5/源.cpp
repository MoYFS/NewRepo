#include<stdio.h>
#include<time.h>
#include <stdlib.h>
int main()
{
	void max(int *a);
	int a[10],i;
	srand((unsigned)time(NULL));
	for (i = 0; i < 10; i++)//���������
	{
		/*scanf_s("%d", &a[i]);*/
		a[i] = rand() % 1000 + 1;
		printf("%d  ", a[i]);
	}
	printf("\n");
	max(a);
}
	void max(int *a)
	{
		int b[2],i;
	b[0] = *a;
	b[1] =1;
	for (i = 1; i < 10; i++)//�ҳ������������¼λ��
	{
		if (b[0] > *(a+i))
		{
	}
		else
		{
			b[0] = *(a+i);
			b[1] = i + 1;
		}
	}
	printf("������Ϊ%d,λ�ڵ�%dλ", b[0], b[1]);
}