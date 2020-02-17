//计算后缀表达式的值 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXNUM 50
#define ElemType double
typedef struct node{
	ElemType data[MAXNUM];
	int top;
}SqStack;
void InitStack(SqStack*L);
void Pop(SqStack*L, ElemType*e);
void Push(SqStack*L, ElemType e);
void DestroyStack(SqStack*L);
void GetTop(SqStack*L, ElemType*e);
int main(void)
{
	char *postexp="12 3 +";//(char*)malloc(sizeof(char)*MAXNUM);
//	gets(postexp);
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
					c=a*b;
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
	printf("The result=%f\n",e);
	return 0;
}
void InitStack(SqStack*L){
	L->top=-1;
}
void Pop(SqStack*L, ElemType*e){
	*e=L->data[L->top--];
}
void Push(SqStack*L, ElemType e)
{
	L->data[++L->top]=e;
}
void DestroyStack(SqStack*L){
	free(L);
}
void GetTop(SqStack*L,ElemType*e)
{
	*e=L->data[L->top];
}
