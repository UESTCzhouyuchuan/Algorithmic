 #include "mytree.h"
 #include <bits/stdc++.h>
 using namespace std;
 typedef struct{
 	BTNode*dot[MAXV];
 	int top;
 }SqStack;
 void AllPath(BTNode*b)
 {
 	BTNode *p=b,*r;
 	SqStack q;
 	q.top=-1;
 	bool flag;
 	do
 	{
 		while(p!=NULL)
 		{
 			q.dot[(++q.top)]=p;
 			p=p->lchild;
		 }
		 r=NULL;flag=true;
		 while(q.top!=-1&&flag)
		 {
		 	p=q.dot[q.top];
		 	if (p->rchild==r)
		 	{
		 		if (p->rchild==NULL&&p->lchild==NULL)
		 		{
		 			int i=q.top;
		 			while(i>=0)
		 			printf("%c ",q.dot[i--]->data);
					printf("\n");
				 }
		 		q.top--;
		 		r=p;
			 }
			 else{
			 	p=p->rchild;
			 	flag=false;
			 }
		 }
		 
	 }while(q.top!=-1);
 }
 void AllPath1(BTNode*b)
 {
 	 
 }
