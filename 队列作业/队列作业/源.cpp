#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"queue.h"
void initqueue(SqQueue*& queue)
{
	queue = (SqQueue*)malloc(sizeof(SqQueue));
	queue->front = queue->fear = 0;
}
void valuationqueue(SqQueue*& queue)
{
	queue->data[8] = 'a';
	queue->data[9] = 'b';
	queue->data[0] = 'c';
	queue->data[1] = 'd';
	queue->data[2] = 'e';
	queue->data[3] = 'f';
	queue->front = 7;
	queue->fear = 3;
}
void initstack(stack *&temp)
{
	temp = (stack*)malloc(sizeof(stack));
		temp->top = -1;
}
void InvertedOrder(SqQueue*& queue)
{
	int count;
	stack* temp;
	count = maxsize - queue->front + queue->fear - 1;
	initstack(temp);
	for (int i=0; i <= count; i++)
	{
		temp->top++;
		queue->front = (queue->front + 1) % maxsize;
		temp->data[temp->top] = queue->data[queue->front];
	}
	initqueue(queue);
	for (int i = 0; i <= count; i++)
	{
		queue->fear = (queue->fear + 1) % maxsize;
		queue->data[queue->fear] = temp->data[temp->top];
		temp->top--;
	}
	free(temp);
}
void fun()
{
	SqQueue* queue;
	initqueue(queue);
	valuationqueue(queue);
	InvertedOrder(queue);
	for (; queue->front != queue->fear;)
	{
		queue->front = (queue->front + 1) % maxsize;
		printf("%c,", queue->data[queue->front]);
	}
}
//int main()
//{
//	fun();
//}