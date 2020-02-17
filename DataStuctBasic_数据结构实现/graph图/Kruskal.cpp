#include "mymap.h"
#include <bits/stdc++.h>
using namespace std;
typedef struct
{
	int u;
	int v;
	int weight;
}Edge;
int FindSet(int x,int Set[])
{
	if (x==Set[x])
	return x;
	else Set[x]=FindSet(Set[x],Set);
}
bool mycompare(Edge e1,Edge e2)
{
	return e1.weight<e2.weight;
}
void Kruskal(MatGraph g)
{
	int i,j,k,u1,v1,sn1,sn2;
	int Set[MAXV];
	Edge E[MAXV*10];
	k=0;
	for (i=0;i<g.n;i++)
		for (j=0;j<=i;j++)
			if (g.edges[i][j]!=0&&g.edges[i][j]<INF)
			{
				E[k].u=i;E[k].v=j;E[k].weight=g.edges[i][j];
				k++;
			}	
	sort(E,E+k,mycompare);
	for (i=0;i<g.n;i++)
	Set[i]=i;
	j=0;
	for (k=0;k<g.n-1;j++)
	{
		u1=E[j].u;
		v1=E[j].v;
		sn1=FindSet(u1,Set);
		sn2=FindSet(v1,Set);
		if (sn1!=sn2)
		{
			printf("(%d,%d):%d\n",u1,v1,E[j].weight);
			k++;
			Set[sn1]=sn2;
		}
	}
}
