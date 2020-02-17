#include <bits/stdc++.h>
using namespace std;
#define N 100
int a[2][4]={{0,0,-1,1},
			{1,-1,0,0}};
typedef struct {
	int x,y;
	int pre;
}Box;
Box data[N];
int Step,flag;
int visit[N+1][N+1];
int xexit,yexit;
void searchPath(Box secBox,int step);
bool mycompare(const Box a,const Box b){
	if(a.x==b.x)return a.x < b.x;
	else return a.x < b.x; 
};
int m,n;
int main(void)
{
	
	while (scanf("%d %d",&m,&n)==2)
	{
		int i;
		Step=0;
		flag=0;
		memset(visit,0,sizeof(visit));
		for (i=0;i<n;i++)
		scanf("%d %d",&data[i].x,&data[i].y);
		scanf("%d %d",&xexit,&yexit);
		sort(data,data+n,mycompare);
		searchPath(data[0],0);
		if (Step==0)printf("No solution\n");
		else
		{
			printf("%d\n",Step);
		}
	}
}
void searchPath(Box secBox,int step){
	if (secBox.x==xexit&&secBox.y==yexit)
	{
		if (flag==0||step<Step){
			flag=1;
			Step=step;
		}
	}
	else
	{
		Box box;
		int i;
		for (i=0;i<4;i++)
		{
			box.x=secBox.x+a[0][i];
			box.y=secBox.y+a[1][i];
			if (box.x>=1&&box.x<=m&&box.y>=1&&box.y<=m&&visit[box.x][box.y]==0&&binary_search(data,data+n,box,mycompare))
			{
				visit[box.x][box.y]=1;
				searchPath(box,step+1);
				visit[box.x][box.y]=0;
			}
		}
		
	}
}
