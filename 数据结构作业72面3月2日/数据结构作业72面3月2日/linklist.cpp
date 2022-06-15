 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"list.h"
//#define limit -842150451
struct linklist *craftlink()//��������
{
	struct linklist* link;
	link = (struct linklist*)malloc(sizeof(struct linklist));
	link->next = NULL;
	return link;
}
void addlinklistnode(struct linklist*link)//�������ڵ�
{
	struct linklist* temp,*temp1,*temp2,*temp3;
	temp=temp1=temp2=temp3= (struct linklist*)malloc(sizeof(struct linklist));
	scanf("%d", &link->data);
	temp->data = link->data;
	link->next = NULL;
	//temp2->next = link;//���ã�
	for (;;)
	{
		temp2->data = link->data;
		if (temp2->data != limit)//�ȴ��Ľ�
		{
			temp1 = (struct linklist*)malloc(sizeof(struct linklist));
			scanf("%d", &temp1->data);
			temp2->next = link;
			link->next = temp1;
			temp1->next = NULL;
			link = link->next;
		}	
		else 
		{
			temp3 = temp2->next;
			temp3->next = NULL;
			free(temp2);
			break;
		}
	}
}
int traversallinklist(struct linklist* link)//��������ͳ�ƽڵ���
{
	int count=0;
	for (; link->next != NULL;count++)
	{
		link = link->next;
	}
	return count+1;
}
void invertedorder(struct linklist*& link)//������������ڵ�
{
	struct linklist* head;
	head = link;
	int n=traversallinklist(link)-1;
	int a[maxsize];
	for (int i=0;i<=n;i++)
	{
		a[i] = link->data;
		link = link->next;
	}
	link = head;
	head = link;
	for (; n >= 0; n--)
	{
		link->data = a[n];
		link = link->next;
	}
	link = head;
	head = NULL;
	free(head);
}
void destroylist( struct linklist*& link)//��������
{
	linklist* pre, * p;
	pre = link;
	p = link->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}
void descendingorder(struct linklist*& link)//�ݼ��������
{
	struct linklist* head;
	head = link;
	int n = traversallinklist(link) - 1,i,j,temp;
	int a[maxsize];
	for (int i = 0; i <= n; i++)
	{
		a[i] = link->data;
		link = link->next;
	}
	link = head;
	head = link;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (; n >= 0; n--)
	{
		link->data = a[n];
		link = link->next;
	}
	link = head;
	head = NULL;
	free(head);
}

void ListPrint(struct linklist*& link)//������ӡ����
{
	while (link != NULL)
	{
		printf("%d\n", link->data);
		link = link->next;
	}
}
void operationlinklist()//���������������������к���
{
	struct linklist* list;
	list=craftlink();//������������ ����������������
	addlinklistnode(list);//�������������������ڵ�
    //invertedorder(list);// ������������ڵ㣨12�⣩
	descendingorder(list);//�������ݼ��������(15��)
	ListPrint(list);//������������������������ӡ����
	destroylist(list);//����������������������������
}