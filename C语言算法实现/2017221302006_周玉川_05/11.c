//计算后缀表达式的值 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ElemType1 char
#define MAXNUM 50
#define ElemType double
typedef struct {
	ElemType1 data[MAXNUM];
	int top;
}StackL; 
typedef struct node{
	ElemType data[MAXNUM];
	int top;
}SqStack;
bool StackLEmpty(StackL*L){
	return (L->top==-1);
}
bool StackLFull(StackL*L){
	return (L->top==MAXNUM-1);
}
void InitStackL(StackL*L){
	L->top=-1;
}
void PopL(StackL*L, ElemType1*e){
	if(StackLEmpty(L))
	{
		printf("The StackL is empty.\n");
		return ;
	}
	*e=L->data[L->top--];
}
void PushL(StackL*L, ElemType1 e){
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
void GetTopL(StackL*L, ElemType1*e)
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
		while(*exp==' ')exp++;
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
double SeekValue(char*postexp);
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
	gets(exp);
	Trans(exp,postexp);
	printf("%g\n",SeekValue(postexp));
//	system("COLOR B");
//	system("pause");
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
double SeekValue(char*postexp)
{
 	double d,a,b,c,e;
	SqStack*Opnd=(SqStack*)malloc(sizeof(SqStack));		//定义操作栈 
	InitStack(Opnd);    //初始化操作栈 
	while (*postexp!='\0')	//postexp字符串扫描完后结束循环 
	{
		switch(*postexp)  
		{
			case '+':      //判定符号为+ 
				Pop(Opnd,&a);//出栈 
				Pop(Opnd, &b);//出栈
				c=a+b;
				Push(Opnd,c);//入栈
				break;
			 case '-':      //判定符号为-
				Pop(Opnd,&a);//出栈 
				Pop(Opnd, &b);//出栈
				c=b-a;
				Push(Opnd,c);//入栈
				break;
			case '*':      //判定符号为* 
				Pop(Opnd,&a);//出栈 
				Pop(Opnd, &b);//出栈
				c=a*b;
				Push(Opnd,c);
				break;
			case '/':      //判定符号为/
				Pop(Opnd,&a);//出栈 
				Pop(Opnd, &b);//出栈
				if(a==0)
				{
					printf("除零错误\n");
					exit(0);
				}
				else
				{
					c=b/a;
					Push(Opnd,c);//入栈
				}
				break;
			default:			//处理数字字符 
				d=0;			//将连续的数字字符转化为数字存放在d中
				while (*postexp >='0'&&*postexp<='9')
				{
					d=10*d+*postexp-'0';
					postexp++;
				} 
				Push(Opnd,d);
				break;
		}
		postexp++;
	} 
	GetTop(Opnd, &e);
	DestroyStack(Opnd);
	return e;
}
