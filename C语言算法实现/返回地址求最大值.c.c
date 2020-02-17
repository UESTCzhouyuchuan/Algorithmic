#include<stdio.h>
#define MAX 10
int* rezhi_max(int [],int);
int main(void)
{
	int a[MAX];
	int i;
	printf("Enter %d integers: \n",MAX);
	for(i=0;i < MAX;i++)
	scanf(" %d",&a[i]);
	printf("The largest: %d\n",*rezhi_max(a,MAX));
	return 0;
} 

int* rezhi_max(int n[],int m)
{
	int *re=&n[0];
	int i;
	for(i =0;i< m;i++)
	if(n[i] >*re)
	re=&n[i];
	return re;
}