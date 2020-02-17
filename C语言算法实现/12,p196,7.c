#include<stdio.h>
#include<stdbool.h>
#define N 5
bool search(int a[],int key);

int main(void)
{
	int import[N],*p;
	int key=0;
	printf("Enter 5 integers: \n");
	for(p = import;p < import+N;p ++)
	scanf(" %d",p);
	printf("Enter a key: \n");
	scanf(" %d",&key);
	if(search(import,key))
	printf("The result: 1");
	else
	printf("The result: 0"); 
	return 0;
	
}

bool search(int a[], int key)
{
	int *p;
	for(p = a;p<a+N;p++)
	{
		if(*p==key)
		return true;
	}
	return false;
	
}
