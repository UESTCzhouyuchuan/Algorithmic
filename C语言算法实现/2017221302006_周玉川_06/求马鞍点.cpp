//’“¬Ì∞∞µ„ 
#include <bits/stdc++.h>
#define M 10
#define N 10
using namespace std;
void InputArray(int a[][M],int m,int n);
void AnalyseArray(int a[][N],int*max,int*min,int m,int n);

int main(void)
{
	int a[M][N];
	int m,n;
	scanf ("%d %d",&m,&n);
	int MinRaw[m];
	int MaxCol[n]; 
	InputArray(a,m,n);
	AnalyseArray(a,MinRaw,MaxCol,m,n);
	return 0;
}

void InputArray(int a[][M],int m,int n){
	int i,j;
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
	scanf (" %d",&a[i][j]);
	getchar();
	}
	
	
}
void AnalyseArray(int a[][N],int*min,int*max,int m,int n){
	int i,j,k;
	for (i=0;i<m;i++)
	{
		k=0;
		for (j=0;j<n;j++)
		{
			if (a[i][k]>a[i][j])
			k=j;
		}
		min[i]=k;
	}
	for (i=0;i<n;i++){
		for (j=0;j<m;j++)
	{
		k=0;
		if (a[j][i]>a[k][i])
		k=j;
	}
	max[i]=k;
	}
	for (i=0;i<m;i++)
	if (max[min[i]]==i)
	printf("a[%d][%d]:%d\n",i,min[i],a[i][min[i]]);
	printf("\n");	
}
