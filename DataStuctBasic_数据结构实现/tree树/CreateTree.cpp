#include "mytree.h"
#include <bits/stdc++.h>
using namespace std;
void CreateBTree(BTNode *&b,char *str)
{
	stack<BTNode*> q;
	int k,j=0;
	char ch=str[j];
	b=NULL;
	BTNode*p;
	while (ch!='\0')
	{
		switch(ch){
			case '(':q.push(p);k=1;break;
			case ')':q.pop();break;
			case ',':k=2;break;
			default:p=new BTNode;
				if (p==NULL)
				{
					perror("");exit(EXIT_FAILURE);
				}
				p->data=ch;
				p->rchild=p->lchild=NULL;
				if (b==NULL)
				{
					b=p;
				}
				else
				{
					if (k==1)
					{
						q.top()->lchild=p;
					}
					else
					q.top()->rchild=p;
				}
		}
		j++;
		ch=str[j];
	}
 } 
