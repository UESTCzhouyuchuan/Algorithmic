#include <bits/stdc++.h>
using namespace std;
#define M 8
#define N 8
int dx[4]={1,0,0,-1},dy[4]={0,1,-1,0};
typedef struct
{
	int x,y;
}road;
int a[M+2][N+2];//为0时表示可以走，1是障碍物，-1时走过了
bool FindPath(road e,int fix,int fiy);
stack<road> q;
void print(int a[][M+2]);
int main(void)
{
	
	memset(a,0,sizeof(a));
//	print(a);
	int i=0;
	for (i=0;i<M+2;i++)a[i][0]=a[i][N+1]=1;
	for (i=0;i<N+2;i++)a[0][i]=a[M+1][i]=1;
	a[1][3]=a[1][7]=a[2][3]=a[2][7]=a[3][5]=a[3][6]=a[4][2]=a[4][3]=a[4][4]=a[5][4]=a[6][2]=a[6][6]=a[7][2]=a[7][3]=a[7][4]=a[7][6]=a[7][7]=a[8][1]=1;
	road begin={2,2};
	if(FindPath(begin,1,8)==false)
	printf("No solution\n");
	return 0;
} 

void print(int a[][M+2])
{
	int i,j;
	for (i=0;i<M+2;i++)
	for (j=0;j<N+2;j++)
	printf("%d%c",a[i][j],j==(N+1)?'\n':',');
}
bool FindPath(road e,int fix,int fiy)
{
	int i=0;
	if (e.x==fix&&e.y==fiy)
	{
		q.push(e);
		stack<road> p;
		while (!q.empty())
		{
			p.push(q.top());
			q.pop();
		}
		while(!p.empty())
		{
			printf("(%d %d)",p.top().x,p.top().y);
			printf("%c",(++i)%5?',':'\n');
			p.pop();
		}
		return true;
		
	}
	else
	{
		q.push(e);
		road re;
		for (i=0;i<4;i++)
		{
			re.x=e.x+dx[i];
			re.y=e.y+dy[i];
			if (a[re.x][re.y]==0)
			{
				a[re.x][re.y]=-1;
			if (FindPath(re,fix,fiy)==true)
				return true;
				a[re.x][re.y]=0;
			}
		}
		q.pop();
		return false;
	}
}
