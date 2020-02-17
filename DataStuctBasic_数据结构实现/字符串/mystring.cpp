#include "mystring.h"
 
 void GetNext(SqString t,int next[])
 {
 	int k=-1,j=0;
 	next[0]=-1;
 	while(j<t.length)
 	{
 		if (k==-1||t.data[k]==t.data[j])
 		{
 			j++;k++;
 			next[j]=k;
		 }
		 else
		 k=next[k];
	 }
 }
int KMPIndex(SqString s,SqString t)
{
	int next[MaxSize],i=0,j=0;
	GetNext(t,next);
	while (i<s.length&&j<t.length)
	{
		if (j==-1||s.data[i]==s.data[j])
		{
			i++;j++;
		}
		else j=next[j];
		if (j>=t.length)
		return (i-t.length);
		else
		return -1;
	}
}
void GetNextval(SqString t,int nextval[])
{
	int k=-1,j=0;
 	nextval[0]=-1;
 	while(j<t.length)
 	{
 		if (k==-1||t.data[k]==t.data[j])
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
int  KMPIndexl(SqString s,SqString t)
{
	int next[MaxSize],i=0,j=0;
	GetNextval(t,next);
	while (i<s.length&&j<t.length)
	{
		if (j==-1||s.data[i]==s.data[j])
		{
			i++;j++;
		}
		else j=next[j];
		if (j>=t.length)
		return (i-t.length);
		else
		return -1;
	}
}
