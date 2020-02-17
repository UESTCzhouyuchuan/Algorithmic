#include "mytree.h"
#include <bits/stdc++.h>
using namespace std;
void InOrder(BTNode *b)
{
	if (b!=NULL)
	{
		InOrder(b->lchild);
		printf("%c ",b->data);
		InOrder(b->rchild);
	}
}
void InOrder1(BTNode *b)
{
	BTNode*p=b;
	stack<BTNode*> q;
	while (!q.empty()||p!=NULL)
	{
		while (p!=NULL)
		{
			q.push(p); 
			p=p->lchild;
		}
		if (!q.empty())
		{
			p=q.top();q.pop();
			printf("%c ",p->data);
			p=p->rchild;
		}
	}
	printf("\n");
}
