#include <bits/stdc++.h>
#define N 8
#define M 8
using namespace std;
typedef struct
{
	int x,y;
	int pre;
}road;
int a[M+2][N+2];
queue <road> Road,q;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
bool FindPathl(road e,int endx,int endy,int counter);
void print(queue <road> p); 
int main(void)
{
	memset(a,0,sizeof(a));
	int i=0;
	for (i=0;i<M+2;i++)a[i][0]=a[i][N+1]=1;
	for (i=0;i<N+2;i++)a[0][i]=a[M+1][i]=1;
	a[1][3]=a[1][7]=a[2][3]=a[2][7]=a[3][5]=a[3][6]=a[4][2]=a[4][3]=a[4][4]=a[5][4]=a[6][2]=a[6][6]=a[7][2]=a[7][3]=a[7][4]=a[7][6]=a[7][7]=a[8][1]=1;
//	printf("%d",Road.size());
	road begin={1,1,1};
	Road.push(begin);
	q.push(begin);
	int counter=0;
	if(FindPathl(begin,8,8,counter)==false)
	printf("No solution\n");
	return 0;
 } 
void print(queue <road> p)
{
	while (!p.empty()){
	printf("(%d %d),",p.front().x,p.front().y);
	int i=p.front().pre;
	p.pop();
	while (i--)p.pop();
}
	
}
bool FindPathl(road e,int endx,int endy,int counter)
{
	counter++;
	e=Road.front();
	Road.pop();
	if (e.x==endx&&e.y==endy)
	{
		print(q);
		return true;
	}
	else
	{
		int i;
		road re;
		for (i=0;i<4;i++)
		{
			re.x=re.x+dx[i];
			re.y=re.x+dy[i];
			if (re.x>=1&&re.x<=8&&re.y>=1&&re.y<=8&&a[re.x][re.y]==0)
			{
				re.pre=counter-Road.size();
				Road.push(re);
				q.push(re);
				a[re.x][re.y]=-1;
				FindPathl(re,endx,endy,counter);
			}
		}
		return false;
	}
	
}
