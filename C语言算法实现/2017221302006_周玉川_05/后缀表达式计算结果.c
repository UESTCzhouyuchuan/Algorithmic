//�����׺���ʽ��ֵ 
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
	SqStack*Opnd=(SqStack*)malloc(sizeof(SqStack));		//�������ջ 
	InitStack(Opnd);    //��ʼ������ջ 
	while (*postexp!='\0')	//postexp�ַ���ɨ��������ѭ�� 
	{
		switch(*postexp)  
		{
			case '+':      //�ж�����Ϊ+ 
				Pop(Opnd,&a);//��ջ 
				Pop(Opnd, &b);//��ջ
				c=a+b;
				Push(Opnd,c);//��ջ
				break;
			 case '-':      //�ж�����Ϊ-
				Pop(Opnd,&a);//��ջ 
				Pop(Opnd, &b);//��ջ
				c=b-a;
				Push(Opnd,c);//��ջ
				break;
			case '*':      //�ж�����Ϊ* 
				Pop(Opnd,&a);//��ջ 
				Pop(Opnd, &b);//��ջ
				
			case '/':      //�ж�����Ϊ/
				Pop(Opnd,&a);//��ջ 
				Pop(Opnd, &b);//��ջ
				if(a==0)
				{
					printf("�������\n");
					exit(0);
				}
				else
				{
					c=a*b;
					Push(Opnd,c);//��ջ
				}
				break;
			default:			//���������ַ� 
				d=0;			//�������������ַ�ת��Ϊ���ִ����d��
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
