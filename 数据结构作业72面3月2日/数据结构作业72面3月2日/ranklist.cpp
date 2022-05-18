#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"list.h"
//#define limit -842150451
void craftlist(struct rankedlist*& list)//创建顺序表
{
	list = (struct rankedlist*)malloc(sizeof(struct rankedlist));
	list->length = 0;
}
void addlistnum(struct rankedlist*& list)//为顺序表添加值
{
	int i = 0;
	for (i; i < maxsize; i++)
	{
		scanf("%d", &list->ranlist[i]);	
		list->length++;
		if (list->ranlist[i] == limit)
		{
			list->length--;
			break;
		}
	}
}
void fun(struct rankedlist*& list)//排序函数
{
	for (int i = 0, temp, n = 0; i < list->length; i++)
	{
		if (list->ranlist[i] < 0)
		{
			temp = list->ranlist[n];
			list->ranlist[n] = list->ranlist[i];
			for (int b = i; b > n + 1; b--)
			{
				list->ranlist[b] = list->ranlist[b - 1];
			}
			list->ranlist[n + 1] = temp;
			n++;
		}
	}
}
void operationranklist()//运行函数
{
	struct rankedlist* a;
	craftlist(a);
	addlistnum(a);
	for (int i = 0; i < a->length; i++)
	{
		printf("%d,", a->ranlist[i]);
	}
	printf("\n");
	fun(a);
	for (int i = 0; i < a->length; i++)
	{
		printf("%d,", a->ranlist[i]);
	}
}