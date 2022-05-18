#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
struct link
{
	int dig;
	struct link* next;
};
struct link* craftnode()//创建节点
{
	struct link* head;
	struct link* p1;
	p1 = (struct link*)malloc(sizeof(struct link));
	p1->dig = 1;
	p1->next = NULL;
	head =p1;
	return head;
}
void endadd(struct link* all)//末节点加节点
{
	struct link*a,*b;
	a =b=(struct link*)malloc(sizeof(struct link));
	printf("输入数字\n");
    scanf("%d",&a->dig);
	b = all;
	for (;b->next != NULL;)
	{
		b = b->next;
	}
	b->next = a;
	a->next = NULL;
}
int lennode(struct link* node)//获取节点长度
{
	int n = 0;
	while (node->next!=NULL)
	{
		n++;
		node = node->next;
	}
	return (n+1 );
}
int main()
{
	int i=0;
	struct link* test;
	test = craftnode();
	endadd(test);
	endadd(test);
	i = lennode(test);
	while (i--)
	{
		printf("%d\n", test->dig);
		test = test->next;
	}
}
