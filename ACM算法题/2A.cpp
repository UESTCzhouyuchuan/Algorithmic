#include <bits/stdc++.h>
using namespace std;
#define N 200001
typedef struct edge
{
	int end;
	struct edge*next;
}Edge;
struct node{
	Edge*fnext;
	Edge*lnext;
}mynode[N];
void add(int i,Edge *p);
int n,k,m;
int Mstep=6666;
void Find(int begin,int counter);
int main(){

	memset(mynode,0,sizeof(mynode));
	scanf("%d %d %d",&n,&k,&m);
	int x,y;
	while(m--)
	{
		Edge*p1,*p2;
		p1=new Edge;p2=new Edge;
		scanf("%d %d",&x,&y);
		(*p1).end=x;(*p2).end=y;
		(*p1).next=NULL,(*p2).next=NULL;
		add(x,p2);
		add(y,p1);
	}
	Find(1,1);
	printf("%d\n",Mstep);
	return 0;
}
void Find(int begin, int counter)
{
	if (counter>=Mstep)return ;
	else if (begin==k)
	{
		Mstep=counter;
	}
	else
	{
		Edge*p=mynode[begin].fnext;
		while (p!=NULL)
		{
			if (p->end==k)
			{
				Mstep=counter+1;
				return ;
			}
			p=p->next;
		}
		p=mynode[begin].fnext;
		while (p!=NULL)
		{
			Find(p->end,counter+1);
			p=p->next;
		}
	}
}
void add(int i,Edge*p)
{
	if (mynode[i].fnext==NULL){
				mynode[i].fnext=mynode[i].lnext=p;
		}
		else
		{
			mynode[i].lnext->next=p;
			mynode[i].lnext=p;
		}
}
