#ifndef MYMAP_H
#define MYMAP_H 

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
#endif