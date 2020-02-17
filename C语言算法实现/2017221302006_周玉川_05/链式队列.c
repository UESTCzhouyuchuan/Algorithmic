//链式队列的基本操作
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXNUM 50

typedef int ElemType; 
typedef struct quene{
	ElemType data;
	struct queue*next;
}Queue;
typedef struct Node{
	Queue*rear;
	Queue*front;
}LinkQueue;
void InitQueue(LinkQueue*L);
void DestroyQueue(LinkQueue*L);
bool QueueEmpty(LinkQueue*L);
void InQueue(LinkQueue*L, ElemType e);
bool OutQueue(LinkQueue*L, ElemType *e);

int main(void)
{
	LinkQueue*SqQueue=(LinkQueue*)malloc(sizeof(LinkQueue));
	InitQueue(SqQueue);
	ElemType xin=520;
	if (QueueEmpty(SqQueue))
	printf("The Queue is empty.\n");
	else
	printf("The queue still has room.\n");
	InQueue(SqQueue,xin);
	DestroyQueue(SqQueue);
	return 0;
}

void InitQueue(LinkQueue*L){
	L->rear=L->front=NULL;
}
void DestroyQueue(LinkQueue*L)
{
	Queue*q=L->front,*p;
	if(q!=NULL)
	for(;q->next!=NULL;q=p)
	{
		p=q->next;
		free(q);	
	}
	free(L);
}
bool QueueEmpty(LinkQueue*L)
{
	return (L->rear==NULL&&L->front==NULL);
}
void InQueue(LinkQueue*L, ElemType e)
{
	Queue*p=(Queue*)malloc(sizeof(Queue));
	if (p==NULL)
	{
		printf("Apply for new room fail.\n");
		exit(0);
	}
	p->data=e;
	p->next=NULL;
	if(L->rear==NULL){
		L->rear=L->front=p;
	}
	else{
	L->rear->next=p;
	L->rear=p; 
	}
}
bool OutQueue(LinkQueue*L, ElemType *e)
{
	if (QueueEmpty(L))
	{
		printf("The Queue is empty.\n");
		return false;
	}
	Queue*p=L->front;
	*e=p->data;
	L->front=p->next;
	free(p);
	return true;
}

