#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#define maxv 50
#define maxV 6
struct ArcNode
{
	int adjvex;//�ñߵ��ڽӵ���
	struct ArcNode* nextarc;//ָ����һ���ߵ�ָ��
	int weight;//�ñߵ������Ϣ��Ȩֵ
};//�߽��
struct VNode
{
	int data;//����洢������
	ArcNode* firstarc;//ָ��ö���ĵ�һ����
};//������
struct AdjGraph
{
	VNode adjlist[maxv];//�ڽӱ��ͷ������飬�������λ10��
	int n;//�ڽӱ�����
	int e;//�ڽӱ����
};//�ڽӱ�����
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
	if (queue->front == queue->fear)//����Ϊ�շ���1����Ϊ�շ���0 
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

void initgraph(AdjGraph*& graph, int adjmat[maxV][maxV], int n, int e)//��ʼ�������ڽӾ���
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
	printf("������ٽ��");
	scanf("%d", &n);
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		graph->adjlist[i].data = i + 1;
		graph->adjlist[i].firstarc = NULL;
	}
	printf("����ͼ�����ӷ�ʽ,����1-2������������ͬ�Ľ���˳�����ͼ\n");
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
		printf("����ɹ�\n");
	}
	graph->e = e;
	graph->n = n;
}
/*****ȫ�ֱ���*****/
int k = 0;
int l[maxv] = { 0 };
int  j = 0;
int x[maxv] = { 0 };
/*****��������*****/
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
	printf("ѧ�ţ�202105630443\n�������ż���\n");
	CreaftGraph(graph);
	printf("������ӷ�ʽ\n");
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
	printf("���������������\n");
	while (tempqueue->front != tempqueue->fear)
	{
		printf("%d--", tempqueue->data[tempqueue->front]);
		tempqueue->front++;
	}
	printf("\n");
	initqueue(tempqueue);
	BreadthSearch(graph, 0, tempqueue);
	printf("���������������\n");
	while (tempqueue->front != tempqueue->fear)
	{
		printf("%d--", tempqueue->data[tempqueue->front]);
		tempqueue->front++;
	}
}