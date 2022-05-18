#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include"statement.h"
/***************************TEST****************************/
int adjmat[maxV][maxV] = { {0,2,3,0,0,0},{1,0,0,4,5,0},{1,0,0,0,0,6},{0,2,0,0,5,0},{0,2,0,4,0,6},{0,0,3,0,5,0} };
/*********************main program**************************/
int main()
{
	AdjGraph* graph;
	ArcNode* p;
	TempQueue* tempqueue;
	printf("学号：202105630443\n姓名：张家瑞\n");
	//initgraph(graph, adjmat, 6, 7);
	CreaftGraph(graph);
	printf("输出连接方式\n");
	for (int i=0;i<graph->n;i++)
	{
		printf("%d", graph->adjlist[i].data);
		p = graph->adjlist[i].firstarc;
		while (p!=NULL)
		{
			printf("--%d", p->adjvex);
			p = p->nextarc;
		}
		printf("\n");
	}
	initqueue(tempqueue);
	DepthSearch(graph,0, tempqueue);
	printf("深度优先搜索遍历\n");
	while (tempqueue->front != tempqueue->fear)
	{
		printf("%d--", tempqueue->data[tempqueue->front]);
		tempqueue->front++;
	}
	printf("\n");
	initqueue(tempqueue);
	BreadthSearch(graph, 0, tempqueue);
	printf("广度优先搜索遍历\n");
	while (tempqueue->front!=tempqueue->fear)
	{
		printf("%d--", tempqueue->data[tempqueue->front]);
		tempqueue->front++;
	}
}