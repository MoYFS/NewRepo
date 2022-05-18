#define _CRT_SECURE_NO_WARNINGS
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include"statement.h"

void initqueue(TempQueue*& tempqueue)
{
	tempqueue = (TempQueue*)malloc(sizeof(TempQueue));
	tempqueue->front = tempqueue->fear = 0;
}
bool QueueEmpty(TempQueue* queue)
{
	if (queue->front == queue->fear)//队列为空返回1，不为空返回0 
	{
		return false;
	}
	return true;
}
void DeQueue(TempQueue* queue,int *temp)
{
	*temp = queue->data[queue->front];
	queue->front = (queue->front + 1) % maxv;
	return;
}
void creatqueue(TempQueue*& queue)
{
	queue = (TempQueue*)malloc(sizeof(TempQueue));
	queue->front = queue->fear = 0;
}
void EnterQueue(TempQueue*& queue, int temp)
{
	queue->data[queue->fear] = temp;
	queue->fear++;
}
void initgraph(AdjGraph*& graph, int adjmat[maxV][maxV], int n, int e)//初始化测试邻接矩阵
{
	int i, j;
	ArcNode* temp;
	graph = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (i = 0; i < n; i++)
	{
		graph->adjlist[i].firstarc = NULL;
	}
	for (i = 0; i < n; i++)
	{
		graph->adjlist[i].data = i + 1;
		for (j = 0; j < n; j++)
		{
			if (adjmat[i][j] != 0 && adjmat[i][j] != UINT_MAX)
			{
				temp = (ArcNode*)malloc(sizeof(ArcNode));
				temp->adjvex = j + 1;
				temp->weight = adjmat[i][j];
				temp->nextarc = graph->adjlist[i].firstarc;
				graph->adjlist[i].firstarc = temp;
			}
		}
	}
	graph->n = n;
	graph->e = e;
}
void CreaftGraph(AdjGraph*& graph)//由输入创建图
{
	int n, e = 0;
	int front, fear;
	ArcNode* tempo;
	ArcNode* tempt;
	graph = (AdjGraph*)malloc(sizeof(AdjGraph));
	printf("输入多少结点");
	scanf("%d", &n);
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		graph->adjlist[i].data = i + 1;
		graph->adjlist[i].firstarc = NULL;
	}
	while (true)
	{
		scanf("%d-%d", &front, &fear);
		if (front == fear)
		{
			break;
		}
		tempo = (ArcNode*)malloc(sizeof(ArcNode));
		tempo->adjvex = fear;
		tempo->weight = fear;
		tempo->nextarc = graph->adjlist[front - 1].firstarc;
		graph->adjlist[front - 1].firstarc = tempo;
		tempt = (ArcNode*)malloc(sizeof(ArcNode));
		tempt->adjvex = front;
		tempt->weight = front;
		tempt->nextarc = graph->adjlist[fear - 1].firstarc;
		graph->adjlist[fear - 1].firstarc = tempt;
		e++;
		printf("输入成功\n");
	}
	graph->e = e;
	graph->n = n;
}