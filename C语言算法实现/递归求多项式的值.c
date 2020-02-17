#include<stdio.h>

int fact(int,int);
int main(void)
{
	int x;
	printf("Enter a x: ");
	scanf("%d",&x);
	printf("%d",3*fact(x,5)+2*fact(x,4)-5*fact(x,3)-fact(x,2)+7*x-6);
	
	return 0;
}

int fact(int x,int n)
{
	if(n<=0)
	return 1;
	else 
	return x*fact(x,n-1);
}