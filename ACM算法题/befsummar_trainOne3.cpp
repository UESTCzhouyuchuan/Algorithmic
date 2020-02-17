#include <bits/stdc++.h>
#define N 1000001
using namespace std;
int b[N];
int second_min(int xa,int xb);
int main(void)
{
	b[0]=1;
	int n;
	int c;
	scanf("%d",&n);
	for (int i=1;i< n+1;i++)
	{
		scanf("%d",&c);
		b[i]=second_min(i-c,i-1);
	}
	for (int i=1;i<n;i++)
	printf("%d ",b[i]);
	printf("%d",b[n]);
	return 0;
}
int second_min(int xa,int xb)
{
	int i;
	int	min=b[xa];
	for (i=xa+1;i<=xb;i++)
	{
		min=min<b[i]?min:b[i]; 
	}
	if (min>1)
	return 1;
	else
	{
		int tag;
	do{
		tag=0;
			for (i=xa;i<=xb;i++)
			{
				if (b[i]==(min+1))
				tag=1;
			}
			min++;
		}while (tag);
	}
	return min;
}

