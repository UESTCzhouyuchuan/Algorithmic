#include <stdlib.h>
#include <stdio.h>
#include "SeekValue.h"
#include "main.h"
double SeekValue(char*postexp)
{
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
				c=a*b;
				Push(Opnd,c);
				break;
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
					c=b/a;
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
	return e;
}
