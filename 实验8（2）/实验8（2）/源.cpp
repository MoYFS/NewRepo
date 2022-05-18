#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* exchange(int* a, int m);
	int b[10], m, i;
	printf("输入数字（10个数）\n");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &b[i]);
	}
	printf("移动位数（小于10）\n");
	scanf_s("%d", &m);
	int* n = exchange(b, m);
	for (i = 0; i < 10; i++)
	{
		printf("%d,", *(n + i));
	}
	return 0;
}
int* exchange(int* a, int m)
{
	int* temp = (int*)malloc(sizeof(int) * m);
	int i;
	for (i = 0; i < m; i++)
	{
		*(temp + i) = *(a + i);
	}
	for (i = 0; i < 10 - m; i++)
	{
		*(a + i) = *(a + m + i);
	}
	for (i =0; i <m; i++)
	{
		*(a + 10-m + i) = *(temp + i);
	}
	free(temp);
	return a;
}