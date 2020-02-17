#include<stdio.h>

int main(void){
	int i,sum=0;
	int n;
	printf("Enter a number: \n");
	scanf(" %d",&n);             //∂¡»°n 
	for(i=1;i<=n;i++)
	sum+=i;                     //1 to n sum up
	printf("sum=%d\n",sum); 
}
