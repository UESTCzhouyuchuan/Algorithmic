#pragma once

#define MAXV 100
#define INF 32767
#define InfoType char 
/**************************
*�ڽӾ�������            * 
**************************/
typedef struct
{	int no;				//������ 
	InfoType info;     //�����������Ϣ 
}VertexType;			//���������
typedef struct {
	int edges[MAXV][MAXV]; //�ڽӾ��� 
	int n,e; //������������ 
	VertexType vexs[MAXV];  //��Ŷ�����Ϣ 
}MatGraph; //������ͼ�ڽӾ������� 
/******************************
*�ڽӱ�����                  * 
******************************/
typedef struct ANode{
	int adjvex; //�ıߵ��ڽӵ���
	struct ANode*nextarc;//ָ����һ���ߵ�ָ�� 
	int weight;//�ıߵ���Ϣ 
}ArcNode; //�߽ڵ������ 
typedef struct Vnode{
	InfoType info; //�����������Ϣ 
	ArcNode *firstarc;//ָ��ĵ�һ���� ע������ͷ��ķ�ʽ 
}VNode; //�ڽӱ��ͷ�������
typedef struct
{
	VNode adjlist[MAXV];//ͷ�ڵ����
	int n,e;//���ͱ��� 
 } AdjGraph; //�������ڽӱ�����
void CreatAdj(AdjGraph *&G,int A[MAXV][MAXV],int e ,int n);
void DispAdj(AdjGraph * G);
void DestroyAdj(AdjGraph * &G);
void MatToList(MatGraph g,AdjGraph *&G);
void ListToMat(AdjGraph * G,MatGraph&g);
/**********************
*ͼ�ı���				* 
***********************/
void DFS(AdjGraph*G,int v,int visited[MAXV]);//�����������
void BFS(AdjGraph*G,int v,int visited[MAXV]);//������ȱ��� 
void DFSl(AdjGraph*G,int v,int visited[MAXV]);//����������� ����ͨͼ 
void BFSl(AdjGraph*G,int v,int visited[MAXV]);//������ȱ��� ����ͨͼ
 /**************************
 *��С������               * 
 ***************************/
 void Prim(MatGraph g,int v);
 void Kruskal(MatGraph g);
 
 /*************************
 *���·��                 * 
 **************************/
 void Dijkstra(MatGraph g);
 void Floyd(MatGraph g);
  
 
