#include<stdio.h>
#include<math.h>
#include<stdbool.h>

bool prime(int n)
{
	int i,j;
	
	
	
	for(i=2;i<=sqrt((float)n);i++)
	{
	j=n%i;
	if(j==0)
	return false; 
	}
return true;
}
int main()
{
	int n;
	printf("Enter a number:");
	scanf("%d",&n);
	
	if(prime(n))
	printf("%d is prime.",n);
	else
	printf("%d is not prime.",n);
	
	
	return 0;
}


