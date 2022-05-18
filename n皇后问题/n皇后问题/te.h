#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include<math.h>
#define maxsize 100
typedef struct
{
	int col[maxsize];//存放皇后位置
	int top;
}structcol;
void printfqueen(structcol Queen)//打印皇后位置
{
	static int count = 0;
	printf(" 第%d个解：", ++count);
	for (int i = 1; i <= Queen.top; i++)
		printf("(%d,%d)", i, Queen.col[i]);
	printf("\n");
}
bool judge(structcol Queen, int d, int f)//判断皇后是否符合规则
{
	if (d == 1)
	{
		return true;
	}
	else
	{
		int i;
		for (i = 1; i <= d - 1; i++)
		{
			if (f == Queen.col[i] || abs(f - Queen.col[i]) == abs(i - d))
			{
				return false;
			}
		}
		return true;
	}
}
void queen(int n)//生成皇后
{
	structcol Queen;
	Queen.top = 1;
	Queen.col[0] = 1;
	Queen.col[Queen.top] = 1;
	bool find;
	int k;
	while (Queen.top != 0)
	{
		k = Queen.top;
		find = false;
		for (int j = Queen.col[k]+1; j <= n;j++ )//判定该行是否有可以放置的位置
		{
			if (judge(Queen, k, j))
			{
				Queen.col[Queen.top] = j;
				find = true;
				break;
			}
		}
		if (find)
		{
			if (k == n)
			{
				printfqueen(Queen);
			}
			else
			{
				Queen.top++;
				Queen.col[Queen.top] = 0;
			}
		}
		else
		{
			Queen.top--;
		}
	}
}
