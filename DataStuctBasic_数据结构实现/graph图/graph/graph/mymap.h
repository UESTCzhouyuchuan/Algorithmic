#ifndef MYMAP_H
#define MYMAP_H 

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
#endif