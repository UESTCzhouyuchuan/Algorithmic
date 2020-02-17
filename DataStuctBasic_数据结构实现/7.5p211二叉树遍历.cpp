#include <bits/stdc++.h>
//7.5二叉树的遍历 分为递归算法和非递归算法
using namespace std;
#define ElemType int
typedef struct node
{
	ElemType data;
	struct node*lchild;
	struct node*rchild;
}BtNode;

void PreOrder(BtNode * b);
void PreOrder1(BtNode * b);
void PreOrder2(BtNode * b);
void InOrder(BtNode * b);
void InOrderl(BtNode * b);
void InOrder2(BtNode * b);
void PostOrder(BtNode * b);
void PostOrder1(BtNode * b);
void PostOrder2(BtNode * b);

int main(void)
{
	
	return  0;
}
void PreOrder(BtNode * b){
	if (b==NULL)
	return ;
	printf("%d\n",b->data);
	PreOrder(b->lchild);
	PreOrder(b->rchild);
}
void PreOrder1(BtNode * b){
	BtNode*p;
	stack<BtNode*> q;
	p=b;
	if (b!=NULL)
	{	
		q.push(p);
	while(!q.empty()||p!=NULL)
	{
		p=q.top();
		printf("%d\n",p->data);
		q.pop();
		if (p->rchild!=NULL)
		q.push(p->rchild);
		if (p->lchild!=NULL)
		q.push(p->lchild);
	}
	}
}
void PreOrder2(BtNode*b)
{
	BtNode * p;
	stack<BtNode*> q;
	p=b;
	while (!q.empty()||p!=NULL)
	{
		while (p!=NULL)
		{
			printf("%d\n",p->data);
			q.push(p);
			p=p->lchild;
		}
		if (!q.empty())
		{
			p=q.top();
			q.pop();
			p=p->rchild;
		}
	}
}
void InOrder(BtNode * b){
	if (b==NULL)
	return ;
	InOrder(b->lchild);
	printf("%d\n",b->data);
	InOrder(b->rchild);
}
void InOrder1(BtNode * b)
{
	BtNode*p;
	stack<BtNode*> q;
	p=b;
	if (b!=NULL)
	{
		q.push(p);
		while (!q.empty()||p!=NULL)
		{
			if (p->lchild!=NULL)
			q.push(p->lchild);
			p=q.top();
			printf("%d\n",p->data);
			q.pop();
			if (p->rchild!=NULL)
			q.push(p->rchild);
		}
	}
}
void InOrder2(BtNode * b)
{
	BtNode * p=b;
	stack<BtNode*> q;
	while (!q.empty()||p!=NULL)
	{
		while (p!=NULL)
		{
			q.push(p);
			p=p->lchild;
		}
		if (!q.empty())
		{
			p=q.top();
			q.pop();
			printf("%d\n",p->data);
			p=p->rchild;
		}
	}
}
void PostOrder(BtNode * b){
	if (b==NULL)
	return ;
	PostOrder(b->lchild);
	PostOrder(b->rchild);
	printf("%d\n",b->data);
}
void PostRoder1(BtNode * b){
	BtNode*p;
	stack<BtNode*> q;
	p=b;
	if (b!=NULL)
	{
		q.push(p);
		while (!q.empty()||p!=NULL)
		{
			if (p->rchild!=NULL)
			q.push(p->rchild);
			p=q.top();
			printf("%d\n",p->data);
			q.pop();
			if (p->lchild!=NULL)
			q.push(p->lchild);
		}
	}
}

void PostOrder2(BtNode * b)
{
	BtNode* p;
	stack <BtNode*> q;
	p=b;
	while (!q.empty()||p!=NULL)
	{
		while (p!=NULL)
		{
			q.push(p);
			p=p->lchild;
		}
		if (!q.empty())
		{
			p=q.top();
			if (p->rchild==NULL){
			printf("%d\n",p->data);
			q.pop();	
			}
			p=p->rchild;
		}
	}
}
