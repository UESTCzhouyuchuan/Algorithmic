//有序表的二路归并算法 A,B是有序的 
#include <stdio.h>
#include <stdlib.h>
#define ElemType int
#define MAXNUM 50
typedef struct {
	ElemType data[MAXNUM];
	int length;
}SqList;
typedef struct Node{
	int data;
	struct Node *next;
}LinkNode;
void UnionList(SqList*LA, SqList*LB, SqList*LC)
{
	int i=0,j=0,k=0;
	while (i<LA->length&&j<LB->length)
	{
		if (LA->data[i]<LB->data[j])
		{
			LC->data[k++]=LA->data[i++];
		}
		else
		{
			LC->data[k++]=LB->data[j++];
		}
	}
	while (i<LA->length)
	LC->data[k++]=LA->data[i++];
	while (j<LB->length)
	LC->data[k++]=LB->data[j++];
	LC->length=k;
} 

void UnionListl(LinkNode*LA, LinkNode*LB, LinkNode*LC)
{
	LinkNode*p=LA->next,*q=LB->next,*L=LC;
	LinkNode*s;
	while (p!=NULL&&q!=NULL)
	{
		s=(LinkNode*)malloc(sizeof(LinkNode));
		L->next=s;
		if (p->data<q->data)
		{
			s->data=p->data;
			p=p->next;
		}
		else
		{
			s->data=q->data;
			q=q->next;
		}
		L=s;
	}
	while (p!=NULL)
	{
		s=(LinkNode*)malloc(sizeof(LinkNode));
		L->next=s;
		s->data=p->data;
		p=p->next;
		L=s;
	}
	while (q!=NULL)
	{
		s=(LinkNode*)malloc(sizeof(LinkNode));
		L->next=s;
		s->data=q->data;
		q=q->next;
		L=s;
	}
	L->next=NULL;
}
