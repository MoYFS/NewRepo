﻿#include<stdio.h>
#include<math.h>
int main()
{
	int x,y;
	printf("请输入x");
	scanf_s("%d", &x);
	if (x < 1)
	{
		y = x;
	}
	else 
	{
		if (1 <= x < 10)
		{
			y = 2 * x - 1;
		}
		else
		{
			y = 3 * x - 11;
		}
	}
	printf("y=%d", y);
	return 0;
}
