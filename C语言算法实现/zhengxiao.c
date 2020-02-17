#include<stdio.h>

void separate(float x,int*zheng,float*xiao)
{
	int i,j;
	i=(int)x;
	j=x-i;
	zheng=&i;
	xiao=&j;

}
int main(void)
{
	int *zheng;
	float n,*xiao;
	scanf("%f",&n);
	separate(n,zheng,xiao);
	printf("N=%g,Zheng=%d,Xiao=%g",n,*zheng,*xiao);
	return 0;
}
