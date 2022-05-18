#define _CRT_SECURE_NO_WARNINGS
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include"statement.h"
/*****全局变量*****/
int k = 0;
int l[maxv] = { 0 };
/*****函数部分*****/
void BreadthSearch(AdjGraph* graph, int i, TempQueue*& tempqueue)
{
	TempQueue *queue;
	creatqueue(queue);
	ArcNode* tempnode;
	tempqueue->data[k] = graph->adjlist[i].data;
	//printf("%d--", graph->adjlist[i].data);
	EnterQueue(queue, i);
	l[i+1] = 1;
		while (QueueEmpty(queue))
		{
			tempnode = graph->adjlist[i].firstarc;
			DeQueue(queue, &i);
			while (tempnode!=NULL)
			{
				if (l[tempnode->adjvex]==0)
				{
					//printf("%d--", graph->adjlist[tempnode->adjvex-1].data);
					k++;
					tempqueue->data[k] = graph->adjlist[tempnode->adjvex-1].data;
					l[tempnode->adjvex ] = 1;
					EnterQueue(queue, tempnode->adjvex -1);
				}
				tempnode = tempnode->nextarc;
			}
		}
		tempqueue->fear = k+1 ;
}