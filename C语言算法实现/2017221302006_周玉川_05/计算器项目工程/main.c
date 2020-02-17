//计算后缀表达式的值 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "SeekValue.h"
#include "main.h"
#include "Trans.h"
bool StackEmpty(SqStack*L);
bool StackFull(SqStack*L);
void InitStack(SqStack*L);
void Pop(SqStack*L, ElemType*e);
void Push(SqStack*L, ElemType e);
void DestroyStack(SqStack*L);
void GetTop(SqStack*L, ElemType*e);
int main(void)
{
	char postexp[MAXNUM];
	char exp[MAXNUM];
	printf("Enter the expression: ");
	gets(exp);
	printf("\n");
	Trans(exp,postexp);
	printf("The result=%f\n",SeekValue(postexp));
	system("COLOR B");
	system("pause");
	return 0;
}
bool StackEmpty(SqStack*L)
{
	return (L->top==-1);
}
bool StackFull(SqStack*L)
{
	return (L->top==(MAXNUM-1));
}
void InitStack(SqStack*L){
	L->top=-1;
}
void Pop(SqStack*L, ElemType*e){
	if(StackEmpty(L))
	{
		printf("The Stack is empty.\n");
		return ;
	}
	*e=L->data[L->top--];
}
void Push(SqStack*L, ElemType e)
{
	if(StackFull(L))
	{
		printf("The Stack is full.\n");
		return ;
	}
	L->data[++L->top]=e;
}
void DestroyStack(SqStack*L){
	free(L);
}
void GetTop(SqStack*L,ElemType*e)
{
	*e=L->data[L->top];
}
