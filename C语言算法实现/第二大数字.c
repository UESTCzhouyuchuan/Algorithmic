#include<stdio.h>

void max(int [],int*max,int*top);

int main(void)
{
	int n[10];
	int i,top=9,largest,secondlargest;
	printf("Enter 10 integers: \n");
	for(i=0;i<=top;i++)
	{
		scanf(" %d",&n[i]);
	}
	max(n,&largest,&top);
	printf("The largest: %d\n",largest);
	/*for(i=0;i<10;i++)
	{
		printf("n[%d]=%d\n",i,n[i]);
	}*/
	//max(n,&secondlargest,&top);
	//printf("Second Largest: %d\n",secondlargest);
	return 0; 
} 

void max(int n[],int*max,int*top)
{
	int i,j,tempt;
	for(i=0;i<=*top;i++)
	{
		if(n[i]>n[*top])
		{
			tempt=n[i];
			n[i]=n[*top];
			n[*top]=tempt;
		}
	}
	*max=n[*top];
	*top=*top-1;
}

