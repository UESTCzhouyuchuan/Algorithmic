#include "mytree.h"
#include <bits/stdc++.h>
using namespace std;

void PostOrder(BTNode *b)
{
	if(b!=NULL)
	{
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%c ",b->data);
	}
}
void PostOrder1(BTNode *b)
{
	BTNode *p=b,*r;
	stack<BTNode*> q;
	bool flag;
	do{
		while (p!=NULL)
		{
			q.push(p);
			p=p->lchild;
		}
		r=NULL;flag=true;
		while(!q.empty()&&flag)
		{
			p=q.top();
			if (p->rchild==r)
			{
				printf("%c ",p->data);
				q.pop();
				r=p;
			}
			else
			{
				p=p->rchild;
				flag=false;
			}
		}
	}while (!q.empty());
	printf("\n");
}
