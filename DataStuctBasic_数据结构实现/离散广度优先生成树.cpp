//广度优先搜索求全部的生成树 

#include <bits/stdc++.h>
using namespace std;
#define N 100

int Map[N][N],sett[N];
int DispMap[N][N];
int num;
void TreeSon(int start,int counter);
void Disp(void);
int FindSet(int num);
int main(void)
{
	memset(Map,-1,sizeof(Map));
	memset(DispMap,-1,sizeof(DispMap));
	int m,n,value;
	int i;
	printf("结点的数量(1-n)：\n");
	scanf("%d",&num);
	for (i=1;i<=num;i++)sett[i]=i;
	while (scanf("%d %d %d",&m,&n,&value)==3)
	Map[m][n]=value;
	for (i=0;i<num;i++)
	{
		TreeSon(i+1,0);
	}
	return 0;
}
int FindSet(int num)
{
	if (sett[num]==num)
	return num;
	else
	{
		int a=sett[num];
		return sett[num]=FindSet(a);
	}
}
void TreeSon(int start,int counter)
{
	if (counter==num-1)
	Disp();
	else
	{
	int j,i;
	int a,b;
	for (j=0;j<num;j++)
	{
		a=Map[start][j];
		if (a!=-1)
		{
				sett[j]=start;
				DispMap[start][j]=a;
			for(i=0;i<num;i++)
			{
				if (i==j)continue;
				b=Map[start][i];
				if (b!=-1&&FindSet(j)!=FindSet(i))
				{
					sett[i]=start;
					DispMap[start][i]=b;
					TreeSon(i,counter+1);
					TreeSon(j,counter+1);
					sett[i]=i;
					DispMap[start][i]=-1;
				}
			}
			TreeSon(j,counter+1);
			sett[j]=j;
			DispMap[start][j]=-1;
		}
	}
	}
	
}
void Disp(void)
{
	int i,j;
	for (i=1;i<=num;i++)
	for (j=1;j<=num;j++)
	printf("%d%c",DispMap[i][j],j==num?' ':'\n');
}
