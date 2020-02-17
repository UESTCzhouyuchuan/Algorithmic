#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Trans.h"
#define ElemType char
#define MAXNUM 100
typedef struct {
	ElemType data[MAXNUM];
	int top;
}StackL; 
bool StackLEmpty(StackL*L){
	return (L->top==-1);
}
bool StackLFull(StackL*L){
	return (L->top==MAXNUM-1);
}
void InitStackL(StackL*L){
	L->top=-1;
}
void PopL(StackL*L, ElemType*e){
	if(StackLEmpty(L))
	{
		printf("The StackL is empty.\n");
		return ;
	}
	*e=L->data[L->top--];
}
void PushL(StackL*L, ElemType e){
	if (StackLFull(L))
	{
		printf("The StackL is full.\n");
		return ;
	}
	L->data[++L->top]=e;
}
void DestroyStackL(StackL*L){
	free(L);
}
void GetTopL(StackL*L, ElemType*e)
{
	if (StackLEmpty(L))
	{
		printf("The Stack is empty.\n");
		return ;
	}
	*e=L->data[L->top];
}

void Trans(char*exp, char postexp[])
{
	char e;
	StackL*Optr=(StackL*)malloc(sizeof(StackL));
	InitStackL(Optr);
	int i=0;
	while (*exp!='\0')
	{
		switch(*exp)
		{
			case '(':
				PushL(Optr,'(');
				exp++;
				break;
			case ')':
				PopL(Optr, &e);
				while (e!='(')
				{
					postexp[i++]=e;
					PopL(Optr,&e);
				}
				exp++;
				break;
			case '+':
			case '-':
				while(!StackLEmpty(Optr))
				{
					GetTopL(Optr, &e);
					if (e!='(')
					{
						postexp[i++]=e;
						PopL(Optr,&e);
					}
					else
					break;
				}
				PushL(Optr, *exp);
				exp++;
				break;
			case '*':
			case '/':
				while(!StackLEmpty(Optr))
				{
					GetTopL(Optr, &e);
					if (e=='*'||e=='/')
					{
						postexp[i++]=e;
						PopL(Optr,&e);
					}
					else
					break;
				}
				PushL(Optr, *exp);
				exp++;
				break;
			default:
				while (*exp>='0'&&*exp<='9')
				{
					postexp[i++]=*exp;
					exp++;
				}
				postexp[i++]='#';
		}
	}
	while(!StackLEmpty(Optr))
	{
		PopL(Optr, &e);
		postexp[i++]=e;
	}
	postexp[i]='\0';
	DestroyStackL(Optr);
}
