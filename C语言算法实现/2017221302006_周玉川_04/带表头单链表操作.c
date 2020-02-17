#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
	int data;
	struct node*next;
}LinkNode;
typedef int ElemType;
void InitList (LinkNode*L);
void CreatListF (LinkNode*L, ElemType *a, int n);
void CreatListB (LinkNode*L, ElemType *a, int n);
void InsertList	(LinkNode*L, int i, ElemType e);
bool ListEmepty	(LinkNode*L);
void DeleteList	(LinkNode*L,int i);
void DestoryList (LinkNode*L);
void ListSort(LinkNode*L);//排序
void ListReverse(LinkNode*L);//反转
int LocateList(LinkNode*L, ElemType e);
int main(void) {
	LinkNode*L=(LinkNode*)malloc(sizeof(LinkNode));
	InitList(L); 
	return 0;
}

void InitList (LinkNode*L)
{
	L->next=NULL;
}
void CreatListF (LinkNode*L, ElemType *a, int n)
{
	LinkNode*p,*l=L;
	int i;
	for (i=0; i<n; i++)
	{
		p=(LinkNode*)malloc(sizeof(LinkNode));
		if(p==NULL)
		{
		printf("Apply for room failed!\n");
		return ;
		}
		l->next=p;
		p->data=a[i];
		l=p;
	}
	l->next=NULL;
}
void CreatListB (LinkNode*L, ElemType *a, int n)
{
	LinkNode*p,*l=L;
	int i;
	for (i=0; i<n; i++)
	{
		p= (LinkNode*)malloc(sizeof(LinkNode));
		if(p==NULL)
		{
		printf("Apply for room failed!\n");
		return ;
		}
		p->next=l->next;
		l->next=p;
		p->data=a[i];
	}
	
}
void InsertList	(LinkNode*L, int i, ElemType e){//在第i个节点之后插入 
	int counter;
	LinkNode*l=L,*p;
	for (counter=0; counter<i; counter++)
	l=l->next;
	p=(LinkNode*)malloc(sizeof(LinkNode));
	if(p==NULL)
		{
		printf("Apply for room failed!\n");
		return ;
		}
	p->next=l->next;
	l->next=p;
	p->data=e;
}
bool ListEmepty	(LinkNode*L){
	return ((L->next)?false:true);
}
void DeleteList	(LinkNode*L,int i){
	LinkNode*p=L,*pre;
	int counter;
	for (counter=0; counter<i; counter++){
		pre=p;
		p=p->next;
	}
	pre->next=p->next;
	free(p);
}
void DestoryList (LinkNode*L){
	LinkNode*p=L->next,*pre;
	for(;p;)
	{
		pre=p->next;
		free(p);
		p=pre;
	}
	L->next=NULL;
}
int LocateList(LinkNode*L,ElemType e)
 {
 	int location;
 	LinkNode*pL=L->next;
 	if(pL==NULL){
 		printf("List is empty!\n");
 		return -1;
 	}
 	for (location= 0;; location++){
 		if(pL->data==e){
 			return (location+1);
 		}
 		if(!pL)
 		break;
 		pL=pL->next;
 	}
 }
 void ListSort(LinkNode*L)
 {
 	LinkNode*p,*q,*pre;
 	p=L->next->next;
 	L->next->next=NULL;
 	while(p!=NULL)
 	{
 		q=p->next;
 		pre=L;
 		while(pre->next!=NULL&&pre->next->data<p->data)
 		pre=pre->next;
 		p->next=pre->next;
 		pre->next=p;
 		p=q;
 	}
 	
 }
 void ListReverse(LinkNode*L)
 {
 	LinkNode*p=L->next,*q=p->next,*k;
 	p->next=NULL;
 	for(;q;)
 	{
 		k=q->next;
 		q->next=p;
 		p=q;
 		q=k;
 	}
 	L->next=p;
 	
 }

