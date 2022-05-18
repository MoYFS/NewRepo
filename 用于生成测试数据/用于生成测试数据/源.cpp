#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int n;
	printf("需要生成多少测试数据?");
	scanf("%d", &n);
	int* array;
	array = (int*)malloc(sizeof(int) * n);
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % (n * 10);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d,",array[i]);
	}
}
