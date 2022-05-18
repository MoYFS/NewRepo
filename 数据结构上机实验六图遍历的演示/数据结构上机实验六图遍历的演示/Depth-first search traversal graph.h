#define _CRT_SECURE_NO_WARNINGS
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include"statement.h"
/*全局变量定义*/ 
int  j= 0;
int x[maxv] = {0};
/*函数部分*/
void DepthSearch(AdjGraph *graph,int i,TempQueue * &tempqueue)
{
	ArcNode* tempnode;
	tempqueue->data[j] = graph->adjlist[i].data;
	tempnode = graph->adjlist[i].firstarc;
	x[i] = 1;
	while (tempnode!=NULL)
	{
		if (x[tempnode->adjvex -1] == 0)
		{
			j++;
			DepthSearch(graph, tempnode->adjvex -1, tempqueue);
		}
		tempnode = tempnode->nextarc;
	}
	tempqueue->fear = j + 1;
}