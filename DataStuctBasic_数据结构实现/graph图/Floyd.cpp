#include <bits/stdc++.h>
#include "mymap.h"
using namespace std;

void FloydDispath(MatGraph g,int A[][MAXV],int path[][MAXV])
{
	int i,j,k;
	int apath[MAXV],d;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
		if (A[i][j]<INF&&i!=j)
		{
			printf("从顶点%d到顶点%d路径为: ",i,j);
			d=0;apath[d]=j;
			k=path[i][j];
				while (k!=i&&k!=-1)
				{
					d++;apath[d]=k;
					k=path[i][k];
				}
				if (k!=i)
				{
					printf("无路径\n");break;
				}
				d++;apath[d]=i;
				printf("%d",apath[d]);
				for (j=d-1;j>=0;j--)
					printf(",%d",apath[j]);
				printf("\t路径长度为: %d\n",A[i][j]);
			}
}
void Floyd(MatGraph g)
{
	int A[MAXV][MAXV],path[MAXV][MAXV];
	int i,j,k;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
		{
			A[i][j]=g.edges[i][j];
			if (i!=j&&A[i][j]<INF)
			path[i][j]=i;
			else
			path[i][j]=-1;
		}
	for (k=0;k<g.n;k++)
		for (i=0;i<g.n;i++)
			for (j=0;j<g.n;j++)
			if (A[i][j]>A[i][k]+A[k][j])
			{
				A[i][j]=A[i][k]+A[k][j];
				path[i][j]=path[k][j];
			}
	FloydDispath(g,A,path);
}
