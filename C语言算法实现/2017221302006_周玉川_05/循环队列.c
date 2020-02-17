//循环队列的基本操作
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXNUM 50

typedef int ElemType; 
typedef struct quene{
	ElemType data[MAXNUM];
	int front;
	int rear;
}Queue;

void InitQueue(Queue*L);
void DestroyQueue(Queue*L);
bool QueueEmpty(Queue*L);
bool QueueFull(Queue*L);
bool InQueue(Queue*L, ElemType e);
bool OutQueue(Queue*L, ElemType *e);

int main(void)
{
	Queue*SqQueue=(Queue*)malloc(sizeof(Queue));
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

void InitQueue(Queue*L){
	L->rear=-1;
	L->front=-1;
}
void DestroyQueue(Queue*L)
{
	free(L);
}
bool QueueEmpty(Queue*L)
{
	return (L->rear==L->front);
}
bool QueueFull(Queue*L){
	return ((L->rear+1)%MAXNUM==L->front);
}
bool InQueue(Queue*L, ElemType e)
{
	if (QueueFull(L))
	{
		printf("The Queue is full.\n");
		return false;
	}
	L->rear=(L->rear+1)%MAXNUM;
	L->data[L->rear]=e;
	return true;
}
bool OutQueue(Queue*L, ElemType *e)
{
	if (QueueEmpty(L))
	{
		printf("The Queue is empty.\n");
		return false;
	}
	L->front=(L->front+1)%MAXNUM;
	*e=L->data[L->front];
	return true;
}

