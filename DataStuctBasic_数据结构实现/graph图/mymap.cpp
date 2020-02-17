#include "mymap.h"
#include <bits/stdc++.h>
using namespace std;
void CreatAdj(AdjGraph*&G,int A[MAXV][MAXV],int e,int n  )
{
	int i,j;ArcNode * p;
	G=new AdjGraph;
	for (i=0;i<n;i++)
	G->adjlist[i].firstarc=NULL;
	for (i=0;i<n;i++)
		for (j=n-1;j>=0;j--)
			if (A[i][j]!=0&&A[i][j]!=INF)
			{
				p=new ArcNode;
				p->adjvex=j;
				p->weight=A[i][j];
				p->nextarc=G->adjlist[i].firstarc;
				G->adjlist[i].firstarc=p;
			}
	G->n=n; G->e=e;
}
void DispAdj(AdjGraph * G)
{
	int i;ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d[%d]->",p->adjvex,p->weight);
			p=p->nextarc;
		}
		printf("\n");
	}
}
void DestroyAdj(AdjGraph * &G)
{
	int i;ArcNode *pre,*p;
	for (i=0;i<G->n;i++)
	{
		pre=G->adjlist[i].firstarc;
		if (pre!=NULL)
		{
			p=pre->nextarc;
			while (p!=NULL)
			{
				free(pre);
				pre=p;p=p->nextarc;
			}
			delete pre;
		}
	}
	delete G;
}
void MatToList(MatGraph g,AdjGraph *&G)
{
	int i,j;
	ArcNode *p;
	G= new AdjGraph;
	for (i=0;i<g.n;i++)
	G->adjlist[i].firstarc=NULL;
	for (i=0;i<g.n;i++)
		for (j=g.n-1;j>=0;j--)
			if (g.edges[i][j]!=0&&g.edges[i][j]!=INF)
			{
				p=new ArcNode;
				p->adjvex=j;p->weight=g.edges[i][j];
				p->nextarc=G->adjlist[i].firstarc;
				G->adjlist[i].firstarc=p;
			}
	G->e=g.e;G->n=g.n;
}
void ListToMat(AdjGraph * G,MatGraph&g)
{
	int i;ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{
			g.edges[i][p->adjvex]=p->weight;
			p=p->nextarc;
		}
	}
	g.n=G->n;g.e=G->e;
}
void DFS(AdjGraph*G,int v,int visited[MAXV])//深度优先搜索
{
	ArcNode*p;
	visited[v]=1;
	printf("%d ",v);
	p=G->adjlist[v].firstarc;
	while (p!=NULL)
	{
		if (visited[p->adjvex]==0)
			DFS(G,p->adjvex,visited);
		p=p->nextarc;
	}
}
void BFS(AdjGraph*G,int v,int visited[MAXV])//广度优先遍历 
{
	int w,i;ArcNode*p;
	queue<int> qu;
	for(i=0;i<G->n;i++)visited[i]=0;
	printf("%2d",v);
	visited[v]=1;
	qu.push(v);
	while (!qu.empty())
	{
		w=qu.front();qu.pop();
		p=G->adjlist[w].firstarc;
		while (p!=NULL)
		{
			if (visited[p->adjvex]==0)
			{
				printf("%2d",p->adjvex);
				visited[p->adjvex]=1;
				qu.push(p->adjvex);
			}
			p=p->nextarc;
		}
	 } 
	 printf("\n");
}

void DFSl(AdjGraph*G,int v,int visited[MAXV])//深度优先搜索 非连通图 
{
 	for (int i=0;i<G->n;i++)
	 if (visited[i]==0)DFS(G,i,visited);	
}
void BFSl(AdjGraph*G,int v,int visited[MAXV])//广度优先搜索 非连通图
{
	for (int i=0;i<G->n;i++)
	 if (visited[i]==0)BFS(G,i,visited);
}
void Prim(MatGraph g,int v)
{
	int lowcost[MAXV];
	int MIN;
	int closest[MAXV],i,j,k;
	for (i=0;i<g.n;i++)
	{
		lowcost[i]=g.edges[v][i];
		closest[i]=v;
	}
	lowcost[v]=0;
	for (i=1;i<g.n;i++)
	{
		MIN=INF;
		for (j=0;j<g.n;j++)
			if (lowcost[j]<MIN)
			{
				MIN=lowcost[j];
				k=j;
			}
		printf("边(%d,%d)权为: %d\n",closest[k],k,MIN);
		lowcost[k]=0;
		for (j=0;j<g.n;j++)
		{
			if (lowcost[j]!=0&&g.edges[k][j]<lowcost[j])
			{
				lowcost[j]=g.edges[k][j];
				closest[j]=k;
			}
		}
	}
}
