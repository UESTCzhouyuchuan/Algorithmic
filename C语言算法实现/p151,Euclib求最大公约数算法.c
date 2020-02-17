#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int commonnumber(int,int);
int main(void)
{
	int m,n;
	printf("Enter two integers: ");
	scanf("%d %d",&m,&n);
	printf("Greatest common divisor: %d",commonnumber(m,n));
	return 0;	
}
int commonnumber(int m,int n)
{
    int temp;//reserve the value of n
	for(;;){
	temp=n; 
	n=m%n;
	if(n==0)
	return temp;
	m=temp;
	}
}
