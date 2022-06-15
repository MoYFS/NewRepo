#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define maxsize 25
#define limit -842150451
struct rankedlist//��������������������������������������������˳���
{
	int ranlist[maxsize];
	int length;
};
void craftlist(struct rankedlist*& list)//����˳���
{
	list = (struct rankedlist*)malloc(sizeof(struct rankedlist));
	list->length = 0;
}
void addlistnum(struct rankedlist*& list)//Ϊ˳������ֵ
{
	int i = 0;
	for (i; i < maxsize; i++)
	{
		scanf("%d", &list->ranlist[i]);
		list->length++;
		if (list->ranlist[i] == limit)//�ж������Ƿ����
		{
			list->length--;
			break;
		}
	}
}
void Print(rankedlist*& a)//�������˳���
{
	for (int i = 0; i < a->length; i++)
		{
			printf("%d,", a->ranlist[i]);
		}
}
int Search(int i, rankedlist *&a)//���ҵ�i��Ԫ�أ�������ֵ
{
	int rt;
		rt = a->ranlist[i - 1];
	return rt;
}
void Insert(rankedlist *&a, int n, int eleminsert)//����һ��ֵ
{
	int temp;
	temp = a->length;
	a->length++;
	if (a->length >= maxsize)
	{
		printf("�޷����룬�Ѵﵽ���洢����");
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
void Delete(rankedlist*& a, int i)//ɾ��
{
	int temp=i-1;
	a->length--;
	for (; temp < a->length; temp++)
	{
		a->ranlist[temp] = a->ranlist[temp + 1];
	}
}
void Sum(rankedlist*& a, int &sum)//���
{
	int i = 0;
	sum = 0;
	for (; i < a->length; i++)
	{
		sum = sum + a->ranlist[i];
	}
}
int  Lookelement(rankedlist*& a, int n)//�����Ƿ����i��������λ��
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
	/*------------�˵�����------------*/
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
		system("cls"); //����
		switch (j)
		{
		case 1:/*���������������Ա�*/
			craftlist(a);
			addlistnum(a);
			Print(a);
			system("pause");
			system("cls");  /*clear screen*/
			break;
		case 2: /*��ӡ�������������Ա�*/
			printf("The original list is:");
			Print(a);
			system("pause");
			system("cls");  /*clear screen*/
			break;
		case 3:/*�����Ա��в��ҵ�i��Ԫ�أ���������ֵ*/
			printf("Input which LNode you want to Search(Input number);");
			getchar();
			scanf("%d", &i);
			if (i > a->length)
			{
				printf("���ҳ�����Χ");
			}
			n = Search(i, a);
			printf("��%d��ֵΪ%d", i, n);
			system("pause");
			system("cls");  /*clear screen*/
			break;
		case 4:/*�����Ա��е�i��Ԫ��֮ǰ����һ��֪Ԫ��*/
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
		case 5:/*�����Ա���ɾ������i��Ԫ��*/
			printf("Please input the elem you want to delete:");
			getchar();
			scanf("%d", &i);
			Delete(a, i);
			Print(a);
			system("pause");
			system("cls");  /*clear screen*/
			break;
		case 6:/*�����Ա�������Ԫ��ֵ��������֮��*/
			Sum(a, sum);
			printf("%d", sum);
			system("pause");
			system("cls");  /*clear screen*/
			break;
		case 7:/*�����Ƿ������i��������λ��*/
			printf("Find the location of the element");
			getchar();
			scanf("%d", &n);
			i = Lookelement(a, n);
			if (i != -1)
			{
				printf("%d�ڵ�%d��", n, i);
			}
			else
			{
				printf("������%d", n);
			}
			system("pause");
			system("cls");  /*clear screen*/
			break;
		case 0:/*�˳�����*/
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