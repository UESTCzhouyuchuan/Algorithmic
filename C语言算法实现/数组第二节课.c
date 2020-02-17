#include<stdio.h>
#define N 100

int main(void)
{
	int a[N]={},i,sum =0,*p=a;
	for(i =0; i< N;i++)
	sum += p[i];          //p[i]即*(p+i), 
	printf("Sum: %d",sum);
	return 0;
}

void duoweishuzu(void)
{
	
}

//当数组名被传递给函数时，总是被视为指针

//int *a;*a=0 wrong
//&a[0][0]等价于a[0] &a[3][0]等价于a[3]
//&m[i][0]等同于&*((m[i]+0)) m[i]