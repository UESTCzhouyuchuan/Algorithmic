#include<stdio.h>
#include<stdbool.h>

bool belongregion(int,int,int);

int main(void)
{
	int x,y,n;
	printf("Enter x,y,n: ");
	scanf("%d %d %d",&x,&y,&n);
	if(belongregion(x,y,n))
	printf("\n%d,%d belong to 0- %d.",x,y,n-1);
	else 
	printf("\n%d,%d don't belong to 0- %d.",x,y,n-1);
}
bool belongregion(int number1,int number2,int region)
{
	if(number1>0&&number2>0&&number1<region&&number2<region)//two numbers belong to the region 
	return true;
	else
	return false;
} 