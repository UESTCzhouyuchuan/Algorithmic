#include<stdio.h>

int main(void)
{
	int n;
	int i,j,counter;
	float tempt;     //to memorize the first number of every row
	printf("Enter the type of the array: ");
	scanf(" %d",&n);
	printf("Import a array: ");
	float array[n][n];
	for(i=0;i <n;i++)
	{
		for(j=0 ;j< n;j++)
		{
			scanf(" %f",&array[i][j]);
		}
	}
	for(i =0;i< n;i++)
	{
         for(j=i+1;j<n;j++)
			for(counter=0;counter<n;counter++)
			{
				
			}
	} 
	for(i =0 ;i< n;i++)
	{
		for(j=0 ;j < n;j ++)
	    printf("%4g",array[i][j]);
	    printf("\n");
	}
	return 0;
}
