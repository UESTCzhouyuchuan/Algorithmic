#include<stdio.h>
#include<limits.h>
#define MAX 10
void max_min(int a[],int n,int*max,int*min)
{
	int i;
	*max=INT_MIN;
	 *min=INT_MAX;
	for(i=0;i<n;i++)
	{
		*max=*max > a[i]? *max:a[i];
		*min=*min < a[i]? *min:a[i];
	}
	return;
}

int main(void)
{
	int a[10];
	int i;
	int max,min;
	printf("Enter %d numbers: \n",MAX);
	for(i=0;i< MAX;i++)
	scanf("%d",&a[i]);
	max_min(a,MAX,&max,&min);
	printf("Largest: %d\nSmallest: %d\n",max,min);
	return 0;
}

