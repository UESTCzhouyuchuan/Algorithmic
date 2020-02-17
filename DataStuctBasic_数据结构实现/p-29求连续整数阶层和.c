#include <stdio.h>
int f(int i,int n);
int main(void)
{
	printf("%d\n",f(1,5));
 } 
 
 int f(int i,int n)
 {
 	if (i>n)
 	return 1;
 	else
 	return (1+i*(f(i+1,n)));
 }
