#include<stdio.h>
#include<time.h>
#include <stdlib.h>
int main()
{
	void max(int *a);
	int a[10],i;
	srand((unsigned)time(NULL));
	for (i = 0; i < 10; i++)//随机数生成
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
	for (i = 1; i < 10; i++)//找出最大数，并记录位置
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
	printf("最大的数为%d,位于第%d位", b[0], b[1]);
}