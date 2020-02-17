#include <bits/stdc++.h>

#define N 50
typedef struct {
	char data[N];
	int length;
}SqString;
void GetNextval (SqString t, int *nextval);
void GetNext (SqString t,int *next);
int KMPIndex (SqString s, SqString t);

int main(void)
{
	SqString s,t;
	int nextval[N],next[N];
	gets(t.data);
	t.length=strlen(t.data);
	GetNextval(t,nextval);
	GetNext(t,next);
	int i;
	for (i=0;i<t.length;i++)
	printf("%d ",next[i]);
	printf("\n");
	for (i=0;i<t.length;i++)
	printf("%d ",nextval[i]);
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
void GetNextval (SqString t, int *nextval)
{
	int j=0,k=-1;
	nextval[0]=-1;
	while (j<t.length)
	{
		if (k==-1||t.data[j]==t.data[k])
		{
			j++;k++;
			if (t.data[j]!=t.data[k])
			nextval[j]=k;
			else
			nextval[j]=nextval[k];
		}
		else
		k=nextval[k];
	}
}
int KMPIndex (SqString s, SqString t){
	int nextval[N],i=0,j=0;
	GetNextval(t,nextval);
	while (i<s.length &&j<t.length)
	{
		if (j==-1||s.data[i]==t.data[j]){
			i++;j++;
		}
		else
		j=nextval[j];
	}
	if (j==t.length)
	{
		return (i-t.length);
	}
	else
	return -1;
}

