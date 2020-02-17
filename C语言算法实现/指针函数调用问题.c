#include<stdio.h>
#include<limits.h>

void max_min(int a[],int*max,int*min)
{
	int i;
	*max=INT_MIN;
	 *min=INT_MAX;
	for(i=0;i<10;i++)
	{
		*max=*max > a[i] ? *max:a[i];
		*min=*min < a[i] ? *min:a[i];
	}
	return;
}

int main(void)
{
	int a[10];
	int i;
	int *max,*min;//需要给地址初始化 
	int m,n;
	//int m=a[0],n=a[0];
	//min=&a[0],max=&a[0];
	min=&m,max=&n;
	printf("Enter 10 numbers: \n");
	for(i=0;i< 10;i++)
	scanf(" %d",&a[i]);
	max_min(a,max,min);
	printf("Largest: %d\nSmallest: %d\n",*max,*min);
	return 0;
}
