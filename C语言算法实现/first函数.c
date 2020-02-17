#include<stdio.h>
#include<stdlib.h>

int plus(int a,int b)
{
	return a+b;
}
int main(void)
{
	int x,y;
	printf("Enter three numbers:");
	scanf_s("%d %d",&x,&y);
	printf("%d plus %d equal %d",x,y,plus(x,y));
	system("pause");
	return 0;
	
}
	
