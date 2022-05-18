#include<stdio.h>
void xuanzhe()
{
	void sort(int arry[], int n);
	int a[10], n = 0;
	for (n = 0; n <= 9; n++)
	{
		scanf_s("%d", &a[n]);
	}
	sort(a, 10);
	for (n = 0; n <= 9; n++)
	{
		printf("%d  ", a[n]);
	}
}
void pl()
{
	void zh(int a[][3]);
	int f[][3] = { {1,2,3},{4,5,6},{7,8,9} }, i = 0, n = 0;
	zh(f);
	for (; i <= 2; i++)
	{
		for (n = 0; n <= 2; n++)
		{
			printf("%d", f[i][n]);
		}
		printf("\n");
	}
}