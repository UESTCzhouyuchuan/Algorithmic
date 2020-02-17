#include<stdio.h>

int main()
{
	float number[100]={},middle=0;
	int i,j,t;
	char ch;
	printf("Please enter a series of numbers: ");
	for(i=0;;i++)
	{
		scanf("%f",&number[i]);
		if((ch=getchar())=='\n')
		break;
	}
	for(t=0;t<i;t++)
	{
		j=i; 
		for(j=i;j>t;j--)
		{
			if(number[j]<number[t])
			{
				middle=number[j];//交换两者的值 
				number[j]=number[t];
				number[t]=middle;
			}
		}
	}
	printf("Numbers after being ordered: ");
	for(j=0;j<i;j++)
	{
		printf("%g,",number[j]);
	}
	printf("%g",number[i]);
	return 0;
} 

