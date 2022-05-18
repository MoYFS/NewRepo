#pragma once
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
	ArcNode * firstarc;//指向该顶点的第一条边
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
/************Depth-first search traversal graph***********/
void DepthSearch(AdjGraph* graph,int i, TempQueue*& tempqueue);
/***********Breadth-first search traversal graph**********/
void BreadthSearch(AdjGraph* graph, int i, TempQueue*& tempqueue);
/************************通用函数*************************/
void initqueue(TempQueue*& tempqueue);
bool QueueEmpty(TempQueue* queue);
void creatqueue(TempQueue*& queue);
void EnterQueue(TempQueue*& queue, int  temp);
void DeQueue(TempQueue* queue, int* temp);
void initgraph(AdjGraph*& graph, int adjmat[maxV][maxV], int n, int e);//初始化测试邻接矩阵
void CreaftGraph(AdjGraph*& graph);//由输入创建图