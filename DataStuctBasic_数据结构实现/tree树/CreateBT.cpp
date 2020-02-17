#include "mytree.h"
#include <bits/stdc++.h>
BTNode *CreateBTl1(char *pre,char *in,int n)
{
	BTNode *b;
	char *p;
	int k;
	if (n<=0)return NULL;
	b=new BTNode;
	b->data=*pre;
	for (p=in;p<in+n;p++)
		if (*p==*pre)
		break;
	k=p-in;
	b->lchild=CreateBTl1(pre+1,in,k);
	b->rchild=CreateBTl1(pre+k+1,p+1,n-k-1);
	return b; 
 } 
 BTNode *CreateBTl2(char *in,char*post,int n)
 {
 	BTNode *b;
 	char ch,*p;
 	int k;
 	if (n<=0)return NULL;
 	ch=*(post+n-1);
 	b=new BTNode;
 	b->data=ch;
 	for (p=in;p<in+n;p++)
 	   if(*p==ch)break;
 	k=in-p;
 	b->lchild=CreateBTl2(in,post,k);
 	b->rchild=CreateBTl2(p+1,post+k,n-k-1);
 	return b;
 }
