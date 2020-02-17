#include<stdio.h>

int main()
{
	int i,j,a,t[5],e=0;
	printf("Enter a number: \n");
	scanf("%d",&a);
	for(i=1;i<=5;i++)
	{
		t[i]=a%10;
		a/=10;
		e++;
	}
	for(i=1;i<=e;i++)
	{
		for(j=e;j>i;j--)
		
		{
			if(t[i]==t[j])
			{
			printf("Have the same number ");
			return 0;
			}
			 
			
		}
	}
	printf("Every number is different");
	return 0;

	
}


