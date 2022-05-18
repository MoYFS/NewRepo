#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define maxsize 25
#define limit -842150451
struct rankedlist//······················顺序表
{
	int ranlist[maxsize];
	int length;
};
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
		if (list->ranlist[i] == limit)//判断输入是否结束
		{
			list->length--;
			break;
		}
	}
}
void Print(rankedlist*& a)//遍历输出顺序表
{
	for (int i = 0; i < a->length; i++)
		{
			printf("%d,", a->ranlist[i]);
		}
}
int Search(int i, rankedlist *&a)//查找第i个元素，并返回值
{
	int rt;
		rt = a->ranlist[i - 1];
	return rt;
}
void Insert(rankedlist *&a, int n, int eleminsert)//插入一个值
{
	int temp;
	temp = a->length;
	a->length++;
	if (a->length >= maxsize)
	{
		printf("无法插入，已达到最大存储极限");
		return;
	}
	else
	{
		for (; temp >=n; temp--)
		{
			a->ranlist[temp]=a->ranlist[temp-1];
		}
		a->ranlist[n] = eleminsert;
		return;
	}
}
void Delete(rankedlist*& a, int i)//删除
{
	int temp=i-1;
	a->length--;
	for (; temp < a->length; temp++)
	{
		a->ranlist[temp] = a->ranlist[temp + 1];
	}
}
void Sum(rankedlist*& a, int &sum)//求和
{
	int i = 0;
	sum = 0;
	for (; i < a->length; i++)
	{
		sum = sum + a->ranlist[i];
	}
}
int  Lookelement(rankedlist*& a, int n)//查找是否存在i，并返回位置
{
	int i=-1;
	for (int temp = 0; temp < a->length; temp++)
	{
		if (a->ranlist[temp] == n)
		{
			i = temp + 1;
			return i;
		}
	}
	return i;
}
void menu(rankedlist*& a)
{
	int j, i = -1, n = 0, eleminsert = 0, sum = 0;
	/*------------菜单函数------------*/
	while (1)
	{
		printf(" ********************MENU * ***********************\n\n");
		printf("Create a new int list :...................press 1\n\n");
		printf("Print the whole`list :....................press 2\n\n");
		printf("Search by order :.........................press 3\n\n");
		printf("Insert the elem in the place i:...........press 4\n\n");
		printf("Delete the elem by order :................press 5\n\n");
		printf("Sum all elem in the list :................press 6\n\n");
		printf("Find the location of the element :........press 7\n\n");
		printf("exit the programe :.......................press 0\n\n");
		printf(" ***********************END*******************\n\n");
		printf("Please choose the number from (0~7).....");
		getchar();
		do
		{
			scanf("%d", &j);
			printf("Error! Please choose again......");
		} while (j < 0 || j>8);
		printf("\n\tYou choose the number %d\n ", j);
		printf("\n\tPress any key to continue.....");
		system("cls"); //清屏
		switch (j)
		{
		case 1:/*创建任意整数线性表*/
			craftlist(a);
			addlistnum(a);
			Print(a);
			system("pause");
			system("cls");  /*clear screen*/
			break;
		case 2: /*打印（遍历）该线性表*/
			printf("The original list is:");
			Print(a);
			system("pause");
			system("cls");  /*clear screen*/
			break;
		case 3:/*在线性表中查找第i个元素，并返回其值*/
			printf("Input which LNode you want to Search(Input number);");
			getchar();
			scanf("%d", &i);
			if (i > a->length)
			{
				printf("查找超出范围");
			}
			n = Search(i, a);
			printf("第%d的值为%d", i, n);
			system("pause");
			system("cls");  /*clear screen*/
			break;
		case 4:/*在线性表中第i个元素之前插入一已知元素*/
			printf("Please input the elem's place where you want");
			getchar();
			scanf("%d", &n);
			printf("lnput the elem which you want to insert:");
			getchar();
			scanf("%d", &eleminsert);
			Insert(a, n, eleminsert);
			Print(a);
			system("pause");
			system("cls");  /*clear screen*/
			break;
		case 5:/*在线性表中删除除第i个元素*/
			printf("Please input the elem you want to delete:");
			getchar();
			scanf("%d", &i);
			Delete(a, i);
			Print(a);
			system("pause");
			system("cls");  /*clear screen*/
			break;
		case 6:/*求线性表中所有元素值（整数）之和*/
			Sum(a, sum);
			printf("%d", sum);
			system("pause");
			system("cls");  /*clear screen*/
			break;
		case 7:/*查找是否存在数i并购返回位置*/
			printf("Find the location of the element");
			getchar();
			scanf("%d", &n);
			i = Lookelement(a, n);
			if (i != -1)
			{
				printf("%d在第%d个", n, i);
			}
			else
			{
				printf("不存在%d", n);
			}
			system("pause");
			system("cls");  /*clear screen*/
			break;
		case 0:/*退出程序*/
			printf("Press any key to continue.....");
			exit(0);
		}
	}
}
int main()
{
	rankedlist* a;
	menu(a);
	return 0;
}