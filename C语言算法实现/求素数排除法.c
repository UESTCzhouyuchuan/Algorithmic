//seek the prime between 1-n
#include<stdio.h>

int main(void)
{
	int n;
	int i,j;
	printf("Enter the top number: ");
	scanf("%d",&n);
	//int b[n]={};why is wrong,not be initialized?
	int b[n];
	for(i =0;i <n;i++)
	b[i]=0;
	for(i =2 ;i <n ;i++)
	{
		for(j =2;j*i <n;j++)
		b[j*i]=1;
	}
	for(i =2;i <n;i++)
	if(!b[i])
	printf("%d,",i);
	return 0;
	
}
