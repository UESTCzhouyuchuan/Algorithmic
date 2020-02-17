#include<stdio.h>
#define MAX 100


int main(void)
{
	int Fibonacci[MAX]={0,1},*p = Fibonacci+1;
	int counter=0,N=15;
	//printf("How many numbers of Fibonacci do you want to see?");
	//scanf(" %d",&N);
	//printf("%-6d%-6d",laxi[0],laxi[1]);
	for(p=Fibonacci+ 2 ;p < Fibonacci+N;p++)
	{
		*p=*(p-1)+*(p-2);
		//printf("%-6d",*p);
	}
	for(p=Fibonacci;p<Fibonacci+N;p++)
	printf("%-6d",*p);
	printf("\n");
	return 0;
} 
