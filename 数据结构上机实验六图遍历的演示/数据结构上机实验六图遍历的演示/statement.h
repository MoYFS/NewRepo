#pragma once
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
	ArcNode * firstarc;//ָ��ö���ĵ�һ����
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
/************Depth-first search traversal graph***********/
void DepthSearch(AdjGraph* graph,int i, TempQueue*& tempqueue);
/***********Breadth-first search traversal graph**********/
void BreadthSearch(AdjGraph* graph, int i, TempQueue*& tempqueue);
/************************ͨ�ú���*************************/
void initqueue(TempQueue*& tempqueue);
bool QueueEmpty(TempQueue* queue);
void creatqueue(TempQueue*& queue);
void EnterQueue(TempQueue*& queue, int  temp);
void DeQueue(TempQueue* queue, int* temp);
void initgraph(AdjGraph*& graph, int adjmat[maxV][maxV], int n, int e);//��ʼ�������ڽӾ���
void CreaftGraph(AdjGraph*& graph);//�����봴��ͼ