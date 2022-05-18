#include<stdio.h>
int main()
{
	int ts(int a[]);
	int a[3];
	printf("输入年，月，日\n");
	scanf_s("%d,%d,%d", &a[0], &a[1], &a[2]);
	if (ts(a) == 0)//判读所输入数据是否有误
	{
		printf("数据有误");
	}
	else
	{
		printf("一共%d天", ts(a));
	}
}
int yn(int a[])
{
	int year = a[0];
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int ts(int a[])
{
	int i;
	int z = 0;
	int b[][12] = { {31,29,31,30,31,30,31,31,30,31,30,31},{31,28,31,30,31,30,31,31,30,31,30,31} };
	for (i = 0; i <= a[1] - 2; i++)
	{
		z = z + b[yn(a)][i];
	}
	if (a[2] > b[yn(a)][a[1] - 1])
	{
		z = 0;
	}
	else
	{
		z = z + a[2];
	}
	return z;
}
