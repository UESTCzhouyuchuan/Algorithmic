#include <bits/stdc++.h>
#define N 100010
using namespace std;
int num[N];
bool mycompare(int a,int b)
{
	return a>b;
}
int main(void)
{
	int n,k;
	int counter,tag,xa,xb;
	scanf ("%d %d",&n,&k);
	int i;
	for (i=1;i<=n;i++)
	scanf("%d",&num[i]);
	scanf ("%d",&counter);
	while (counter--)
	{
		scanf ("%d %d %d",&tag,&xa,&xb);
		switch(tag){
			case 0:sort(num+xa,num+xb+1);break;
			case 1:sort(num+xa,num+xb+1,mycompare);break;
			default:break;
		}
	}
	printf("%d\n",num[k]);
	return 0;
}

