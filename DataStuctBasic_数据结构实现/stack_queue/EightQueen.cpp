#include <bits/stdc++.h>
#include"myStackQueue.h"
using namespace std;

int EightQueen(int n);
int main(void)
{
	int a=EightQueen(4);
	printf("%d\n",a);
	return 0;
}

int EightQueen(int n)
{
	int i=0,k=1,j;
	SqStack q;
	q.top=-1;
	int counter=0;
	bool flag=true;
	do{
		if(i==n)
		{
		   counter++;
		   i--;
		   flag=true;
		   q.top--;	
		   q.data[q.top]+1;
		}
		else
		{
			flag=false;
		for (;k<=n&&!flag;)
		{
		  for (j=0;j<=q.top;j++)
		  	if(k==q.data[j]||q.data[j]-k==j-i||q.data[j]-k==i-j)
		  	break;
		  	
		    if(j==i)
		    {
		    	q.data[++(q.top)]=k;
		    	flag=true;
		    	i++;
		    	k=1;
			}
			else k++;
		   
		}
		if(!flag&&q.top!=-1)
		{
		    i--;
		    k=q.data[q.top]+1;
		    q.top--;
			}
	    }	
	}while(q.top!=-1);
	return counter;
}




