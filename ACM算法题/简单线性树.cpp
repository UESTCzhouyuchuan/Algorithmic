#include <bits/stdc++.h>
using namespace std;
#define mid (left+right)/2
#define lson rt<<1,left,mid
#define rson rt<<1|1,mid+1,right
#define N 1000010 

void BuildTree(int rt,int left,int right);
void Update(int rt);
void query(int rt,int left,int right);
int father[N];
struct node{
	long long sum,max,min;
	int left,right;
}dot[N*4];
long long Sum,Min,Max;
int main(void)
{
	int n,m;
	memset(father,0,sizeof(father));
	memset(dot,0,sizeof(dot));
	int type;
	long long num;
	int index;
	int x1,x2;
	scanf("%d %d",&n,&m);
	BuildTree(1,1,n);
	while (m--)
	{
		scanf("%d",&type);
		switch(type)
		{
			case 0:scanf("%d %lld",&index,&num);
				dot[father[index]].max=dot[father[index]].min=dot[father[index]].sum=num;
				Update(father[index]);
  				break;
			case 1:scanf("%d %d",&x1,&x2);
				Sum=0;Max=LONG_LONG_MIN;Min=LONG_LONG_MAX;
				query(1,x1,x2);
				printf("%lld\n",Sum-Max-Min);
				break;
			default:break;
		}
	}
	return 0;
}
void BuildTree(int rt,int left,int right){
	dot[rt].left=left;dot[rt].right=right;
	if (left==right)
	{
		father[left]=rt;
		return ;
	}
	BuildTree(lson);
	BuildTree(rson);
}
void Update(int rt)
{
	if(rt==1)
	{
		return ;
	 }
	 int rft=rt/2;
	 const struct node comp1=dot[rft<<1],comp2=dot[rft<<1|1];
	 dot[rft].max=comp1.max>comp2.max?comp1.max:comp2.max;
	 dot[rft].min=comp1.min<comp2.min?comp1.min:comp2.min;
	 dot[rft].sum=comp1.sum+comp2.sum;
	 Update(rft);
} 
void query(int rt,int left,int right)
{
	if (dot[rt].left==left&&dot[rt].right==right)
	{
		Sum+=dot[rt].sum;
		Min=Min<dot[rt].min?Min:dot[rt].min;
		Max=Max>dot[rt].max?Max:dot[rt].max;
	}
	else
	{	
		if(left<=dot[rt<<1].right)
		{
			if (right<=dot[rt<<1].right)
			query(rt<<1,left,right);
			else
			query(rt<<1,left,dot[rt<<1].right);
		}
		if (right>=dot[rt<<1|1].left)
		{
			if (left>=dot[rt<<1|1].left)
			query(rt<<1|1,left,right);
			else
			query(rt<<1|1,dot[rt<<1|1].left,right);
		}
	}
}
