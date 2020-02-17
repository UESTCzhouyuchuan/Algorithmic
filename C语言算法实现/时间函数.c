#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void shijian(int x,int*hour,int*minute,int*second);

int main()
{
	int hour,minute,second;
	long int total;
	total=time(NULL)+8*3600-4;
	shijian(total,&hour,&minute,&second);
	printf("Time: \n%.2d:%.2d:%.2d",hour,minute,second);
	system("pause");
	return 0;
}

void shijian(int x,int*hour,int*minute,int*second)
{
	*hour=x/3600%24;
	*minute=x/60%60;
	*second=x%60;
}
