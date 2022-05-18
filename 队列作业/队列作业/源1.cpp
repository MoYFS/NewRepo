#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#define maxqnode 10
typedef struct node
{
	int data;
	struct node* next;
}qnode;
void insert(qnode* quh[], qnode* qut[], int x)//插值
{
	qnode* temp;
	temp = (qnode*)malloc(sizeof(qnode));
	temp->data = x;
	temp->next = NULL;
	if (quh[x] == NULL)
	{
		quh[x] = temp;
		qut[x] = temp;
	}
	else
	{
		quh[x]->next = temp;//接上了
		qut[x] = temp;
	}
}
void creat(qnode* quh[], qnode* qut[])
{
	int n, x, i;
	printf("输入多少数n:");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		do
		{
			printf("输入第%d个数", i + 1);
			scanf("%d", &x);
		} while (x<0||x>10);
		insert(quh, qut, x);
	}
}
void DestroyList(qnode* &head)
{
	qnode* pre = head, * p = pre->next;
	while (p!=NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}
void Displist(qnode*& head)
{
	printf("\n输出所有元素");
		while (head!=NULL)
		{
			printf("%d,", head->data);
			head = head->next;
		}
		printf("\n");
}
qnode* linkqueue(qnode* quh[], qnode* qut[])//连接链队
{
	qnode* head = NULL, * temp1=NULL;
	//temp1 = (qnode*)malloc(sizeof(qnode));
	//temp1->next = NULL;
	int i;
	for (i = 0; i < maxqnode; i++)
	{
		if (quh[i] != NULL)
		{
			if (head == NULL)
			{
				head = quh[i];
				temp1 = qut[i];
			}
			else
			{
				temp1->next = quh[i];
				temp1 = qut[i];
			}
		}
	}
	temp1->next = NULL;
	return head;
}
int main()
{
	int i;
	node* head;
	node* quh[maxqnode], *qut[maxqnode];
	for (i = 0; i < maxqnode; i++)
	{
		quh[i] = qut[i] = NULL;
	}
	creat(quh, qut);
	head = linkqueue(quh, qut);
	Displist(head);
	DestroyList(head);
	return 0;
}