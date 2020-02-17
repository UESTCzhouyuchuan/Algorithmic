#pragma once

#define MAXV 100
#define INF 32767
#define InfoType char 
/**************************
*邻接矩阵类型            * 
**************************/
typedef struct
{	int no;				//顶点编号 
	InfoType info;     //顶点的其他信息 
}VertexType;			//顶点的类型
typedef struct {
	int edges[MAXV][MAXV]; //邻接矩阵 
	int n,e; //顶点数，边数 
	VertexType vexs[MAXV];  //存放顶点信息 
}MatGraph; //完整的图邻接矩阵类型 
/******************************
*邻接表类型                  * 
******************************/
typedef struct ANode{
	int adjvex; //改边的邻接点编号
	struct ANode*nextarc;//指向下一条边的指针 
	int weight;//改边的信息 
}ArcNode; //边节点的类型 
typedef struct Vnode{
	InfoType info; //顶点的其他信息 
	ArcNode *firstarc;//指向的第一条边 注：采用头插的方式 
}VNode; //邻接表的头结点类型
typedef struct
{
	VNode adjlist[MAXV];//头节点矩阵
	int n,e;//结点和边数 
 } AdjGraph; //完整的邻接表类型
void CreatAdj(AdjGraph *&G,int A[MAXV][MAXV],int e ,int n);
void DispAdj(AdjGraph * G);
void DestroyAdj(AdjGraph * &G);
void MatToList(MatGraph g,AdjGraph *&G);
void ListToMat(AdjGraph * G,MatGraph&g);
/**********************
*图的遍历				* 
***********************/
void DFS(AdjGraph*G,int v,int visited[MAXV]);//深度优先搜索
void BFS(AdjGraph*G,int v,int visited[MAXV]);//广度优先遍历 
void DFSl(AdjGraph*G,int v,int visited[MAXV]);//深度优先搜索 非连通图 
void BFSl(AdjGraph*G,int v,int visited[MAXV]);//广度优先遍历 非连通图
 /**************************
 *最小生成树               * 
 ***************************/
 void Prim(MatGraph g,int v);
 void Kruskal(MatGraph g);
 
 /*************************
 *最短路径                 * 
 **************************/
 void Dijkstra(MatGraph g);
 void Floyd(MatGraph g);
  
 
