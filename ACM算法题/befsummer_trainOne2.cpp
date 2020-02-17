#include <bits/stdc++.h>
//带lazy标签的线段树 
using namespace std;
#define  N 1000001
#define LL long long
#define mid (left+right)/2
#define lson r<<1,left,mid
#define rson r<<1|1,mid+1,right
typedef struct{
	int left,right;
	LL sum;
}dot;
dot Dot[N*4];
int father[N];
LL lazy[N];
void BuildTreeB(int r,int left,int right);
void QueryB(int r,int left,int right);
void UpdateB(int r,LL addnum);
LL Sum;
int main(void)
{
	memset(father,0,sizeof(father));
	memset(Dot,0,sizeof(Dot));
	memset(lazy,0,sizeof(lazy));
	int n,m;
	scanf("%d %d",&n,&m);
	BuildTreeB(1,1,n);
	LL addnum;
	int x1,x2;
	int type,i;
	while (m--)
	{
		scanf ("%d",&type);
		if (type==0)
		{
			scanf ("%d %d %lld",&x1,&x2,&addnum);
			for (i=x1;i<=x2;i++)
			lazy[i]+=addnum;
		}
		else
		{
			Sum=0;
			scanf ("%d %d %lld",&x1,&x2,&addnum);
			for (i=x1;i<=x2;i++)
			{
				if (lazy[i])
				{
					UpdateB(father[i],lazy[i]);
					lazy[i]=0;
				}
			}
			QueryB(1,x1,x2);
			printf("%lld\n",Sum);
		}
	}
	return 0;
}
void BuildTreeB(int r,int left,int right)
{
	 Dot[r].left=left;Dot[r].right=right;Dot[r].sum=0;
	if (left==right)
	{
		father[left]=r;
		
	}
	else
	{
		BuildTreeB(lson);
		BuildTreeB(rson);
	}
}
void QueryB(int r,int left,int right){
	if (left==Dot[r].left&&right==Dot[r].right)
	{
		Sum+=Dot[r].sum;
	 }
	 else
	 {
	 	int rt=r<<1;
	 	if (right<=Dot[rt].right)
	 	QueryB(rt,left,right);
	 	else if (left>=Dot[rt+1].left)
	 	QueryB(rt+1,left,right);
	 	else
	 	{
	 		QueryB(rt,left,Dot[rt].right);
	 		QueryB(rt+1,Dot[rt+1].left,right);
		 }
	 }
	
}
void UpdateB(int r,LL addnum){
	Dot[r].sum+=addnum;
	if (r==1)
	{
		return ;
	}
	UpdateB(r>>1,addnum);
}
