#include<stdio.h>

void shijian(int x,int*hour,int*minute,int*second);

int main()
{
	int total,hour,minute,second;
	printf("Enter total seconds: \n");
	scanf("%d",&total);
	shijian(total,&hour,&minute,&second);
	printf("Time: \n%d:%d:%d",hour,minute,second);
	return 0;
}

void shijian(int x,int*hour,int*minute,int*second)
{
	*hour=x/3600%24;
	*minute=x/60%60;
	*second=x%60;
}
