#include "mymap.h"
#include <bits/stdc++.h>
void CreatAdj(AdjGraph*&G,int A[MAXV][MAXV],int e,int n)
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


