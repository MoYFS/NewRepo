#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#define maxv 50
#define maxV 6
struct ArcNode
{
	int adjvex;//该边的邻接点编号
	struct ArcNode* nextarc;//指向下一条边的指针
	int weight;//该边的相关信息，权值
};//边结点
struct VNode
{
	int data;//顶点存储的数据
	ArcNode* firstarc;//指向该顶点的第一条边
};//顶点结点
struct AdjGraph
{
	VNode adjlist[maxv];//邻接表的头结点数组，最大结点数位10个
	int n;//邻接表顶点数
	int e;//邻接表边数
};//邻接表类型
struct TempQueue
{
	int data[maxv];
	int front;
	int fear;
};

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
void DeQueue(TempQueue* queue, int* temp)
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
/***************************TEST****************************/
int adjmat[maxV][maxV] = { {0,2,3,0,0,0},{1,0,0,4,5,0},{1,0,0,0,0,6},{0,2,0,0,5,0},{0,2,0,4,0,6},{0,0,3,0,5,0} };
/*********************main program**************************/

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
void CreaftGraph(AdjGraph*& graph)
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
	printf("输入图的连接方式,例如1-2，输入两个相同的结点退出构建图\n");
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
/*****全局变量*****/
int k = 0;
int l[maxv] = { 0 };
int  j = 0;
int x[maxv] = { 0 };
/*****函数部分*****/
void BreadthSearch(AdjGraph* graph, int i, TempQueue*& tempqueue)
{
	TempQueue* queue;
	creatqueue(queue);
	ArcNode* tempnode;
	tempqueue->data[k] = graph->adjlist[i].data;
	//printf("%d--", graph->adjlist[i].data);
	EnterQueue(queue, i);
	l[i + 1] = 1;
	while (QueueEmpty(queue))
	{
		tempnode = graph->adjlist[i].firstarc;
		DeQueue(queue, &i);
		while (tempnode != NULL)
		{
			if (l[tempnode->adjvex] == 0)
			{
				//printf("%d--", graph->adjlist[tempnode->adjvex-1].data);
				k++;
				tempqueue->data[k] = graph->adjlist[tempnode->adjvex - 1].data;
				l[tempnode->adjvex] = 1;
				EnterQueue(queue, tempnode->adjvex - 1);
			}
			tempnode = tempnode->nextarc;
		}
	}
	tempqueue->fear = k + 1;
}
void DepthSearch(AdjGraph* graph, int i, TempQueue*& tempqueue)
{
	ArcNode* tempnode;
	tempqueue->data[j] = graph->adjlist[i].data;
	tempnode = graph->adjlist[i].firstarc;
	x[i] = 1;
	while (tempnode != NULL)
	{
		if (x[tempnode->adjvex - 1] == 0)
		{
			j++;
			DepthSearch(graph, tempnode->adjvex - 1, tempqueue);
		}
		tempnode = tempnode->nextarc;
	}
	tempqueue->fear = j + 1;
}

int main()
{
	AdjGraph* graph;
	ArcNode* p;
	TempQueue* tempqueue;
	//initgraph(graph, adjmat, 6, 7);
	printf("学号：202105630443\n姓名：张家瑞\n");
	CreaftGraph(graph);
	printf("输出连接方式\n");
	for (int i = 0; i <graph->n; i++)
	{
		printf("%d", graph->adjlist[i].data);
		p = graph->adjlist[i].firstarc;
		while (p != NULL)
		{
			printf("--%d", p->adjvex);
			p = p->nextarc;
		}
		printf("\n");
	}
	initqueue(tempqueue);
	DepthSearch(graph, 0, tempqueue);
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
	while (tempqueue->front != tempqueue->fear)
	{
		printf("%d--", tempqueue->data[tempqueue->front]);
		tempqueue->front++;
	}
}