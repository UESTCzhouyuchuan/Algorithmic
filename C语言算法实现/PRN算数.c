#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define STACK_SIZE 20

int top=0;
char sh[STACK_SIZE]; 
void stack_overflow(void);
void stack_underflow(void);
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char);
char pop(void);

int main(void)
{
	char ch;
	printf("Enter an RPN expression: ");
	while((ch=getchar())==' '); 
	for(;ch!='\n';)
	{
		switch(ch){
			case '-':
			sh[top-2]=sh[top-2]-sh[top-1];
			top--;break;
			case '+':
			sh[top-2]=sh[top-2]+sh[top-1];
			top--;break;
			case'*':
			sh[top-2]=sh[top-2]*sh[top-1];
			top--;
			break;
			case'/':
			sh[top-2]=sh[top-2]/sh[top-1];
			top--;break;
			case'=':
			top--;break;
			case' ':break;
			default:
			push(ch%('0'));break;	
		}
		while((ch=getchar())==' ');
	}
	if(is_empty())
		stack_underflow();
	printf("\nResult: %d",sh[0]);
	return 0;
}

void make_empty(void)
{
	top=0;
}
bool is_empty(void)
{
	return top > 0;
}
bool is_full(void)
{
	return top== STACK_SIZE;
}
void push(char i)
{
	if(is_full())
	stack_overflow();
	else
	sh[top++] = i;
}
char pop(void)
{
	if(is_empty())
	stack_underflow();
	else
	return sh[--top];
}
void stack_overflow(void)
{
	printf("Expression is too complex.");
	exit(EXIT_FAILURE);
	
}
void stack_underflow(void)
{
	printf("Not enough operands in ewpression.");
	exit(EXIT_FAILURE);
}
