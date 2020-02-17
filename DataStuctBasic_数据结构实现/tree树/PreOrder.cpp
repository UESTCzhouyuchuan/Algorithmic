#include "mytree.h"
#include <bits/stdc++.h>
using namespace std;
void PreOrder(BTNode *b)
{
	if (b!=NULL)
	{
		printf("%c ",b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}
void PreOrder1(BTNode *b)
{
	BTNode*p;
	stack<BTNode*> q;
	if (b!=NULL)
	{
		q.push(b);
		while (!q.empty())
		{
			p=q.top();q.pop();
			printf("%c ",p->data);
			if (p->rchild!=NULL)
			q.push(p->rchild);
			if(p->lchild!=NULL)
			q.push(p->lchild);
		}
		printf("\n");
	}
}
void PreOrder2(BTNode *b)
{
	BTNode*p=b;
	stack<BTNode*> q;
	while (!q.empty()||p!=NULL)
	{
		while (p!=NULL)
		{
			printf("%c ",p->data);
			q.push(p);
			p=p->lchild;
		}
		if (!q.empty())
		{
			p=q.top();q.pop();
			p=p->rchild;
		}
	}
	printf("\n");
}
