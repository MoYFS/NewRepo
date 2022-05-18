#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct link
{
	int no;
};
struct linkq
{
	struct link w;
	struct linkq* next;
};
void add(linkq* q,int n)
{
	linkq* temp;
	temp = (linkq*)malloc(sizeof(linkq));
	temp->next = NULL;
	temp->w.no = n;
	q->next = temp;
}
void sort(linkq* head)
{
	linkq* pre, * p, * tail, * temp;
	tail = NULL;
	pre = head;
	while ((head->next->next) != tail)
	{
		p = head->next;
		pre = head;
		while (p->next != tail)
		{
			if ((p->w.no) > (p->next->w.no))
			{
				pre->next = p->next;
				temp = p->next->next;
				p->next->next = p;
				p->next = temp;
				p = pre->next;  //p回退一个节点 
			}
			p = p->next;  //p再前进一个节点 
			pre = pre->next;
		}
		tail = p;
	}
}
int main()
{
	 struct linkq *q,*head;
	 q = (linkq*)malloc(sizeof(linkq));
	 head = q;
	 int a[10] = { 5,32,23,7,2,24,342,86,43,47 };
	for (int n = 0; n < 10; n++)
	{
		add(q, a[n]);
		q = q->next;
	}
	sort(head);
	while (head!=NULL)
	{
		printf("%d\n", head->next->w.no);
		head = head->next;
	}
}
