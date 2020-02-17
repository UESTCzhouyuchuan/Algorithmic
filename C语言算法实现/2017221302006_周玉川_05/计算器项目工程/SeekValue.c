#include <stdlib.h>
#include <stdio.h>
#include "SeekValue.h"
#include "main.h"
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
