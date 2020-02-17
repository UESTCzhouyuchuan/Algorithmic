#include <bits/stdc++.h>
#include "mymap.h"
using namespace std;
int main(void)
{
	AdjGraph*G;
	int A[MAXV][MAXV];
	int visited[MAXV];
	memset(A,0,sizeof(A));
	memset(visited,0,sizeof(visited));
	for (int i=0;i<9;i++)
	A[i][i+1]=i+1;
	CreatAdj(G,A,10,10);
	DispAdj(G);
	DFS(G,0,visited);
	DestroyAdj(G);
	return 0;
}
