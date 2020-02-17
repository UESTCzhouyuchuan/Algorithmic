//KMPÀ„∑®
#include <bits/stdc++.h>
#define MAXNUM 50
using namespace std;

typedef struct {
	char data[MAXNUM];
	int length;
}SqString;
void GetNext(const SqString t, int *next);
int KMPindex (const SqString s,SqString t);

int main ()
{
	SqString L;
	gets(L.data);
	L.length=strlen(L.data);
	int next[MAXNUM];
	GetNext(L,next);
	int i;
	for (i=0;i<L.length;i++)
	printf("%d ",next[i]);
	return 0;
} 
void GetNext(const SqString t, int *next)
{
	int j=0,k=-1;
	next[0]=-1;
	while (j<t.length-1)
	{
		if (k==-1||t.data[j]==t.data[k])
		{
			k++;j++;
			next[j]=k;
		}
		else
		k=next[k];
	}
}
int KMPindex (const SqString s,SqString t)
{
	int next[MAXNUM],i=0,j=0;
	GetNext(t,next);
	while (i<s.length &&j<t.length)
	{
		if (j==-1||s.data[i]==t.data[j]){
			i++;j++;
		}
		else
		j=next[j];
	}
	if (j==t.length)
	{
		return (i-t.length);
	}
	else
	return -1;
}
