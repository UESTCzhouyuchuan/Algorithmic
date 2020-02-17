#include <bits/stdc++.h>
using namespace std;
#define MAX_LEN 200
int Substract(int *p1,int*p2,int nLen1,int nLen2);
void print(int a[],int a_len){
  for (int i =a_len-1;i>=0;i--)
    printf("%d",a[i]);
  printf("\n");
}
int main(void)
{
	char ReadLen1[MAX_LEN+10],ReadLen2[MAX_LEN+10];
	int ans1[MAX_LEN+10],ans2[MAX_LEN+10];
	int Result[MAX_LEN+10];
	int nLen1,nLen2,nTimes;
	int n;
	scanf ("%d",&n);
	while (n--)
	{
		memset(ReadLen1,0,sizeof(ReadLen1));
		memset(ReadLen2,0,sizeof(ReadLen2));
		scanf ("%s",ReadLen1);
		scanf ("%s", ReadLen2);
		nLen1=strlen(ReadLen1),nLen2=strlen(ReadLen2);
		if (nLen1<nLen2)
		{
			printf("0\n");
		}
		else
		{
			memset(ans1,0,sizeof(ans1));
			memset(ans2,0,sizeof(ans2));
			memset(Result,0,sizeof(Result));
			int i,j;
			for (j=0,i=nLen1-1;i>=0;i--,j++)
			ans1[j]=ReadLen1[i]-'0';
			for (j=0,i=nLen2-1;i>=0;i--,j++)
			ans2[j]=ReadLen2[i]-'0';
			nTimes=nLen1-nLen2;
			if (nTimes){
				for (i=nLen2-1;i>=0;i--)
			ans2[i+nTimes]=ans2[i];
			memset(ans2,0,nTimes*sizeof(int));
			}
			for (j=0;j<=nTimes;j++)
			{
				int t;
				while ((t=Substract(ans1,ans2+j,nLen1,nLen2+nTimes-j))>=0)
				{
					nLen1=t;
					Result[nTimes-j]++;
				}
			}
			if (Result[nTimes]==0)nTimes--;
			while (nTimes>=0)
			printf("%d",Result[nTimes--]);
			printf("\n");
			
		}
	}
	return 0;
}
int Substract(int *p1,int *p2,int nLen1,int nLen2)
{
	if (nLen1<nLen2)
	return -1;
	int i;
	if (nLen1==nLen2)
	{
		for (i=nLen1-1;i>=0;i--)
		if (p1[i]>p2[i])break;
		else if (p1[i]<p2[i]) return -1;
	}

	for (i=0;i<nLen1;i++)
	{
		p1[i]-=p2[i];
		if (p1[i]<0)
		{
			p1[i]+=10;
			p1[i+1]--;
		}
	}
	for (i=nLen1-1;i>=0;i--)
		if (p1[i])
			return i+1;
	return 0;
}
